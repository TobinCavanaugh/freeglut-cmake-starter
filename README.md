# freeglut-cmake-starter

FreeGLUT project template using CMake.

## Index

* [Prerequisites](#prerequisites)
* [Cloning the repository](#cloning)
* [Generating the project](#generate-project)
  * [Code::Blocks](#codeblocks)
  * [Visual Studio](#visual-studio)

## Prerequisites

To use project template, you need to install the following:

- [Git](https://git-scm.com/downloads)
- [CMake](https://cmake.org/download/) (minimum version of 3.25.1)

## Cloning the repository

In a terminal with Git installed, clone the repository by typing in the following command in a directory where you want your project:

```bash
$ git clone --recurse-submodules https://github.com/dante1130/freeglut-cmake-starter
```

## Generating the project

CMake generates the project files for a subset of buildsystem that you may want to use.

I'll use Code::Blocks and Visual Studio as an example.

See here for a list of all CMake generators: https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html

### Code::Blocks

To generate a Code::Blocks project, run the following command:

```bash
$ cmake -S . -B build -G "CodeBlocks - MinGW Makefiles"
```

In the `build` directory, you will see that the Code::Blocks project has been generated.

Note: This generates a Code::Blocks project with **MinGW Makefiles**, if you wish to use other Makefiles or buildsystems please refer to the [list of CMake generators for Code::Blocks](https://cmake.org/cmake/help/latest/generator/CodeBlocks.html).

You may also want to consider to pass in the compiler that you want to use. If for example, we want to use the `gcc` compiler:

```bash
$ cmake -S . -B build -G "CodeBlocks - MinGW Makefiles" -D CMAKE_C_COMPILER=gcc
```

Note: You will need to ensure that your PATH contains `gcc`.

## Visual Studio

To generate a Visual Studio project, you will need to tell CMake what version of Visual Studio you will want to use.

From the [CMake generators page](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html#id14), you can see the list of Visual Studio generators.

If for example, we want to generate a project for Visual Studio 2022, run the following command:

```bash
$ cmake -S . -B build -G "Visual Studio 17 2022"
```

In the `build` directory, you will see that the Visual Studio 2022 project has been generated.
