# 🎯 C COMPILER - COMPLETE EXAMPLES

## Setup (Run Once)
```powershell
flex lexer.l ; bison -d parser.y ; gcc lex.yy.c parser.tab.c -o compiler.exe
```

---

## ✅ EXAMPLE 1: Simple String Output
**File: `ex1.c`**
```c
int main() {
    printf("Hello World");
    return 0;
}
```
**Run:** `.\compiler.exe ex1.c`  
**Output:**
```
Hello World
```

---

## ✅ EXAMPLE 2: Integer with Format
**File: `ex2.c`**
```c
int main() {
    int age;
    age = 25;
    printf("Age:", age);
    return 0;
}
```
**Run:** `.\compiler.exe ex2.c`  
**Output:**
```
Age: 25
```

---

## ✅ EXAMPLE 3: Float with Format
**File: `ex3.c`**
```c
int main() {
    float temperature;
    temperature = 98.6;
    printf("Temp:", temperature);
    return 0;
}
```
**Run:** `.\compiler.exe ex3.c`  
**Output:**
```
Temp: 98.600000
```

---

## ✅ EXAMPLE 4: String Variable with Format
**File: `ex4.c`**
```c
int main() {
    char() city = "New York";
    printf("City:", city);
    return 0;
}
```
**Run:** `.\compiler.exe ex4.c`  
**Output:**
```
City: New York
```

---

## ✅ EXAMPLE 5: Arithmetic Operations
**File: `ex5.c`**
```c
int main() {
    int a;
    int b;
    int sum;
    a = 10;
    b = 20;
    sum = a + b;
    printf("Sum:", sum);
    return 0;
}
```
**Run:** `.\compiler.exe ex5.c`  
**Output:**
```
Sum: 30
```

---

## ✅ EXAMPLE 6: Multiplication
**File: `ex6.c`**
```c
int main() {
    int length;
    int width;
    int area;
    length = 5;
    width = 4;
    area = length * width;
    printf("Area:", area);
    return 0;
}
```
**Run:** `.\compiler.exe ex6.c`  
**Output:**
```
Area: 20
```

---

## ✅ EXAMPLE 7: Division
**File: `ex7.c`**
```c
int main() {
    int total;
    int parts;
    int each;
    total = 100;
    parts = 4;
    each = total / parts;
    printf("Each:", each);
    return 0;
}
```
**Run:** `.\compiler.exe ex7.c`  
**Output:**
```
Each: 25
```

---

## ✅ EXAMPLE 8: Subtraction
**File: `ex8.c`**
```c
int main() {
    int start;
    int end;
    int difference;
    start = 50;
    end = 20;
    difference = start - end;
    printf("Diff:", difference);
    return 0;
}
```
**Run:** `.\compiler.exe ex8.c`  
**Output:**
```
Diff: 30
```

---

## ✅ EXAMPLE 9: Complex Expression
**File: `ex9.c`**
```c
int main() {
    int result;
    result = 5 + 3 * 2;
    printf("Result:", result);
    return 0;
}
```
**Run:** `.\compiler.exe ex9.c`  
**Output:**
```
Result: 11
```

---

## ✅ EXAMPLE 10: Float Arithmetic
**File: `ex10.c`**
```c
int main() {
    float x;
    float y;
    float z;
    x = 5.5;
    y = 2.3;
    z = x + y;
    printf("Sum:", z);
    return 0;
}
```
**Run:** `.\compiler.exe ex10.c`  
**Output:**
```
Sum: 7.800000
```

---

## ✅ EXAMPLE 11: Increment Operator
**File: `ex11.c`**
```c
int main() {
    int count;
    count = 5;
    count++;
    printf("Count:", count);
    return 0;
}
```
**Run:** `.\compiler.exe ex11.c`  
**Output:**
```
Count: 6
```

---

## ✅ EXAMPLE 12: Multiple Statements
**File: `ex12.c`**
```c
int main() {
    int x;
    int y;
    x = 10;
    y = 20;
    printf("First:", x);
    printf("Second:", y);
    return 0;
}
```
**Run:** `.\compiler.exe ex12.c`  
**Output:**
```
First: 10
Second: 20
```

---

## 📊 SUPPORTED SYNTAX

### Data Types
- `int` - Integer numbers
- `float` - Decimal numbers
- `char()` - String/text

### Operators
- `+` Addition
- `-` Subtraction
- `*` Multiplication
- `/` Division
- `++` Increment
- `--` Decrement

### Printf Formats
- `printf("text")` - Just text
- `printf("label:", variable)` - Label with value

### Control Flow (Available)
- `if (condition) { }`
- `while (condition) { }`
- `return value;`

---

## 💡 TIPS

1. **Always use `return 0;`** at the end of main
2. **Declare variables** before using them
3. **Use semicolons** after each statement
4. **Printf auto-detects type** - no need for format codes!
5. **Each program is independent** - can run multiple times

---

**Happy Coding!** 🚀
