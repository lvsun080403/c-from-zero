@echo off
setlocal enabledelayedexpansion
chcp 65001 >nul 2>&1

rem ============================================================
rem  build.bat  -  compile every .c file in plain\ (or commented\)
rem  usage:  build.bat            -> compiles plain\
rem          build.bat commented  -> compiles commented\
rem ============================================================

set "SRC=plain"
if /i "%~1"=="commented" set "SRC=commented"
if not exist "%SRC%" (
    echo [x] folder "%SRC%" not found. run this script inside the repo root.
    exit /b 1
)

set "CC="
for %%c in (gcc clang tcc) do (
    if not defined CC (
        where %%c >nul 2>&1 && set "CC=%%c"
    )
)

if not defined CC (
    echo [x] no C compiler found in PATH.
    echo     install MinGW-w64 / LLVM, or drop a tcc.exe next to this file,
    echo     then run:  tcc -o build\01.exe plain\01-sort-three.c
    exit /b 1
)

echo [i] compiler : %CC%
echo [i] source   : %SRC%\

if not exist "build" mkdir "build"

set /a OK=0
set /a BAD=0

for %%f in ("%SRC%\*.c") do (
    set "NAME=%%~nf"
    %CC% "%%f" -o "build\!NAME!.exe" >nul 2>&1
    if exist "build\!NAME!.exe" (
        set /a OK+=1
        echo     [ok]   %%~nxf
    ) else (
        set /a BAD+=1
        echo     [fail] %%~nxf
    )
)

echo.
echo [i] done: !OK! compiled, !BAD! failed
if !BAD! GTR 0 exit /b 1
endlocal
