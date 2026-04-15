# ⚡ Quick Reference Card

## 🎯 5 Seconds to Run Your First Program

```powershell
.\compiler.exe example_arithmetic.c
```

**Output:** `a =10b =20Sum:30Difference:-10Product:200Division:0` ✅

---

## 💻 Program Template (Copy & Paste)

```c
int main() {
    // Variables
    int x = 10;
    float y = 3.14;
    char() text = "Hello";
    
    // Calculations
    int result = (x + 5);
    
    // Output
    printf("X:", x);
    printf("Result:", result);
    printf("Text:", text);
    
    return 0;
}
```

---

## 📊 Data Types

| Type | Example |
|------|---------|
| `int` | `int age = 25;` |
| `float` | `float price = 99.99;` |
| `char()` | `char() name = "Alice";` |

---

## ➕ Operators

| Operator | Example | Result |
|----------|---------|--------|
| `+` | `10 + 5` | 15 |
| `-` | `10 - 5` | 5 |
| `*` | `10 * 5` | 50 |
| `/` | `10 / 5` | 2 |
| `%` | `10 % 3` | 1 |
| `==` | `10 == 10` | 1 (true) |
| `!=` | `10 != 5` | 1 (true) |
| `>` | `10 > 5` | 1 (true) |
| `<` | `10 < 5` | 0 (false) |
| `>=` | `10 >= 10` | 1 (true) |
| `<=` | `10 <= 5` | 0 (false) |

---

## 🖨️ Printf Examples

```c
// String only
printf("Hello");

// Single variable
printf(x);

// Label + value
printf("Age:", 25);

// Multiple arguments
printf("Name:", "Alice", "Age:", 25);

// Expression
printf("Sum:", (10 + 20));
```

---

## 📝 Complete Examples

### Example 1: Simple Math
```c
int main() {
    int a = 10;
    int b = 20;
    printf("Sum:", (a + b));
    return 0;
}
```

### Example 2: Comparison
```c
int main() {
    int x = 85;
    printf("Pass:", (x >= 60));
    printf("Merit:", (x >= 80));
    return 0;
}
```

### Example 3: Floats
```c
int main() {
    float total = (99.99 * 1.1);
    printf("Total:", total);
    return 0;
}
```

### Example 4: Strings
```c
int main() {
    char() name = "Bob";
    printf("Hello,", name);
    return 0;
}
```

---

## 🚀 Run Your Program

1. **Create file:** `myprogram.c`
2. **Write code:** Add your program
3. **Compile & Run:** `.\compiler.exe myprogram.c`
4. **See output:** Displays automatically

---

## ✅ Working Features

- ✅ Variables (int, float, char())
- ✅ Arithmetic (+, -, *, /, %)
- ✅ Comparisons (==, !=, <, >, <=, >=)
- ✅ Printf with auto type detection
- ✅ String support
- ✅ Float support
- ✅ Complex expressions

---

## ❌ Not Working Yet

- ❌ If-else statements
- ❌ While loops
- ❌ For loops
- ❌ Arrays
- ❌ Functions

---

## 📚 Documentation

| File | Purpose |
|------|---------|
| `LEARNING_GUIDE.md` | Complete tutorial |
| `EXECUTION_SUMMARY.md` | Test results |
| `PROGRAMMING_EXAMPLES.md` | Reference |
| `README.md` | Project info |

---

## 💡 Quick Tips

```c
// Use parentheses for clarity
printf("Result:", ((a + b) * c));

// Comparisons return 0 or 1
int pass = (score >= 60);

// Multiple printf args concatenate
printf("Name:", name, "Age:", age);

// Always use semicolons
int x = 10;

// Always end with return
return 0;
```

---

## 🎯 All 5 Examples

```powershell
.\compiler.exe example_arithmetic.c
.\compiler.exe example_comparison.c
.\compiler.exe example_float_calc.c
.\compiler.exe example_strings.c
.\compiler.exe example_logic.c
```

---

**Status: ✅ Ready to Code!**

*Start with:* `.\compiler.exe example_arithmetic.c`
