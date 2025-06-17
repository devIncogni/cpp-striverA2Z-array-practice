# C++ Template Project Repository

## Overview
This repository provides a clean and efficient C++ project setup using:
- CMake for build configuration.
- Clang++ with C++23 standard.
- Code Runner extension for quick single-file testing.
- LLDB (via code-lldb extension) for integrated debugging in Visual Studio Code.

## Features
- **CMake Build System:** Supports multi-file projects and maintains build artifacts in a separate directory.
- **Clang++ with C++23:** Enforces modern standard with colored diagnostics.
- **LLDB Debugging:** Integrated terminal-based debugging using `code-lldb`.
- **Code Runner Support:** Enables fast compilation and execution of single files, useful for testing snippets or individual modules.

## Setup
1. Clone this repository.
2. Open the folder in Visual Studio Code.
3. Install the following extensions:
   - `ms-vscode.cmake-tools`
   - `vadimcn.vscode-lldb`
   - `formulahendry.code-runner` (optional for quick runs)
4. Press **Ctrl+Shift+B** to build the project.
5. Press **F5** to start debugging.
6. Use Code Runner (`Ctrl+Alt+N`) for quick testing of single files.

## Notes
- **CMake is configured to use C++23** for consistency and future-proofing.
- **Executables are placed in `bin/`**; intermediates in `build/`.
- **Quick single-file builds with Code Runner** use clang++ and are independent of the full project build.
- This template encourages clean separation of source, build, and output files, suitable for both small experiments and large-scale projects.
