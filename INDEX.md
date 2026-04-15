# 📑 C COMPILER PROJECT - FILE INDEX

## 🚀 START HERE

1. **README.md** - Quick start guide with examples
2. **SUCCESS.md** - Verification that everything works
3. **EXAMPLES.md** - 12+ working example programs

---

## 📚 DOCUMENTATION

| File | Purpose |
|------|---------|
| `README.md` | Overview and quick commands |
| `SUCCESS.md` | Test results and verification |
| `EXAMPLES.md` | Complete example programs (12+) |
| `FEATURES.md` | Feature summary and learning outcomes |
| `COMPLETE_GUIDE.md` | Comprehensive reference guide |
| `USAGE_GUIDE.md` | Detailed usage instructions |

---

## 🧪 TEST PROGRAMS

Ready-to-run test files:

| File | Tests |
|------|-------|
| `test1_simple_string.c` | `printf("Hello")` |
| `test2_format_int.c` | `printf("Output:", int)` |
| `test3_format_float.c` | `printf("Value:", float)` |
| `test4_format_string.c` | `printf("Name:", string)` |
| `test_add.c` | Arithmetic addition |
| `test_float.c` | Float operations |
| `test_int.c` | Integer variables |
| `test_string.c` | String variables |
| `test_print.c` | Basic printf |

**Run any test:**
```powershell
.\compiler.exe test1_simple_string.c
.\compiler.exe test2_format_int.c
```

---

## 🛠️ COMPILER FILES

| File | Purpose |
|------|---------|
| `lexer.l` | Flex lexical analyzer |
| `parser.y` | Bison syntax parser |
| `compiler.exe` | Compiled compiler (MAIN) |
| `lex.yy.c` | Generated lexer code |
| `parser.tab.c` | Generated parser code |
| `parser.tab.h` | Generated parser header |
| `generated.c` | Output C code |

---

## ⚙️ SETUP COMMANDS

```powershell
# Compile the compiler (ONE TIME)
flex lexer.l ; bison -d parser.y ; gcc lex.yy.c parser.tab.c -o compiler.exe

# Run a program
.\compiler.exe your_program.c
```

---

## ✅ WHAT WORKS

### Data Types
- ✅ `int` - Integer numbers
- ✅ `float` - Decimal numbers
- ✅ `char()` - String text

### Printf Formats
- ✅ `printf("text")` - String output
- ✅ `printf("label:", variable)` - Formatted output

### Operations
- ✅ Arithmetic: `+`, `-`, `*`, `/`
- ✅ Comparison: `<`, `>`, `<=`, `>=`, `==`, `!=`
- ✅ Logical: `&&`, `||`, `!`
- ✅ Unary: `++`, `--`

---

## 📖 READING ORDER

**First Time Users:**
1. Read `README.md` (2 min)
2. Read `SUCCESS.md` (2 min)
3. Try `test1_simple_string.c` (1 min)
4. Try `test2_format_int.c` (1 min)

**Learning:**
1. Read `FEATURES.md` (5 min)
2. Browse `EXAMPLES.md` (10 min)
3. Try examples one by one

**Deep Dive:**
1. Read `COMPLETE_GUIDE.md` (20 min)
2. Read `USAGE_GUIDE.md` (10 min)
3. Study `lexer.l` and `parser.y`

---

## 🎯 QUICK TEST

```powershell
# Run all tests
.\compiler.exe test1_simple_string.c
.\compiler.exe test2_format_int.c
.\compiler.exe test3_format_float.c
.\compiler.exe test4_format_string.c
```

**Expected Output:**
```
Hello
Output: 3
Value: 3.140000
Name: Alice
```

---

## 💡 PRO TIPS

1. Check `generated.c` to see what C code is generated
2. Each run creates `out_0.exe`, `out_1.exe`, etc.
3. Look at `EXAMPLES.md` for exact syntax
4. Copy-paste examples and modify them
5. Errors show on stderr, output on stdout

---

## 🎓 LEARNING OUTCOMES

After using this compiler:
- Understand lexical analysis
- Understand syntax parsing
- Understand code generation
- Understand compilation pipeline
- Build your own language

---

## 🚀 START NOW

```powershell
# Just one command:
.\compiler.exe test1_simple_string.c
```

**Output:** `Hello`

Done! Your compiler works! 🎉

---

## 📞 SUPPORT

- Check `EXAMPLES.md` for working code
- Check `README.md` for quick help
- Check `generated.c` to debug
- Check `SUCCESS.md` for verification

---

**Happy Compiling!** ✨
