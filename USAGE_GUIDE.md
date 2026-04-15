# 📖 FULL USAGE GUIDE FOR MINI C COMPILER

## 🎯 WHAT THIS IS

This is a **FULL C COMPILER** that:
- Takes a `.c` file as input
- **Parses** it (syntax checking)
- **Generates** C code
- **Compiles** to an executable
- **Runs** the program automatically
- **Shows** the output

## 📦 FILES YOU NEED

| File | Purpose |
|------|---------|
| `lexer.l` | Lexical analyzer (tokenizer) |
| `parser.y` | Syntax parser (grammar rules) |
| `compile.ps1` / `compile.bat` | Build scripts |
| `mini_compiler.exe` | The final compiler (generated) |
| `sample*.c` | Example input programs |

---

## 🚀 GETTING STARTED (3 EASY STEPS)

### STEP 1: Compile the Compiler (DO THIS ONCE)

**Option A - PowerShell (Recommended for Windows):**
```powershell
.\compile.ps1
```

**Option B - Command Prompt:**
```batch
compile.bat
```

**Option C - Manual (if scripts don't work):**
```bash
flex lexer.l
bison -d parser.y
gcc lex.yy.c parser.tab.c -o mini_compiler.exe
```

### STEP 2: Create Your C Program

Create a file named `myprogram.c`:
```c
int main() {
    int x;
    x = 5;
    return x;
}
```

### STEP 3: Run Your Program Through the Compiler

```bash
mini_compiler.exe myprogram.c
```

**Output will appear like:**
```
[*] Parsing 'myprogram.c'...
[*] Generated code written to 'generated.c'
[*] Compiling generated.c...
[*] Running compiled program...

========== OUTPUT ==========
===========================
```

---

## 💡 EXAMPLE PROGRAMS

### Example 1: Simple Variables
**File: `ex1.c`**
```c
int main() {
    int a;
    a = 10;
    return a;
}
```

**Run:**
```bash
mini_compiler.exe ex1.c
```

**Output:** `10`

---

### Example 2: Arithmetic
**File: `ex2.c`**
```c
int main() {
    int x;
    int y;
    int sum;
    x = 5;
    y = 3;
    sum = x + y;
    return sum;
}
```

**Run:**
```bash
mini_compiler.exe ex2.c
```

**Output:** `8`

---

### Example 3: If Statement
**File: `ex3.c`**
```c
int main() {
    int x;
    x = 5;
    if (x) {
        x = 100;
    }
    return x;
}
```

**Run:**
```bash
mini_compiler.exe ex3.c
```

**Output:** `100`

---

### Example 4: While Loop
**File: `ex4.c`**
```c
int main() {
    int count;
    count = 3;
    while (count) {
        count = count - 1;
    }
    return count;
}
```

**Run:**
```bash
mini_compiler.exe ex4.c
```

**Output:** `0`

---

### Example 5: Comparisons
**File: `ex5.c`**
```c
int main() {
    int a;
    int b;
    a = 5;
    b = 3;
    if (a > b) {
        return 1;
    }
    return 0;
}
```

---

## 📊 SUPPORTED FEATURES

### Variables
```c
int x;           // Declaration
x = 5;           // Assignment
int y = 10;      // Combined
```

### Operators
```c
x + y    // Addition
x - y    // Subtraction
x * y    // Multiplication
x / y    // Division
```

### Comparisons
```c
x < y    // Less than
x > y    // Greater than
x <= y   // Less than or equal
x >= y   // Greater than or equal
x == y   // Equal
x != y   // Not equal
```

### Logical
```c
x && y   // AND
x || y   // OR
!x       // NOT
```

### Statements
```c
if (condition) { }
if (cond) { } else { }
while (condition) { }
return value;
```

### Increment/Decrement
```c
x++;     // Post-increment
x--;     // Post-decrement
```

---

## 📁 FILE FLOW

```
Your C Code
    ↓
lexer.l (tokenizes)
    ↓
parser.y (parses)
    ↓
Generated C Code (generated.c)
    ↓
GCC Compiler
    ↓
Executable (generated.exe)
    ↓
Auto-runs and shows OUTPUT
```

---

## 🔍 WHAT HAPPENS INSIDE

When you run `mini_compiler.exe myprogram.c`:

1. **Reads** your C file
2. **Tokenizes** it using Flex lexer
3. **Parses** tokens using Bison parser
4. **Generates** valid C code → `generated.c`
5. **Compiles** with GCC → `generated.exe`
6. **Executes** the program
7. **Displays** return value and output

---

## ⚠️ COMMON ISSUES

### Issue: "mini_compiler.exe not found"
**Solution:** Run `compile.ps1` or `compile.bat` first

### Issue: "Permission denied" when compiling
**Solution:** Close any running mini_compiler processes and try again

### Issue: Parsing errors in your program
**Solution:** Check syntax - only supported features work (see above list)

### Issue: "flex/bison/gcc not found"
**Solution:** Install MinGW or MSYS2:
```powershell
choco install winflexbison mingw
```

---

## 📋 CHECKLIST

- [ ] Run `compile.ps1` to build the compiler
- [ ] Create a `.c` file with your code
- [ ] Run `mini_compiler.exe yourfile.c`
- [ ] See the output displayed
- [ ] Check `generated.c` to see the generated code
- [ ] Check `generated.exe` to run it again

---

## 🎓 LEARNING OUTCOMES

After using this compiler, you'll understand:

1. **Lexical Analysis** - How text becomes tokens
2. **Syntax Parsing** - How tokens become code structure
3. **Code Generation** - How AST becomes executable code
4. **Compilation** - The full compile process
5. **Language Design** - Building your own language

---

## 📚 TECHNICAL DETAILS

### Grammar Rules

```
program → function
function → INT ID ( ) { statements }
statements → statement statements | ε
statement → INT ID ;
          | INT ID = expr ;
          | ID = expr ;
          | RETURN expr ;
          | IF ( expr ) { statements }
          | WHILE ( expr ) { statements }
```

### Example Compilation

**Input (`test.c`):**
```c
int main() {
    int x;
    x = 5;
    return x;
}
```

**Generated (`generated.c`):**
```c
#include <stdio.h>
int main() {
    int x = 0;
    x = 5;
    return x;
    return 0;
}
```

**Execution:**
- Program returns: `5`

---

## 🎯 QUICK REFERENCE

| Task | Command |
|------|---------|
| Compile compiler | `.\compile.ps1` |
| Test with sample | `mini_compiler.exe sample1.c` |
| View generated code | `type generated.c` |
| Re-run executable | `generated.exe` |
| Delete build files | `del *.exe lex.yy.c parser.tab.*` |

---

## 💪 NEXT STEPS

Try these to expand the compiler:

1. Add `printf()` support
2. Add arrays
3. Add functions
4. Add for loops
5. Add string support
6. Add more operators

---

**Happy Compiling! 🎉**
