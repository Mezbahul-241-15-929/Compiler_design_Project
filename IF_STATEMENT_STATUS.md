# IF Statement Support - Status & Workaround

## Current Status

✅ **Simple IF statements WORK**
```c
if (age >= 18) {
    printf("You are an adult");
}
```

❌ **IF-ELSE statements DO NOT WORK** (Parser limitation)
```c
if (age >= 18) {
    printf("You are an adult");
} else {
    printf("You are a minor");
}
// Error: "Parse error on line X"
```

## Why the Limitation Exists

This is a classic **"Dangling Else" problem** in compiler design:
- The LALR(1) parser cannot decide after seeing `}` whether to:
  1. Reduce the if-statement rule (end of if-only), OR
  2. Shift the ELSE token (continue to if-else)
- This creates **reduce/reduce conflicts** that prevent proper parsing
- Fixing this requires either:
  - A GLR parser (more complex, slower)
  - Complete grammar restructuring (significant rewrite)
  - An AST-based two-pass compiler

## Workaround: Use Separate IF Statements

Instead of if-else, use two separate if statements with **opposite conditions**:

### Example 1: Age Check
**DON'T use:**
```c
int main() {
    int age = 20;
    if (age >= 18) {
        printf("adult");
    } else {
        printf("minor");
    }
    return 0;
}
```

**DO use:**
```c
int main() {
    int age = 20;
    if (age >= 18) {
        printf("adult");
    }
    if (age < 18) {
        printf("minor");
    }
    return 0;
}
```

### Example 2: Even/Odd Check
**DON'T use:**
```c
if (num % 2 == 0) {
    printf("even");
} else {
    printf("odd");
}
```

**DO use:**
```c
if (num % 2 == 0) {
    printf("even");
}
if (num % 2 != 0) {
    printf("odd");
}
```

## Testing

Test files demonstrating the workaround:
- `test_if_separate.c` - Shows working two-if approach
- `test_if_else_workaround.c` - Adult/minor example with workaround

Run: `.\mini_compiler.exe test_if_else_workaround.c`

## Future Improvements

To fully support if-else-if chains, the compiler would need:
1. **Option A (Recommended)**: Rewrite with AST-based code generation
2. **Option B**: Use Bison's GLR mode for ambiguous grammars
3. **Option C**: Implement a pre-processor to convert if-else to nested ifs

For now, use the workaround pattern above.
