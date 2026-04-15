/* =========================
   Full C Compiler Project
   Parser (parser.y)
   ========================= */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void yyerror(const char *s);
int yylex();
extern FILE *yyin;
extern int yylineno;

FILE *output_file;

// Stack-based statement buffering for control flow
#define MAX_BUFFER_DEPTH 10
typedef struct {
    char buffer[50000];
    int pos;
} StatementBuffer;

StatementBuffer buffer_stack[MAX_BUFFER_DEPTH];
int buffer_depth = 0;  // 0 = no buffering, 1+ = buffering level
char temp_else_body[100000];  // Temporary storage for else body

void push_buffer() {
    if (buffer_depth < MAX_BUFFER_DEPTH - 1) {
        buffer_stack[buffer_depth].pos = 0;
        memset(buffer_stack[buffer_depth].buffer, 0, 50000);
        buffer_depth++;
    }
}

char* pop_buffer() {
    if (buffer_depth > 0) {
        buffer_depth--;
        return buffer_stack[buffer_depth].buffer;
    }
    return "";
}

void buffer_statement(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    if (buffer_depth > 0) {
        buffer_stack[buffer_depth - 1].pos += vsprintf(buffer_stack[buffer_depth - 1].buffer + buffer_stack[buffer_depth - 1].pos, fmt, args);
    } else {
        vfprintf(output_file, fmt, args);
    }
    va_end(args);
}

char* get_current_buffer() {
    if (buffer_depth > 0) {
        return buffer_stack[buffer_depth - 1].buffer;
    }
    return "";
}

// Track variable types
typedef struct {
    char name[50];
    char type[20];  // "int", "float", "string"
} VarType;

VarType vars[100];
int var_count = 0;

void add_var_type(const char *name, const char *type) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(vars[i].name, name) == 0) {
            strcpy(vars[i].type, type);
            return;
        }
    }
    strcpy(vars[var_count].name, name);
    strcpy(vars[var_count].type, type);
    var_count++;
}

char* get_var_type(const char *name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(vars[i].name, name) == 0) {
            return vars[i].type;
        }
    }
    return "int";
}

int in_function = 0;
int depth = 0;

%}

%union {
    char *str;
    int num;
}

%token INT FLOAT CHAR STRING RETURN IF ELSE FOR PRINTF VOID
%token <str> NUMBER FLOAT_NUM ID STRING_LIT CHAR_LIT
%token PLUS MINUS MUL DIV MOD ASSIGN SEMICOLON COMMA QUOTE
%token LPAREN RPAREN LBRACE RBRACE
%token LT GT LE GE EQ NE NOT AND OR INC DEC

%type <str> expr printf_args block statement

%left OR
%left AND
%left EQ NE LT GT LE GE
%left PLUS MINUS
%left MUL DIV MOD
%right NOT

%%

program:
    function
    ;

function:
    INT ID LPAREN RPAREN LBRACE {
        fprintf(output_file, "#include <stdio.h>\nint main() {\n");
    } block RBRACE {
        fprintf(output_file, "    return 0;\n}\n");
    }
    ;

block:
    {
        push_buffer();
    } statements {
        char *buffered = pop_buffer();
        fprintf(output_file, "%s", buffered);
        $$ = "";
    }
    ;

statements:
    statement
    | statements statement
    ;

statement:
    INT ID SEMICOLON {
        buffer_statement("    int %s = 0;\n", $2);
        add_var_type($2, "int");
    }
    | INT ID ASSIGN expr SEMICOLON {
        buffer_statement("    int %s = %s;\n", $2, $4);
        add_var_type($2, "int");
    }
    | FLOAT ID SEMICOLON {
        buffer_statement("    float %s = 0.0;\n", $2);
        add_var_type($2, "float");
    }
    | FLOAT ID ASSIGN expr SEMICOLON {
        buffer_statement("    float %s = %s;\n", $2, $4);
        add_var_type($2, "float");
    }
    | CHAR ID SEMICOLON {
        buffer_statement("    char %s = '\\0';\n", $2);
        add_var_type($2, "char");
    }
    | CHAR ID ASSIGN CHAR_LIT SEMICOLON {
        buffer_statement("    char %s = %s;\n", $2, $4);
        add_var_type($2, "char");
    }
    | STRING ID SEMICOLON {
        buffer_statement("    char *%s = \"\";\n", $2);
        add_var_type($2, "string");
    }
    | STRING ID ASSIGN STRING_LIT SEMICOLON {
        buffer_statement("    char *%s = %s;\n", $2, $4);
        add_var_type($2, "string");
    }
    | ID ASSIGN expr SEMICOLON {
        buffer_statement("    %s = %s;\n", $1, $3);
    }
    | ID INC SEMICOLON {
        buffer_statement("    %s++;\n", $1);
    }
    | ID DEC SEMICOLON {
        buffer_statement("    %s--;\n", $1);
    }
    | PRINTF LPAREN expr RPAREN SEMICOLON {
        char *val = $3;
        char *type = get_var_type(val);
        if (val[0] == '"') {
            buffer_statement("    printf(%s);\n", val);
        } else if (strchr(val, '.') != NULL) {
            buffer_statement("    printf(\"%%f\\n\", %s);\n", val);
        } else {
            if (strcmp(type, "float") == 0) {
                buffer_statement("    printf(\"%%f\\n\", %s);\n", val);
            } else if (strcmp(type, "string") == 0) {
                buffer_statement("    printf(\"%%s\\n\", %s);\n", val);
            } else if (strcmp(type, "char") == 0) {
                buffer_statement("    printf(\"%%c\\n\", %s);\n", val);
            } else {
                buffer_statement("    printf(\"%%d\\n\", %s);\n", val);
            }
        }
    }
    | PRINTF LPAREN expr COMMA expr RPAREN SEMICOLON {
        char *first = $3;
        char *second = $5;
        char *type_first = get_var_type(first);
        char *type_second = get_var_type(second);
        
        // Check if first is a string literal
        int first_is_string = (first[0] == '"');
        int second_is_string = (second[0] == '"');
        
        if (first_is_string && !second_is_string) {
            // printf("label:", variable)
            char *type = get_var_type(second);
            if (strchr(second, '.') != NULL) {
                buffer_statement("    printf(\"%%s%%f\", %s, %s);\n", first, second);
            } else if (strcmp(type, "float") == 0) {
                buffer_statement("    printf(\"%%s%%f\", %s, %s);\n", first, second);
            } else if (strcmp(type, "string") == 0) {
                buffer_statement("    printf(\"%%s%%s\", %s, %s);\n", first, second);
            } else if (strcmp(type, "char") == 0) {
                buffer_statement("    printf(\"%%s%%c\", %s, %s);\n", first, second);
            } else {
                buffer_statement("    printf(\"%%s%%d\", %s, %s);\n", first, second);
            }
        } else if (!first_is_string && second_is_string) {
            // printf(variable, "label:")
            char *type = get_var_type(first);
            if (strchr(first, '.') != NULL) {
                buffer_statement("    printf(\"%%f%%s\", %s, %s);\n", first, second);
            } else if (strcmp(type, "float") == 0) {
                buffer_statement("    printf(\"%%f%%s\", %s, %s);\n", first, second);
            } else if (strcmp(type, "string") == 0) {
                buffer_statement("    printf(\"%%s%%s\", %s, %s);\n", first, second);
            } else if (strcmp(type, "char") == 0) {
                buffer_statement("    printf(\"%%c%%s\", %s, %s);\n", first, second);
            } else {
                buffer_statement("    printf(\"%%d%%s\", %s, %s);\n", first, second);
            }
        } else if (second_is_string) {
            // Both strings
            buffer_statement("    printf(\"%%s%%s\", %s, %s);\n", first, second);
        } else {
            // Both variables
            char *type_first_actual = get_var_type(first);
            char *type_second_actual = get_var_type(second);
            if (strcmp(type_first_actual, "float") == 0 && strcmp(type_second_actual, "float") == 0) {
                buffer_statement("    printf(\"%%f%%f\", %s, %s);\n", first, second);
            } else if (strcmp(type_first_actual, "string") == 0 || strcmp(type_second_actual, "string") == 0) {
                buffer_statement("    printf(\"%%s%%s\", %s, %s);\n", first, second);
            } else {
                buffer_statement("    printf(\"%%d%%d\", %s, %s);\n", first, second);
            }
        }
    }
    | PRINTF LPAREN printf_args RPAREN SEMICOLON {
        buffer_statement("%s", $3);
    }
    | RETURN expr SEMICOLON {
        buffer_statement("    return %s;\n", $2);
    }
    | RETURN SEMICOLON {
        buffer_statement("    return 0;\n");
    }
    | IF LPAREN expr RPAREN LBRACE {push_buffer();} statements RBRACE else_part {
        char *if_body = pop_buffer();
        buffer_statement("    if (%s) {\n%s    }\n", $3, if_body);
        if (strlen(temp_else_body) > 0) {
            buffer_statement("%s", temp_else_body);
            temp_else_body[0] = '\0';
        }
    }
    | FOR LPAREN ID ASSIGN expr SEMICOLON expr SEMICOLON ID INC RPAREN LBRACE {push_buffer();} statements RBRACE {
        char *loop_body = pop_buffer();
        buffer_statement("    for (%s = %s; %s; %s++) {\n%s    }\n", $3, $5, $7, $9, loop_body);
    }
    ;

else_part:
    /* empty */
    | ELSE LBRACE {push_buffer();} statements RBRACE {
        char *else_body = pop_buffer();
        sprintf(temp_else_body, "    else {\n%s    }\n", else_body);
    }
    | ELSE IF LPAREN expr RPAREN LBRACE {push_buffer();} statements RBRACE else_part {
        char *elseif_body = pop_buffer();
        char temp[100000];
        sprintf(temp, "    else if (%s) {\n%s    }\n%s", $4, elseif_body, temp_else_body);
        strcpy(temp_else_body, temp);
    }
    ;

expr:
    expr PLUS expr {
        char *result = malloc(100);
        sprintf(result, "(%s + %s)", $1, $3);
        $$ = result;
    }
    | expr MINUS expr {
        char *result = malloc(100);
        sprintf(result, "(%s - %s)", $1, $3);
        $$ = result;
    }
    | expr MUL expr {
        char *result = malloc(100);
        sprintf(result, "(%s * %s)", $1, $3);
        $$ = result;
    }
    | expr DIV expr {
        char *result = malloc(100);
        sprintf(result, "(%s / %s)", $1, $3);
        $$ = result;
    }
    | expr MOD expr {
        char *result = malloc(100);
        sprintf(result, "(%s %% %s)", $1, $3);
        $$ = result;
    }
    | expr LT expr {
        char *result = malloc(100);
        sprintf(result, "(%s < %s)", $1, $3);
        $$ = result;
    }
    | expr GT expr {
        char *result = malloc(100);
        sprintf(result, "(%s > %s)", $1, $3);
        $$ = result;
    }
    | expr LE expr {
        char *result = malloc(100);
        sprintf(result, "(%s <= %s)", $1, $3);
        $$ = result;
    }
    | expr GE expr {
        char *result = malloc(100);
        sprintf(result, "(%s >= %s)", $1, $3);
        $$ = result;
    }
    | expr EQ expr {
        char *result = malloc(100);
        sprintf(result, "(%s == %s)", $1, $3);
        $$ = result;
    }
    | expr NE expr {
        char *result = malloc(100);
        sprintf(result, "(%s != %s)", $1, $3);
        $$ = result;
    }
    | expr AND expr {
        char *result = malloc(100);
        sprintf(result, "(%s && %s)", $1, $3);
        $$ = result;
    }
    | expr OR expr {
        char *result = malloc(100);
        sprintf(result, "(%s || %s)", $1, $3);
        $$ = result;
    }
    | NOT expr {
        char *result = malloc(100);
        sprintf(result, "(!%s)", $2);
        $$ = result;
    }
    | LPAREN expr RPAREN {
        $$ = $2;
    }
    | NUMBER {
        $$ = $1;
    }
    | FLOAT_NUM {
        $$ = $1;
    }
    | STRING_LIT {
        $$ = $1;
    }
    | CHAR_LIT {
        $$ = $1;
    }
    | ID {
        $$ = $1;
    }
    | ID INC {
        char *result = malloc(100);
        sprintf(result, "(%s++)", $1);
        $$ = result;
    }
    | ID DEC {
        char *result = malloc(100);
        sprintf(result, "(%s--)", $1);
        $$ = result;
    }
    ;

printf_args:
    expr COMMA expr {
        char *result = malloc(2000);
        char *fmt = malloc(500);
        char *args = malloc(500);
        
        fmt[0] = '\0';
        args[0] = '\0';
        
        // First argument
        char *val1 = $1;
        char *type1 = get_var_type(val1);
        
        if (val1[0] == '"') {
            strcat(fmt, "%s");
            strcat(args, val1);
        } else if (strchr(val1, '.') != NULL || strcmp(type1, "float") == 0) {
            strcat(fmt, "%f");
            strcat(args, val1);
        } else if (strcmp(type1, "string") == 0) {
            strcat(fmt, "%s");
            strcat(args, val1);
        } else {
            strcat(fmt, "%d");
            strcat(args, val1);
        }
        
        // Second argument
        char *val2 = $3;
        char *type2 = get_var_type(val2);
        
        if (val2[0] == '"') {
            strcat(fmt, "%s");
            strcat(args, ",");
            strcat(args, val2);
        } else if (strchr(val2, '.') != NULL || strcmp(type2, "float") == 0) {
            strcat(fmt, "%f");
            strcat(args, ",");
            strcat(args, val2);
        } else if (strcmp(type2, "string") == 0) {
            strcat(fmt, "%s");
            strcat(args, ",");
            strcat(args, val2);
        } else {
            strcat(fmt, "%d");
            strcat(args, ",");
            strcat(args, val2);
        }
        
        sprintf(result, "    printf(\"%s\", %s);\n", fmt, args);
        free(fmt);
        free(args);
        $$ = result;
    }
    | printf_args COMMA expr {
        char *result = malloc(2000);
        char *prev = $1;
        char *val = $3;
        char *type = get_var_type(val);
        
        // Extract format and args from previous
        char fmt[500];
        char args[500];
        sscanf(prev, "    printf(\"%[^\"]\", %[^)]", fmt, args);
        
        if (val[0] == '"') {
            strcat(fmt, "%s");
        } else if (strchr(val, '.') != NULL || strcmp(type, "float") == 0) {
            strcat(fmt, "%f");
        } else if (strcmp(type, "string") == 0) {
            strcat(fmt, "%s");
        } else {
            strcat(fmt, "%d");
        }
        
        strcat(args, ",");
        strcat(args, val);
        
        sprintf(result, "    printf(\"%s\", %s);\n", fmt, args);
        free(prev);
        $$ = result;
    }
    ;

%%

void yyerror(const char *s) {
    printf("Error on line %d: %s\n", yylineno, s);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file.c>\n", argv[0]);
        printf("\nExample: %s sample1.c\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (!input) {
        printf("Error: Cannot open file '%s'\n", argv[1]);
        return 1;
    }

    output_file = fopen("generated.c", "w");
    if (!output_file) {
        printf("Error: Cannot create output file\n");
        fclose(input);
        return 1;
    }

    yyin = input;
    
    int parse_result = yyparse();
    
    fclose(input);
    fclose(output_file);

    if (parse_result != 0) {
        fprintf(stderr, "Parse error in '%s'\n", argv[1]);
        return 1;
    }

    char outfile[50];
    static int counter = 0;
    sprintf(outfile, "out_%d.exe", counter++);
    
    char cmd[200];
    sprintf(cmd, "gcc generated.c -o %s 2>nul", outfile);
    int compile_result = system(cmd);
    
    if (compile_result != 0) {
        fprintf(stderr, "Compilation error\n");
        return 1;
    }
    
    system(outfile);

    return 0;
}
