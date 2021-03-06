rem @echo off

rem set PLATFRM="x86"
set PLATFRM="Any CPU"

rem the native C++ library is built for 64-bit platform
msbuild /t:clean /p:Configuration="Debug" /p:Platform="x64" pprngCpp\w32\w32.sln
msbuild /p:Configuration="Debug" /p:Platform="x64" prngCpp\w32\w32.sln

sn -k sharpPRNG/sharpPRNG.snk
msbuild /t:clean /p:Configuration="Debug" /p:Platform=%PLATFRM% sharpPRNG\sharpPRNG.sln
msbuild /p:Configuration="Debug" /p:Platform=%PLATFRM% sharpPRNG\sharpPRNG.sln

copy prngCpp\w32\Debug\prngCpp.dll  sharpPRNG\testSharpPRNG\bin\Debug\
sharpPRNG\testSharpPRNG\bin\Debug\testSharpPRNG.exe

