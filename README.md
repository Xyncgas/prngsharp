# prngsharp

C++11 Mersenne-Twister pseudo random number generator available in .NET on
Windows and Mono (Mac OSX, Linux)

# usage

Get the package on [nuget.org](https://www.nuget.org/packages/sharpPRNG/):

```nuget install sharpPRNG```

# how to build

## C++11 library

### Unix
there is a [project file](prngCpp/prngCpp.cbp) for [CodeBlocks](http://www.codeblocks.org/) which builds the C++ library
"libprngCpp.so"

### Windows
a Visual Studio [project file](prngCpp/w32/w32.sln) is available.


## C# assembly

### Unix
there is a [project file](sharpPRNG/sharpPRNG.sln) for using [MonoDevelop](http://www.monodevelop.com/) to build the assembly

### Windows
the same project file can be used in Visual Studio.
