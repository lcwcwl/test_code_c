@echo off

set BUILD_DIR=build_vs2017
echo current use vs2017
set CMAKE_FLAGS=Visual Studio 15 2017 Win64

if not exist %BUILD_DIR% md %BUILD_DIR%

cd %BUILD_DIR%

cmake -G "%CMAKE_FLAGS%" ..

cd ..

pause