# ⚠️ If-Else Implementation Status

## Current Issue

The compiler has a **fundamental limitation** with if-else statements:

### Problem
```c
if (num > 0) {
    printf("positive");
} else {
    printf("non-positive");
}
```

**What happens:** Both `printf("positive")` AND `printf("non-positive")` execute.

**Why:** Statements are output during **parsing time**, not collection time. Each statement rule directly writes to the output file as it's parsed, rather than being buffered for conditional execution.

### Output Shows All Branches
```
positive even number is 15
positive odd number
non-positive number
```

All three branches execute because they're all written to the generated C file outside any if-else block.

---

## Solution Required

To fix this properly would require:

1. **AST Generation** - Build an Abstract Syntax Tree first
2. **Two-Pass Compilation** - First pass: collect structure, Second pass: generate code
3. **Complete Output Buffering** - Buffer all statements until control flow is complete

This is a **significant architectural change** beyond quick fix scope.

---

## Current Workaround

Use **comparisons without if-else** statements:

```c
int main() {
    int num = 15;
    printf("Is positive:", (num > 0));
    printf("Is even:", ((num % 2) == 0));
    printf("Is odd:", ((num % 2) != 0));
    return 0;
}
```

---

## What DOES Work

✅ All 5 basic examples (arithmetic, comparison, float, strings, logic)
✅ Comparison operators return 0 or 1
✅ Printf with auto type detection
✅ Variables and type tracking

❌ If-else statements with blocks
❌ While loops with blocks
❌ Nested conditionals

---

## Status

**If-else support:** ⏳ Planned for v2.0

The current implementation would require a complete compiler redesign to properly support control flow structures.
