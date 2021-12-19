@echo off
chcp 1251
for /l %%i in (33,1,255) do (   
    call :_tochar %%i
)
exit /b

:_tochar
cmd /c exit %1
echo %1 "%=exitcodeAscii%"
