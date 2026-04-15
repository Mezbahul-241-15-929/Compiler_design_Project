@echo off
REM Compile Full C Compiler
REM filepath: Problem8_Mini_C_Compiler\compile.bat

echo ===================================
echo Full C Compiler - Compilation Script
echo ===================================

cd /d "%~dp0"

echo.
echo Step 1: Running Flex...
flex lexer.l
if errorlevel 1 (
    echo Error: Flex failed. Make sure Flex is installed.
    pause
    exit /b 1
)

echo Step 1: Success - lex.yy.c created
echo.

echo Step 2: Running Bison...
bison -d parser.y
if errorlevel 1 (
    echo Error: Bison failed. Make sure Bison is installed.
    pause
    exit /b 1
)

echo Step 2: Success - parser.tab.c and parser.tab.h created
echo.

echo Step 3: Compiling with GCC...
gcc lex.yy.c parser.tab.c -o mini_compiler.exe
if errorlevel 1 (
    echo Error: Compilation failed. Make sure GCC is installed.
    pause
    exit /b 1
)

echo Step 3: Success - mini_compiler.exe created
echo.

echo ===================================
echo Compilation Successful!
echo ===================================
echo.
echo Usage: mini_compiler.exe input.c
echo.

.\mini_compiler.exe

pause
