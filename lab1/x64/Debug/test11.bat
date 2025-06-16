@echo off
echo Creating a test file...
echo text string 1 > test_file.txt
echo text string 2 >> test_file.txt
echo text string 3 >> test_file.txt
echo text string 4 >> test_file.txt
echo text string 5 >> test_file.txt
echo.
echo Running a program to search for a string "string 3"...
C:\Users\sergeygusev\Desktop\vs\lab1\x64\Debug\lab1.exe test_file.txt "string 3"

@echo off
echo Creating a test file...
echo Test string 1 > test_file.txt
echo Test string 2 >> test_file.txt
echo Test string 4 >> test_file.txt
echo Test string 5 >> test_file.txt
echo.
echo Running a program to search for a string "string 3"...
C:\Users\sergeygusev\Desktop\vs\lab1\x64\Debug\lab1.exe test_file.txt "строка 3"

@echo off
echo Running a program without arguments...
C:\Users\sergeygusev\Desktop\vs\lab1\x64\Debug\lab1.exe

@echo off
echo Running a program with the wrong number of arguments...
C:\Users\sergeygusev\Desktop\vs\lab1\x64\Debug\lab1.exe