#cmake -G "Visual Studio 16 2019" -A Win32 -D  CMAKE_INSTALL_PREFIX=c:\temp\yart -D CMAKE_PREFIX_PATH="C:\Qt\Qt-5.15.2\lib\cmake" ..
cmake_minimum_required(VERSION 3.10)

project(YART
    LANGUAGES CXX
    VERSION 0.1.1
)

add_subdirectory(src)
add_subdirectory(examples)
