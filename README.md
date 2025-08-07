![Logo](4.png)
![Logo](5.png)

# crs.h - Console Rich Style

`crs.h` is a lightweight, header-only C++ library that provides advanced console text styling capabilities using ANSI escape sequences. Designed for developers targeting MSYS2, MinGW, Linux, and other Unix-like terminals, it offers an easy and flexible way to format console output with:

- **Text effects:** bold, italic, underline, strikethrough, reset
- **24-bit RGB color support:** foreground and background colors specified by RGB hex values
- **No namespace required** – all functions are global for simplicity
- **Utility functions** for terminal formatting

---

## Table of Contents

1. [Features](#features)
2. [Installation](#installation)
3. [Usage](#usage)
4. [Example Code](#example-code)
5. [Integration with MSYS2 / MinGW](#integration-with-msys2--mingw)
6. [Compilation Instructions](#compilation-instructions)
7. [Notes & Best Practices](#notes--best-practices)
8. [Troubleshooting](#troubleshooting)
9. [License](#license)
10. [Credits](#credits)

---

## ✅ Features

### 🎨 Color Controls
- `setTextColor(hex)` – Set text color (e.g., `#ff0000`)
- `setBackgroundColor(hex)` – Set background color (e.g., `#000000`)
- `resetColors()` – Reset both foreground and background

### 🖋️ Text Formatting
- `setBold()` / `unsetBold()`
- `setItalic()` / `unsetItalic()`
- `setUnderline()` / `unsetUnderline()`
- `setReverse()` / `unsetReverse()`
- `setStrikethrough()` / `unsetStrikethrough()`

### ⚠️ Deprecated
- `printGradientText(...)` – was used for gradients, but is now **deprecated** and non-functional.

---

### 📁 Installation & Usage Guide

This guide will show you how to "install" your CRS library so you can use it easily in any MinGW C++ project with VS Code.

## 🛠️ Part 1: Install CRS as a System Library (One-Time Setup)

These steps make your CRS library available to all your MinGW C++ projects.

Prepare crs.h and crs.cpp:
Place your crs.h (containing only function declarations) and crs.cpp (containing function implementations) files in a temporary working directory (e.g., C:\temp\crs_build).

Compile crs.cpp into an object file:
Open your terminal (MSYS2, Git Bash, or CMD/PowerShell if g++ is in your PATH), navigate to your temporary directory, and run:
Bash

g++ -c crs.cpp -o crs.o -std=c++17

Create the static library libcrs.a:
In the same directory, run:
Bash

ar rcs libcrs.a crs.o

Copy crs.h to MinGW's include directory:
Bash

copy crs.h C:\msys64\mingw64\include\

(If using MSYS2/Git Bash, you can use cp crs.h /mingw64/include/)

Copy libcrs.a to MinGW's lib directory:
Bash

    copy libcrs.a C:\msys64\mingw64\lib\

(If using MSYS2/Git Bash, you can use cp libcrs.a /mingw64/lib/)

## 🖥️ Part 2: Configure VS Code for IntelliSense (One-Time Setup for MinGW)

This ensures VS Code's IntelliSense (for autocompletion, error checking) can find crs.h.

Open VS Code Command Palette: Press Ctrl+Shift+P.

Select C/C++: Edit Configurations (UI).

    Under "Include path", click "+ Add Folder".

Add the path to your MinGW's include directory:

    C:\msys64\mingw64\include

You'll likely already have ${workspaceFolder}/** and other paths. Just add this one.

    Save the c_cpp_properties.json file.

Reload VS Code (or Ctrl+Shift+P and "Reload Window") for changes to take effect.

## 🚀 Part 3: Create a VS Code Project Template (Optional but Recommended)

This step streamlines creating new projects, so you don't have to edit tasks.json every time.

Create a template folder: Make a new folder, for example, C:\Users\YourUser\Documents\CppProjectTemplate.

Create .vscode/tasks.json:
Inside this template folder, create a .vscode subfolder, and then a tasks.json file inside .vscode. Paste the following content into tasks.json:
JSON


    {
        "tasks": [
            {
                "type": "cppbuild",
                "label": "Build C++ Project (CRS & C++17)",
                "command": "C:\\msys64\\mingw64\\bin\\g++.exe",
                "args": [
                    "-fdiagnostics-color=always",
                    "-g",
                    "${file}",
                    "-o",
                    "${fileDirname}\\${fileBasenameNoExtension}.exe",
                    "-std=c++17",
                    "-lcrs"
                ],
                "options": {
                    "cwd": "${fileDirname}"
                },
                "problemMatcher": [
                    "$gcc"
                ],
                "group": {
                    "kind": "build",
                    "isDefault": true
                },
                "detail": "General build task for C++ projects using CRS library and C++17."
            }
        ],
        "version": "2.0.0"
    }

## ⚡ Part 4: Use CRS in Your Projects (For Every Project)

Now, when you want to start a new C++ project that uses CRS, follow these simple steps:

Start a new project:
Copy your CppProjectTemplate folder.
Paste and rename it to your new project's name (e.g., MyNewAwesomeApp).
Open this new project folder in VS Code (File > Open Folder...).
Include crs.h in your C++ code:
In any .cpp file where you want to use CRS functions (e.g., main.cpp), add:
C++

    #include <crs.h> // Use angle brackets for system-installed headers

Compile your project:
Open the .cpp file you want to compile in VS Code.
Press Ctrl+Shift+B (or Cmd+Shift+B on macOS).
VS Code will automatically use the tasks.json from your project folder to compile and link your application with CRS.
    

---

## 🧪 Usage & Experimental

```cpp
#include "crs.h"
#include <iostream>

int main() {
    setTextColor("00ff00");
    setBackgroundColor("000000");
    setBold();
    std::cout << "Bold green on black" << std::endl;

    unsetBold();
    resetColors();

    setUnderline();
    std::cout << "Underlined text" << std::endl;
    unsetUnderline();

    return 0;
}
```

---

## 🖥️ Integration with MSYS2 / MinGW

### Global Usage
Copy the file into:
```bash
C:\msys64\mingw64\include
```
Then use:
```cpp
#include <crs.h>
```

### Local Usage
Keep `crs.h` in your project and include it directly:
```cpp
#include "crs.h"
```

---

## ⚙️ Compilation Instructions

Compile in MSYS2 / MinGW like this:
```bash
g++ main.cpp -o app
./app
```

---

## 📌 Notes & Best Practices

- Use ANSI-compatible terminals (Windows Terminal, macOS Terminal, Linux).
- Always reset styles with `resetColors()` to avoid style bleed.
- Avoid mixing `std::cerr` and `std::cout` without resetting styles.

---

## ❓ Troubleshooting

- **Colors not working?** Terminal might not support ANSI. Try Windows Terminal.
- **Escape codes visible as text?** Ensure output encoding and terminal compatibility.
- **Header not found?** Confirm that `crs.h` is in the include path.

---

## 📄 License

MIT License — free to use and modify.

---

## ✨ Credits

Created by **Dominik [VEX7]**  
Inspired by UNIX and ANSI escape standards.

---

## 🙏 Support

If you enjoy using `crs.h`, give it a ⭐ on GitHub!

---

### Thank you for using `crs.h` for beautiful console output!
