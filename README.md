# Problem 8: Full C Compiler with Flex & Bison

## ⚡ QUICK COMMANDS

### Compile (ONE TIME)
```powershell
flex lexer.l ; bison -d parser.y ; gcc lex.yy.c parser.tab.c -o compiler.exe
```

### Example Program
```c
int main() {
    int x = 3;
    printf("Output:", x);
    return 0;
}
```

### Run
```powershell
.\compiler.exe test.c
```
**Output:** `Output: 3`

---

## 📝 PRINTF FORMATS (NEW!)

### Format 1: Simple String
```c
printf("Hello");
```
**Output:** `Hello`

### Format 2: With Integer
```c
int x = 5;
printf("Value:", x);
```
**Output:** `Value: 5`

### Format 3: With Float
```c
float pi = 3.14;
printf("Pi:", pi);
```
**Output:** `Pi: 3.140000`

### Format 4: With String
```c
char() name = "Bob";
printf("Name:", name);
```
**Output:** `Name: Bob`

## 📋 Overview

A **Full C Compiler** that:
- ✅ Reads C source code from a file
- ✅ Parses it with lexer & parser
- ✅ Generates optimized C code
- ✅ Compiles to machine code
- ✅ Executes automatically
- ✅ Shows real program output

Supports:
- Variable declarations & assignments
- Arithmetic expressions
- Comparison operators
- Logical operators
- If-Else statements
- While loops
- Return statements
- Increment/Decrement operators

---

## 🎯 Features

✅ **Keywords:** `int`, `return`, `if`, `else`, `while`  
✅ **Operators:** `+`, `-`, `*`, `/`, `=`  
✅ **Delimiters:** `(`, `)`, `{`, `}`, `;`  
✅ **Identifiers:** Variable names  
✅ **Numbers:** Integer literals  

---

## 📁 Files

| File | Purpose |
|------|---------|
| `lexer.l` | Flex lexer - tokenizes input |
| `parser.y` | Bison parser - parses syntax |
| `compile.bat` | Windows batch script to compile |
| `compile.ps1` | PowerShell script to compile |
| `README.md` | This file |

---

## 🔧 Compilation Methods

### **Method 1: Using Batch File (Windows)**

```batch
compile.bat
```

### **Method 2: Using PowerShell**

```powershell
.\compile.ps1
```

### **Method 3: Manual Compilation**

```powershell
# Step 1: Generate lexer
flex lexer.l

# Step 2: Generate parser
bison -d parser.y

# Step 3: Compile
gcc lex.yy.c parser.tab.c -o mini_compiler.exe

# Step 4: Run
.\mini_compiler.exe
```

---

## 📝 Example Input

```c
int a;
a = 5;

if (a) {
   a = a + 1;
}

while (a) {
   a = a - 1;
}

return
```

### **Expected Output**

```
=== Mini C Compiler ===
Enter Mini C Code:
Declare variable
Assignment done
If statement
Assignment don
While loop
Assignment done
Return statement
```

---

## 🚀 Usage Examples

### **Example 1: Simple Declaration and Assignment**
```c
int x;
x = 10;
```
**Output:** 
```
Declare variable
Assignment done
```

### **Example 2: Arithmetic Expression**
```c
int result;
result = 5 + 3 * 2;
```
**Output:**
```
Declare variable
Assignment done
```

### **Example 3: If-Else Statement**
```c
int x;
x = 5;

if (x) {
   x = 10;
} else {
   x = 0;
}
```
**Output:**
```
Declare variable
Assignment done
If-Else statement
Assignment done
```

### **Example 4: While Loop**
```c
int i;
i = 3;

while (i) {
   i = i - 1;
}
```
**Output:**
```
Declare variable
Assignment done
While loop
Assignment done
```

---

## ⚙️ Requirements

You must have installed:
- **Flex** - Lexical analyzer generator
- **Bison** - Parser generator  
- **GCC** - C Compiler

### **Installation (Windows)**

#### Using Chocolatey (Recommended)
```powershell
choco install winflexbison mingw -y
```

#### Using MSYS2
1. Download from: https://www.msys2.org/
2. Install and run MSYS2 terminal:
```bash
pacman -S flex bison mingw-w64-x86_64-gcc
```

---

## 📊 Lexer Tokens

| Token | Pattern | Example |
|-------|---------|---------|
| `INT` | "int" | `int x;` |
| `RETURN` | "return" | `return 0;` |
| `IF` | "if" | `if (x)` |
| `ELSE` | "else" | `else { }` |
| `WHILE` | "while" | `while (x)` |
| `NUMBER` | `[0-9]+` | `5`, `123` |
| `ID` | `[a-zA-Z_][a-zA-Z0-9_]*` | `x`, `count`, `_var` |
| `PLUS` | "+" | `a + b` |
| `MINUS` | "-" | `a - b` |
| `MUL` | "*" | `a * b` |
| `DIV` | "/" | `a / b` |
| `ASSIGN` | "=" | `x = 5` |
| `LPAREN` | "(" | `(x)` |
| `RPAREN` | ")" | `(x)` |
| `LBRACE` | "{" | `{ }` |
| `RBRACE` | "}" | `{ }` |
| `SEMICOLON` | ";" | `x = 5;` |

---

## 📈 Grammar Rules

```
program → program statement | statement

statement → INT ID SEMICOLON
          | ID ASSIGN expr SEMICOLON
          | RETURN expr SEMICOLON
          | IF LPAREN expr RPAREN block
          | IF LPAREN expr RPAREN block ELSE block
          | WHILE LPAREN expr RPAREN block

block → LBRACE program RBRACE | statement

expr → expr PLUS expr
     | expr MINUS expr
     | expr MUL expr
     | expr DIV expr
     | LPAREN expr RPAREN
     | NUMBER
     | ID
```

---

## 🐛 Troubleshooting

### **Error: `y.tab.h: No such file or directory`**
- **Cause:** Bison wasn't run or failed
- **Solution:** Run `bison -d parser.y` first

### **Error: `yylex() not found`**
- **Cause:** Flex wasn't run
- **Solution:** Run `flex lexer.l` first

### **Error: `gcc: command not found`**
- **Cause:** GCC not installed or not in PATH
- **Solution:** Install MinGW or MSYS2

### **Error: `division by zero`**
- **Cause:** Expression evaluated with `/0`
- **Note:** Compiler detects this and warns

---

## 📚 Learning Outcomes

After completing this project, you'll understand:
1. How lexical analysis works with Flex
2. How syntax parsing works with Bison
3. Building a compiler from scratch
4. Handling multiple language constructs
5. Error detection and reporting

---

## 🎓 VIVA Questions

1. **What does Flex do?** - Converts input into tokens
2. **What does Bison do?** - Parses tokens according to grammar rules
3. **What is `yylval`?** - Stores token values
4. **What is `yytext`?** - Matched text from lexer
5. **How do you handle operator precedence?** - Using `%left` and `%right` directives
6. **What's the difference between `lexer.l` and `parser.y`?** - Lexer tokenizes, parser analyzes structure
7. **How to compile?** - flex → bison → gcc

---

## 📞 Support

For issues:
1. Check if all tools are installed
2. Verify files are in the same directory
3. Ensure correct file permissions
4. Check for typos in input code

---

**Happy Compiling!** 🎉
