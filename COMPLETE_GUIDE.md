# ✅ FULL C COMPILER - COMPLETE GUIDE

## 🚀 ONE-LINE SETUP

```powershell
flex lexer.l ; bison -d parser.y ; gcc lex.yy.c parser.tab.c -o compiler.exe
```

## 📝 QUICK EXAMPLES

### 1️⃣ Integer Example
**File: `test_int.c`**
```c
int main() {
    int x;
    x = 42;
    printf(x);
    return 0;
}
```
**Run:** `.\compiler.exe test_int.c`  
**Output:** `42`

---

### 2️⃣ Float Example  
**File: `test_float.c`**
```c
int main() {
    float x;
    float y;
    float z;
    x = 5.5;
    y = 2.3;
    z = x + y;
    printf(z);
    return 0;
}
```
**Run:** `.\compiler.exe test_float.c`  
**Output:** `7.800000`

---

### 3️⃣ String Example
**File: `test_string.c`**
```c
int main() {
    char() message = "Hello World";
    printf(message);
    return 0;
}
```
**Run:** `.\compiler.exe test_string.c`  
**Output:** `Hello World`

---

### 4️⃣ Arithmetic with Integers
**File: `test_add.c`**
```c
int main() {
    int a;
    int b;
    int c;
    a = 5;
    b = 3;
    c = a + b;
    printf(c);
    return 0;
}
```
**Run:** `.\compiler.exe test_add.c`  
**Output:** `8`

---

### 5️⃣ Mixed Operations
**File: `test_mixed.c`**
```c
int main() {
    int result;
    result = 5 + 3 * 2;
    printf(result);
    return 0;
}
```
**Run:** `.\compiler.exe test_mixed.c`  
**Output:** `11`

---

### 6️⃣ Subtraction
**File: `test_sub.c`**
```c
int main() {
    int x;
    int y;
    x = 20;
    y = 8;
    printf(x - y);
    return 0;
}
```
**Run:** `.\compiler.exe test_sub.c`  
**Output:** `12`

---

### 7️⃣ Multiplication
**File: `test_mult.c`**
```c
int main() {
    int a;
    int b;
    a = 7;
    b = 3;
    printf(a * b);
    return 0;
}
```
**Run:** `.\compiler.exe test_mult.c`  
**Output:** `21`

---

### 8️⃣ Division
**File: `test_div.c`**
```c
int main() {
    int x;
    x = 20;
    printf(x / 4);
    return 0;
}
```
**Run:** `.\compiler.exe test_div.c`  
**Output:** `5`

---

## 🎯 SUPPORTED DATA TYPES

| Type | Declaration | Example |
|------|-------------|---------|
| **Integer** | `int x;` | `int x = 5;` |
| **Float** | `float x;` | `float x = 3.14;` |
| **String** | `char() x` | `char() msg = "Hello";` |

---

## 🔧 SUPPORTED OPERATORS

### Arithmetic
- `+` Addition
- `-` Subtraction
- `*` Multiplication
- `/` Division

### Comparison
- `<` Less than
- `>` Greater than
- `<=` Less or equal
- `>=` Greater or equal
- `==` Equal
- `!=` Not equal

### Logical
- `&&` AND
- `||` OR
- `!` NOT

### Assignment
- `=` Assignment

### Unary
- `++` Increment
- `--` Decrement

---

## 📋 STATEMENTS SUPPORTED

```c
int x = 5;           // Variable declaration
x = 10;              // Assignment
printf(x);           // Print output
return 0;            // Return value
if (x > 5) { }       // Conditional
while (x) { }        // Loop
```

---

## 🎓 HOW IT WORKS

```
Your C Code (input.c)
    ↓
[FLEX - Lexer] Tokenizes
    ↓
[BISON - Parser] Parses & Generates C
    ↓
Generated C Code (generated.c)
    ↓
[GCC Compiler] Compiles to executable
    ↓
[Executable] Runs automatically
    ↓
Output displayed
```

---

## 📂 GENERATED FILES

- `generated.c` - Generated C source code
- `out_0.exe`, `out_1.exe`, etc. - Compiled executables (numbered for each run)
- `lex.yy.c` - Flex lexer code
- `parser.tab.c` - Bison parser code
- `parser.tab.h` - Bison parser header

---

## ⚠️ IMPORTANT NOTES

1. **Always return 0 at the end** of main
2. **Declare variables before using** them
3. **Use printf() for output** - simple `return` doesn't display
4. **Strings use** `char()` syntax for pointers
5. **Float precision** may vary (shows 6 decimals)
6. **Each run creates** a new numbered .exe file

---

## 🐛 TROUBLESHOOTING

| Issue | Solution |
|-------|----------|
| Float prints wrong | Ensure variable declared as `float`, not `int` |
| String doesn't print | Use `char()` for string pointers |
| Variable not found | Declare before use |
| Syntax error | Check for missing semicolons |

---

## 💪 NEXT STEPS

Try these advanced features:
- [ ] Add `for` loops
- [ ] Add function calls
- [ ] Add arrays
- [ ] Add pointers
- [ ] Add structs
- [ ] Add file I/O

---

**Your C Compiler is Ready!** 🎉
