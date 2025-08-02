/*
CRS - Console Rich Styles
Version 1.0
Created on 2025-07-26
Author: Dominik (VEX7)

copyright (c) 2025 Dominik (VEX7)

This file is part of the CCS library, which provides functions for setting text and background colors, text styles, and printing gradient text in the console.
This file is licensed under the MIT License.
You can use, modify, and distribute this code freely, but please keep this header intact
and give credit where it's due.
This file contains the function declarations for the CRS library.
It includes these functions:
- setTextColor: Sets the text color using a hexadecimal color code (can include # prefix).
- setBackgroundColor: Sets the background color using a hexadecimal color code (can include # prefix).
- resetColors: Resets the text and background colors to default.
- setBold: Sets the text to bold.
- unsetBold: Unsets the bold text style.
- setItalic: Sets the text to italic.
- unsetItalic: Unsets the italic text style.
- setUnderline: Sets the text to underlined.
- unsetUnderline: Unsets the underlined text style.
- setReverse: Sets the text and background colors to be reversed.
- unsetReverse: Unsets the reversed text and background colors.
- setStrikethrough: Sets the text to strikethrough.
- unsetStrikethrough: Unsets the strikethrough text style.
- printGradientText: Prints text with a gradient effect between two specified colors.
*/

#ifndef CRS_H
#define CRS_H

#include <string>

// Declarații de funcții pentru stilizarea consolei
void setTextColor(const std::string& hexColor);
void setBackgroundColor(const std::string& hexColor);
void resetColors();

void setBold();
void unsetBold();
void setItalic();
void unsetItalic();
void setUnderline();
void unsetUnderline();
void setReverse();
void unsetReverse();
void setStrikethrough();
void unsetStrikethrough();

// Funcție pentru a printa text cu un gradient de culori
void printGradientText(const std::string& text, const std::string& startHex, const std::string& endHex);

// Namespace pentru culori predefinite
namespace Colors {
    const std::string RED = "FF0000";
    const std::string GREEN = "00FF00";
    const std::string BLUE = "0000FF";
    const std::string YELLOW = "FFFF00";
    const std::string MAGENTA = "FF00FF";
    const std::string CYAN = "00FFFF";
    const std::string BLACK = "000000";
    const std::string WHITE = "FFFFFF";
    const std::string ORANGE = "FFA500";
    const std::string PURPLE = "800080";
    const std::string GRAY = "808080";
    const std::string LIGHT_GRAY = "D3D3D3";
    const std::string DARK_RED = "8B0000";
    const std::string LIGHT_GREEN = "90EE90";
    const std::string LIGHT_BLUE = "ADD8E6";
    const std::string LIGHT_YELLOW = "FFFFE0";
    const std::string LIGHT_MAGENTA = "FFB6C1";
    const std::string LIGHT_CYAN = "E0FFFF";
    const std::string LIGHT_ORANGE = "FFA07A";
    const std::string LIGHT_PURPLE = "DDA0DD";
    const std::string LIGHT_BLACK = "696969";
    const std::string LIGHT_WHITE = "F5F5F5";
    const std::string LIGHT_BLUE_GRAY = "B0C4DE";
    const std::string LIGHT_BROWN = "A52A2A";
    const std::string LIGHT_PINK = "FF69B4";
    const std::string LIGHT_TEAL = "20B2AA";
    const std::string LIGHT_GOLD = "FFD700";
    const std::string LIGHT_SILVER = "C0C0C0";
    const std::string LIGHT_LIME = "00FF7F";
    const std::string LIGHT_TURQUOISE = "AFEEEE";
    const std::string LIGHT_PEACH = "FFDAB9";
    const std::string LIGHT_CORAL = "FF7F50";
}

#endif // CRS_H