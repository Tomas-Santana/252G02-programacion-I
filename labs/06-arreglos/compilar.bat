@echo off
set "PATH=%~dp0w64devkit\bin;%PATH%"
g++ "%~1" -o "%~dpn1.exe"
if errorlevel 1 exit /b 1
if "%~2"=="ejecutar" start "Programa" cmd /c ""%~dpn1.exe" & echo. & pause"
