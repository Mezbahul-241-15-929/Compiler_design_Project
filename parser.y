/* =========================
   Full C Compiler Project
   Parser (parser.y)
   ========================= */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex();
extern FILE *yyin;
extern int yylineno;

FILE *output_file;

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

%token INT FLOAT CHAR RETURN IF ELSE WHILE PRINTF VOID
%token <str> NUMBER FLOAT_NUM ID STRING CHAR_LIT
%token PLUS MINUS MUL DIV ASSIGN SEMICOLON COMMA QUOTE
%token LPAREN RPAREN LBRACE RBRACE
%token LT GT LE GE EQ NE NOT AND OR INC DEC

%type <str> expr

%left OR
%left AND
%left EQ NE LT GT LE GE
%left PLUS MINUS
%left MUL DIV
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
    statements
    ;

statements:
    statement
    | statements statement
    ;

statement:
    INT ID SEMICOLON {
        fprintf(output_file, "    int %s = 0;\n", $2);
        add_var_type($2, "int");
    }
    | INT ID ASSIGN expr SEMICOLON {
        fprintf(output_file, "    int %s = %s;\n", $2, $4);
        add_var_type($2, "int");
    }
    | FLOAT ID SEMICOLON {
        fprintf(output_file, "    float %s = 0.0;\n", $2);
        add_var_type($2, "float");
    }
    | FLOAT ID ASSIGN expr SEMICOLON {
        fprintf(output_file, "    float %s = %s;\n", $2, $4);
        add_var_type($2, "float");
    }
    | CHAR ID SEMICOLON {
        fprintf(output_file, "    char %s = '\\0';\n", $2);
        add_var_type($2, "char");
    }
    | CHAR LPAREN RPAREN ID SEMICOLON {
        fprintf(output_file, "    char *%s = \"\";\n", $4);
        add_var_type($4, "string");
    }
    | CHAR LPAREN RPAREN ID ASSIGN STRING SEMICOLON {
        fprintf(output_file, "    char *%s = %s;\n", $4, $6);
        add_var_type($4, "string");
    }
    | ID ASSIGN expr SEMICOLON {
        fprintf(output_file, "    %s = %s;\n", $1, $3);
    }
    | ID INC SEMICOLON {
        fprintf(output_file, "    %s++;\n", $1);
    }
    | ID DEC SEMICOLON {
        fprintf(output_file, "    %s--;\n", $1);
    }
    | PRINTF LPAREN expr RPAREN SEMICOLON {
        char *expr_val = $3;
        if (expr_val[0] == '"') {
            fprintf(output_file, "    printf(\"%%s\\n\", %s);\n", expr_val);
        } else if (strchr(expr_val, '.') != NULL) {
            fprintf(output_file, "    printf(\"%%f\\n\", %s);\n", expr_val);
        } else {
            char *type = get_var_type(expr_val);
            if (strcmp(type, "float") == 0) {
                fprintf(output_file, "    printf(\"%%f\\n\", %s);\n", expr_val);
            } else if (strcmp(type, "string") == 0) {
                fprintf(output_file, "    printf(\"%%s\\n\", %s);\n", expr_val);
            } else {
                fprintf(output_file, "    printf(\"%%d\\n\", %s);\n", expr_val);
            }
        }
    }
    | PRINTF LPAREN STRING RPAREN SEMICOLON {
        fprintf(output_file, "    printf(%s);\n", $3);
    }
    | PRINTF LPAREN STRING COMMA expr RPAREN SEMICOLON {
        char *fmt = $3;
        char *val = $5;
        char *type = get_var_type(val);
        
        // Remove quotes from format string
        char fmt_clean[200];
        strncpy(fmt_clean, fmt + 1, strlen(fmt) - 2);
        fmt_clean[strlen(fmt) - 2] = '\0';
        
        // Check if format string has format specifier
        if (strchr(fmt_clean, '%') == NULL) {
            // No format specifier, add one based on type
            char new_fmt[200];
            if (strcmp(type, "float") == 0) {
                sprintf(new_fmt, "\"%s %%f\"", fmt_clean);
            } else if (strcmp(type, "string") == 0) {
                sprintf(new_fmt, "\"%s %%s\"", fmt_clean);
            } else {
                sprintf(new_fmt, "\"%s %%d\"", fmt_clean);
            }
            fprintf(output_file, "    printf(%s, %s);\n", new_fmt, val);
        } else {
            fprintf(output_file, "    printf(%s, %s);\n", fmt, val);
        }
    }
    | RETURN expr SEMICOLON {
        fprintf(output_file, "    return %s;\n", $2);
    }
    | RETURN SEMICOLON {
        fprintf(output_file, "    return 0;\n");
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
    | STRING {
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
