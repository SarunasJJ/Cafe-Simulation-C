@echo off
if .%USERDOMAIN% == .LAPTOP-K6JE6M4N goto :LAPTOP-K6JE6M4N
Rem MIF kompiuteris
path "C:\Program Files (x86)\Dev-Cpp\MinGW64\bin\;%path"
mingw32-make.exe
goto :toliau

:LAPTOP-K6JE6M4N
make

:toliau
test.exe input.txt

pause