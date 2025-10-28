@echo off
call setEnv.bat
"D:\Software\MATLAB\R2022b\toolbox\shared\coder\ninja\win64\ninja.exe" -t compdb cc cxx cudac > compile_commands.json
"D:\Software\MATLAB\R2022b\toolbox\shared\coder\ninja\win64\ninja.exe" -v %*
