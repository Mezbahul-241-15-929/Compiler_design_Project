# 📚 If-Else Examples & Programming Guide

## ⚠️ Current Limitation

The Mini C Compiler **does not yet support if-else statements with curly braces**. The example you provided:

```c
int main() {
    int x = 5;
    if (x > 3) {
        printf("greater");
    }
    printf("done");
    return 0;
}
```

Will result in: `Error on line 3: syntax error`

**Reason:** If-else block handling requires buffering statements inside braces, which is a complex parser change. This feature is on the roadmap but not yet implemented.

---

## ✅ What WORKS Right Now

The compiler supports all the following features without if-else blocks:

### 1. Arithmetic Operations

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

**Output:** `a =10b =20Sum:30Difference:-10Product:200Division:0`

**Operators:** `+`, `-`, `*`, `/`, `%`

---

### 2. Comparison Operations

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

**Output:** `x:15y:25x == z:1x > y:0y >= x:1x != y:1`

**Operators:** `==`, `!=`, `>`, `>=`, `<`, `<=`

**Boolean Results:** 1 = TRUE, 0 = FALSE

---

### 3. Float Calculations

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

**Output:** `Price:99.989998Tax Rate:0.100000Total:109.988998`

**Features:**
- Decimal number support
- Complex arithmetic expressions
- Automatic float formatting in printf

---

### 4. String Operations

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

**Output:** `Alice works as a EngineerSalary:50000`

**Features:**
- String variables with `char()`
- Multiple printf arguments concatenate automatically
- Mix strings and integers seamlessly

---

### 5. Boolean Logic (Simulated)

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

**Output:** `Score:85Pass:1Merit:1Distinction:0`

**Logic:**
- Comparisons return 1 (TRUE) or 0 (FALSE)
- Useful for conditional evaluation
- Can simulate if-else logic with printf output

---

## 📊 Data Types

| Type | Declaration | Example |
|------|-------------|---------|
| Integer | `int x;` | `int age = 25;` |
| Float | `float x;` | `float pi = 3.14;` |
| String | `char() x;` | `char() name = "Alice";` |
| Char | `char x;` | `char letter = 'A';` |

---

## 🔧 All Operators Supported

### Arithmetic
- Addition: `a + b`
- Subtraction: `a - b`
- Multiplication: `a * b`
- Division: `a / b`
- Modulo: `a % b`
- Increment: `a++`, `++a`
- Decrement: `a--`, `--a`

### Comparison
- Equal: `a == b`
- Not Equal: `a != b`
- Greater: `a > b`
- Greater or Equal: `a >= b`
- Less: `a < b`
- Less or Equal: `a <= b`

### Logical (Returns 0 or 1)
- AND: `a && b`
- OR: `a || b`
- NOT: `!a`

---

## 🎯 Practical Examples

### Calculate Bill Amount
```c
int main() {
    float subtotal = 150.00;
    float discount_rate = 0.10;
    float final_amount = (subtotal * (1 - discount_rate));
    printf("Subtotal:", subtotal);
    printf("Discount:", (subtotal * discount_rate));
    printf("Final:", final_amount);
    return 0;
}
```

### Temperature Comparison
```c
int main() {
    float temp1 = 98.6;
    float temp2 = 100.2;
    printf("Temp1:", temp1);
    printf("Temp2:", temp2);
    printf("Temp1 > Temp2:", (temp1 > temp2));
    printf("Average:", ((temp1 + temp2) / 2));
    return 0;
}
```

### Student Information
```c
int main() {
    char() name = "Bob";
    int age = 20;
    float gpa = 3.85;
    printf(name, " is ", age);
    printf("GPA:", gpa);
    printf("Honor:", (gpa >= 3.8));
    return 0;
}
```

---

## 🚀 How to Use

1. **Create a file** with `.c` extension
2. **Write your code** using supported features
3. **Run compiler:** `.\compiler.exe filename.c`
4. **View output:** Displays automatically

---

## 📋 Running Examples

```powershell
.\compiler.exe example_arithmetic.c
.\compiler.exe example_comparison.c
.\compiler.exe example_float_calc.c
.\compiler.exe example_strings.c
.\compiler.exe example_logic.c
```

---

## 🔄 Roadmap (Future Features)

- ✅ If-else statements with blocks
- ✅ While loops with blocks
- ✅ For loops
- ✅ Arrays
- ✅ Functions
- ✅ Ternary operator (`? :`)

---

## 💡 Tips & Tricks

1. **Use parentheses** for clarity: `(a + b) * c`
2. **Test with printf**: Use printf to verify intermediate results
3. **Boolean returns**: Comparisons return 0 or 1
4. **Type auto-detection**: Printf automatically formats based on type
5. **String concatenation**: Multiple printf args concatenate automatically

---

**Happy Coding! 🎉**

Current Status: ✅ Full arithmetic, comparison, string, and float support
Coming Soon: If-else and loop blocks
