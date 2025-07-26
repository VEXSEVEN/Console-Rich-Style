![Logo](3.png)

# crs.h - Console Rich Style

`crs.h` is a lightweight, header-only C++ library that provides advanced console text styling capabilities using ANSI escape sequences. Designed for developers targeting MSYS2, MinGW, Linux, and other Unix-like terminals, it offers an easy and flexible way to format console output with:

- **Text effects:** bold, italic, underline, strikethrough, reset
- **24-bit RGB color support:** foreground and background colors specified by RGB hex values
- **Utility functions:** easy conversion from RGB to ANSI escape codes
- **Namespace encapsulation** to avoid conflicts

---

## Table of Contents

1. [Features](#features)
2. [Installation](#installation)
3. [Usage](#usage)
4. [Example Code](#example-code)
5. [Integration with MSYS2 / MinGW](#integration-with-msys2--mingw)
6. [Compilation Instructions](#compilation-instructions)
7. [Notes &amp; Best Practices](#notes--best-practices)
8. [Troubleshooting](#troubleshooting)
9. [License](#license)
10. [Credits](#credits)

---

## Features

- **Bold, Italic, Underline, Strikethrough** text styles
- Full support for **24-bit true color** with RGB hex codes
- Easy to use inline constants for common colors and styles
- `hexColor(r, g, b)` utility function returning ANSI code string
- Fully header-only, no dependencies
- Compatible with any ANSI-compliant terminal (MSYS2, MinGW, Linux, macOS, Windows 10+ terminals)

---

## Installation

### Prerequisites

- A C++ compiler supporting C++11 or later (e.g., `g++` from MinGW/MSYS2)
- MSYS2 or MinGW environment (Windows) or Unix-like terminal

### Steps

1. Download or copy the `crs.h` file.
2. Place `crs.h` in your project directory **or** in the global include directory:
   ```
   C:\msys64\mingw64\include\crs.h
   ```
3. Include it in your C++ source files using angle brackets:
   ```cpp
   #include <crs.h>
   ```

---

## Usage

Use the `ConsoleStyle` namespace for convenient access to styles and colors:

- Constants like `BOLD`, `ITALIC`, `RED`, `RESET`
- Use `hexColor(int r, int g, int b)` for custom RGB colors
- Combine multiple styles by concatenation

Example:

```cpp
std::cout << BOLD << RED << "Bold Red Text" << RESET << std::endl;
std::cout << ITALIC << hexColor(128, 0, 128) << "Italic Purple Text" << RESET << std::endl;
```

---

## Example Code

```cpp
#include <iostream>
#include <crs.h>

int main() {
    using namespace ConsoleStyle;

    std::cout << BOLD << RED << "This is bold red text" << RESET << std::endl;
    std::cout << ITALIC << GREEN << "This is italic green text" << RESET << std::endl;
    std::cout << UNDERLINE << BLUE << "This is underlined blue text" << RESET << std::endl;

    // Custom orange color using RGB
    std::string orange = hexColor(255, 165, 0);
    std::cout << orange << "This is orange text using RGB" << RESET << std::endl;

    return 0;
}
```

---

## Integration with MSYS2 / MinGW

- Place `crs.h` in the global include directory for easy access across projects:
  ```
  C:\msys64\mingw64\include  ```  
  ```
- Alternatively, keep it local to your project folder and include with quotes:
  ```cpp
  #include "crs.h"
  ```
- Make sure your compiler uses the correct include paths (MSYS2 does by default).

---

## Compilation Instructions

Use `g++` or `clang++` in MSYS2 or MinGW shell:

```bash
g++ main.cpp -o styledApp
./styledApp
```

For Windows CMD, make sure your environment variables include the compiler path.

---

## Notes & Best Practices

- ANSI escape sequences may not render correctly on all Windows terminals; Windows 10+ default console supports them well.
- For older Windows, consider using terminals like ConEmu, Cmder, or Windows Terminal.
- Combine styles carefully, reset at line end to avoid bleeding styles.
- Use `std::string` when concatenating style codes with text.
- Avoid mixing different output streams without resetting styles.

---

## Troubleshooting

- **No colors or styles shown?**Make sure your terminal supports ANSI escape codes. On Windows, enable virtual terminal processing or use a modern terminal emulator.
- **Garbled characters?**Reset style after output. Check for stray escape codes.
- **Compiler errors including `crs.h`?**
  Verify header file is in the correct include path. Check spelling and include syntax.

---

## License

This project is released under the MIT License. You may use, modify, and distribute freely.

---

## Credits

Created by Dominik [VEX7] . Inspired by ANSI escape code standards and terminal styling conventions.

---

## Support me by click on the star

---

### Thank you for using `crs.h` for beautiful console output!
