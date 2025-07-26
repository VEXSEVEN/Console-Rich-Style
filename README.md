![Logo](3.png)

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

## 📁 Installation

### Prerequisites
- C++11 compatible compiler (e.g., `g++` or `clang++`)
- MSYS2 / MinGW or ANSI-compatible terminal

### Steps
1. Copy `crs.h` to your project or:
   ```bash
   C:\msys64\mingw64\include\crs.h
   ```
2. Include it in your code:
   ```cpp
   #include "crs.h"
   ```

---

## 🧪 Usage

```cpp
#include "crs.h"
#include <iostream>

int main() {
    setTextColor("#00ff00");
    setBackgroundColor("#000000");
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
