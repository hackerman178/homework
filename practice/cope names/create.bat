@echo off
chcp 65001 > nul

SET name=%1


md %name%\"Алгебра и геометрия"
echo Ведякова Анастасия Олеговна > %name%\"Алгебра и геометрия"\readme.txt
echo Начало занятий: %DATE% >> %name%\"Алгебра и геометрия"\readme.txt

md %name%\"Мат.анализ"
echo Eвстафьева Виктория Викторовна > %name%\"Мат.анализ"\readme.txt
echo Начало занятий: %DATE% >> %name%\"Мат.анализ"\readme.txt

md %name%\"Основы программирования"
echo Погожев Сергей Владимирович > %name%\"Основы программирования"\readme.txt
echo Начало занятий: %DATE% >> %name%\"Основы программирования"\readme.txt

md %name%\"Дискретная математика"
echo Максимов Алексей Юрьевич > %name%\"Дискретная математика"\readme.txt
echo Начало занятий: %DATE% >> %name%\"Дискретная математика"\readme.txt

copy /D /Y op.bat %name%
copy /D /Y algem.bat %name%

cd %name%