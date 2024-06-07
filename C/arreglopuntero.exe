@echo off
setlocal enabledelayedexpansion

:: Encuentra el último archivo .c modificado
for /f "delims=" %%x in ('dir *.c /b /od /a-d') do set "latest=%%x"

:: Compila el último archivo .c encontrado
if defined latest (
    echo Compilando !latest!...
    gcc !latest! -o !latest:.c=.exe!
    echo Compilación completada: !latest:.c=.exe!
) else (
    echo No se encontraron archivos .c para compilar.
)

endlocal
pause
