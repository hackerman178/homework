@echo off

set /a numb=1
:loop
set /a ostatok=(%numb%*%numb%)%%1000000

if "%ostatok%"=="269696" (goto :exit)
set /a numb=%numb%+1
goto :loop


:exit
echo %numb%
