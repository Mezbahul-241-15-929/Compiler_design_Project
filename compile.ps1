# PowerShell Compilation Script for Full C Compiler
# filepath: Problem8_Mini_C_Compiler\compile.ps1

Write-Host "===================================" -ForegroundColor Cyan
Write-Host "Full C Compiler - Compilation" -ForegroundColor Cyan
Write-Host "===================================" -ForegroundColor Cyan
Write-Host ""

# Step 1: Check tools
Write-Host "Checking required tools..." -ForegroundColor Yellow
bison --version > $null 2>&1
if ($LASTEXITCODE -ne 0) {
    Write-Host "ERROR: Bison not found. Install it first!" -ForegroundColor Red
    exit 1
}

flex --version > $null 2>&1
if ($LASTEXITCODE -ne 0) {
    Write-Host "ERROR: Flex not found. Install it first!" -ForegroundColor Red
    exit 1
}

gcc --version > $null 2>&1
if ($LASTEXITCODE -ne 0) {
    Write-Host "ERROR: GCC not found. Install it first!" -ForegroundColor Red
    exit 1
}

Write-Host "✓ All tools found!" -ForegroundColor Green
Write-Host ""

# Step 2: Run Flex
Write-Host "Step 1: Running Flex..." -ForegroundColor Yellow
flex lexer.l
if ($LASTEXITCODE -ne 0) {
    Write-Host "ERROR: Flex compilation failed!" -ForegroundColor Red
    exit 1
}
Write-Host "✓ lex.yy.c created" -ForegroundColor Green
Write-Host ""

# Step 3: Run Bison
Write-Host "Step 2: Running Bison..." -ForegroundColor Yellow
bison -d parser.y
if ($LASTEXITCODE -ne 0) {
    Write-Host "ERROR: Bison compilation failed!" -ForegroundColor Red
    exit 1
}
Write-Host "✓ parser.tab.c and parser.tab.h created" -ForegroundColor Green
Write-Host ""

# Step 4: Compile with GCC
Write-Host "Step 3: Compiling with GCC..." -ForegroundColor Yellow
gcc lex.yy.c parser.tab.c -o mini_compiler.exe
if ($LASTEXITCODE -ne 0) {
    Write-Host "ERROR: GCC compilation failed!" -ForegroundColor Red
    exit 1
}
Write-Host "✓ mini_compiler.exe created" -ForegroundColor Green
Write-Host ""

Write-Host "===================================" -ForegroundColor Green
Write-Host "Compilation Successful!" -ForegroundColor Green
Write-Host "===================================" -ForegroundColor Green
Write-Host ""

Write-Host "Usage: .\mini_compiler.exe input.c" -ForegroundColor Yellow
Write-Host ""