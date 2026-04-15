# Mini C Compiler - Programming Examples Guide

## 🎯 Overview

This guide provides practical examples demonstrating the Mini C Compiler's capabilities including arithmetic, comparisons, float calculations, strings, and logic operations.

---

## Example 1: Arithmetic Operations
**File:** `example_arithmetic.c`

Demonstrates: +, -, *, / operators

```c
int main() {
    int a = 10;
    int b = 20;
    printf("a =", a);
    printf("b =", b);
    printf("Sum:", (a + b));
    printf("Difference:", (a - b));
    printf("Product:", (a * b));
    printf("Division:", (a / b));
    return 0;
}
```

**Command:** `.\compiler.exe example_arithmetic.c`

**Output:**
```
a =10b =20Sum:30Difference:-10Product:200Division:0
```

**Key Points:**
- Addition: 10 + 20 = 30
- Subtraction: 10 - 20 = -10
- Multiplication: 10 * 20 = 200
- Division: 10 / 20 = 0 (integer division)

---

## Example 2: Comparison Operators
**File:** `example_comparison.c`

Demonstrates: ==, !=, >, >=, <, <=

```c
int main() {
    int x = 15;
    int y = 25;
    int z = 15;
    printf("x:", x);
    printf("y:", y);
    printf("x == z:", (x == z));
    printf("x > y:", (x > y));
    printf("y >= x:", (y >= x));
    printf("x != y:", (x != y));
    return 0;
}
```

**Command:** `.\compiler.exe example_comparison.c`

**Output:**
```
x:15y:25x == z:1x > y:0y >= x:1x != y:1
```

**Result Explanation:**
- x == z: 1 (TRUE - both are 15)
- x > y: 0 (FALSE - 15 is not greater than 25)
- y >= x: 1 (TRUE - 25 >= 15)
- x != y: 1 (TRUE - 15 ≠ 25)

---

## Example 3: Float Calculations
**File:** `example_float_calc.c`

Demonstrates: float type, decimal arithmetic

```c
int main() {
    float price = 99.99;
    float tax = 0.1;
    float total = (price * (1 + tax));
    printf("Price:", price);
    printf("Tax Rate:", tax);
    printf("Total:", total);
    return 0;
}
```

**Command:** `.\compiler.exe example_float_calc.c`

**Output:**
```
Price:99.989998Tax Rate:0.100000Total:109.988998
```

**Calculation:**
- Price: 99.99
- Tax: 0.1 (10%)
- Total: 99.99 × (1 + 0.1) = 99.99 × 1.1 ≈ 109.99

---

## Example 4: String Operations
**File:** `example_strings.c`

Demonstrates: char() string type, multiple printf arguments

```c
int main() {
    char() name = "Alice";
    char() job = "Engineer";
    int salary = 50000;
    printf(name, " works as a ", job);
    printf("Salary:", salary);
    return 0;
}
```

**Command:** `.\compiler.exe example_strings.c`

**Output:**
```
Alice works as a EngineerSalary:50000
```

**Features:**
- `char()` declares string variables
- Multiple printf arguments automatically concatenate
- Mix strings and variables in one printf call

---

## Example 5: Boolean Logic
**File:** `example_logic.c`

Demonstrates: boolean comparisons, logical operators

```c
int main() {
    int score = 85;
    printf("Score:", score);
    printf("Pass:", (score >= 60));
    printf("Merit:", (score >= 75));
    printf("Distinction:", (score >= 90));
    return 0;
}
```

**Command:** `.\compiler.exe example_logic.c`

**Output:**
```
Score:85Pass:1Merit:1Distinction:0
```

**Interpretation:**
- Score: 85
- Pass (≥60): 1 = TRUE ✓
- Merit (≥75): 1 = TRUE ✓
- Distinction (≥90): 0 = FALSE ✗

---

## 📚 Supported Operators

### Arithmetic Operators
| Operator | Usage | Example |
|----------|-------|---------|
| + | Addition | `a + b` |
| - | Subtraction | `a - b` |
| * | Multiplication | `a * b` |
| / | Division | `a / b` |
| % | Modulo | `a % b` |
| ++ | Increment | `a++` |
| -- | Decrement | `a--` |

### Comparison Operators
| Operator | Usage | Example |
|----------|-------|---------|
| == | Equal to | `a == b` |
| != | Not equal to | `a != b` |
| > | Greater than | `a > b` |
| >= | Greater or equal | `a >= b` |
| < | Less than | `a < b` |
| <= | Less or equal | `a <= b` |

### Logical Operators
| Operator | Usage | Example |
|----------|-------|---------|
| && | AND | `a && b` |
| \|\| | OR | `a \|\| b` |
| ! | NOT | `!a` |

---

## 🚀 Quick Start

1. **Create a C file** (e.g., `example_arithmetic.c`)
2. **Run the compiler:** `.\compiler.exe example_arithmetic.c`
3. **View output:** Program output displays automatically

---

## 💡 Tips

1. Always end with `return 0;`
2. Use semicolons after statements
3. Declare variables before use
4. Printf auto-detects types (no format codes needed)
5. Use parentheses for complex expressions: `(a + b) * c`
6. Boolean results: 1 = TRUE, 0 = FALSE

---

**Ready to code! 🎉**
