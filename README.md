# VSCode project skeleton for raylib c++ projects

based on [the official template](https://github.com/raysan5/raylib/tree/master/projects/VSCode)

### Dependencies

- [Raylib](https://www.raylib.com/)
- [VSCode](https://code.visualstudio.com/)
- VSCode C/C++ Extension

## Contents
- VSCode build, debug, and Intellisense definitions
- MinGW raylib Makefile lightly edited to use c++
- Small example game

## Changing compiler and raylib path
By default, the project is set up to use a chocolatey install of MinGW and a relative path for raylib. To Update these values, change `mingwBinPath` and `raylibPath` in [settings.json](.vscode/settings.json).

To fix Intellisense, the `compilerPath` and `includePath` of [c_cpp_properties.json](.vscode/settings.json) must be updated

## Getting Raylib to work on Windows
The provided makefile is set up to use [the raylib source](https://github.com/raysan5/raylib/releases/tag/4.5.0)

If you recieve the following error: `ld.exe cannot find -lraylib`, you need to [compile your raylib source directory into a library file.](https://github.com/raysan5/raylib/wiki/Working-on-Windows#build-raylib-using-make)