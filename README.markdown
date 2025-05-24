# 🖥️🔒 SecureBank UI: C++ Console Display Module 💳
_A C++ class providing a console-based user interface for a bank system, featuring screen management, colored output, and menu navigation with cross-platform considerations._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B%2011%2B-blue.svg)](https://isocpp.org/)
[![Platform: Windows (Full) / Cross-platform (Basic)](https://img.shields.io/badge/Platform-Windows%20%7C%20Cross--platform-lightgrey.svg)]()

## 📋 Table of Contents
1.  [Overview](#-overview)
2.  [Key Features & Display Functions](#-key-features--display-functions)
3.  [Screenshots (Conceptual)](#-screenshots-conceptual)
4.  [System Requirements](#-system-requirements)
5.  [Core Header (`Display.hpp`)](#-core-header-displayhpp)
6.  [Integration and Setup](#️-integration-and-setup)
7.  [Usage in a Bank System](#️-usage-in-a-bank-system)
8.  [File Structure](#-file-structure)
9.  [Technical Notes](#-technical-notes)
10. [Contributing](#-contributing)
11. [License](#-license)
12. [Contact](#-contact)

## 📄 Overview

The **SecureBank UI Display Module**, authored by Adrian Lesniak, is a C++ class (`Display`) designed to provide a clean, interactive, and visually enhanced console-based user interface for a banking system application. It encapsulates functionalities for managing screen output, including clearing the screen, displaying text in various colors (primarily for Windows), rendering an ASCII logo, and presenting different system states like welcome messages, PIN prompts, main menus, PIN change interfaces, and success/error notifications. The module also handles validated user input for menu choices and includes considerations for basic cross-platform compatibility regarding screen clearing and color output.

## ✨ Key Features & Display Functions

The `Display` class offers a suite of methods to manage the console UI:

*   🎨 **Visual Presentation**:
    *   `drawSimpleLogo`: Renders a distinct ASCII "SECURE BANK" logo.
    *   `showWelcome`: Displays the ASCII logo and a welcoming message to the user.
*   🔒 **User Interaction Prompts**:
    *   `showPinPrompt`: Presents a prompt for the user to enter their PIN.
    *   `showChangePinMenu`: Displays an interface prompting the user to enter and confirm a new 4-digit PIN.
*   ⚙️ **Menu Navigation**:
    *   `showMainMenu`: Displays the main banking menu with options such as:
        1.  Check Balance
        2.  Change PIN
        3.  Logout
    *   `getMenuChoice`: Securely retrieves and validates user input (typically 1-3) for menu selections, handling non-numeric or out-of-range inputs.
*   💬 **Feedback Messages**:
    *   `showSuccess`: Displays a success message (e.g., "Access Granted!", "PIN Changed Successfully!").
    *   `showError`: Shows an error message, incorporating a custom string to specify the nature of the error (e.g., "✗ Error: Invalid PIN.").
*   🖥️ **Console Management Utilities**:
    *   `clearScreen`: Clears the console window using platform-specific commands (`cls` for Windows, `clear` for Linux/macOS).
    *   `setTextColor` / `resetColor`: Manages console text colors (e.g., yellow for the logo, light cyan for menus) primarily using Windows console API. Non-Windows systems will typically see default console colors.

## 🖼️ Screenshots (Conceptual)

**Coming soon!**

_This section would ideally show conceptual mockups or actual screenshots if integrated into a running bank system, demonstrating: the welcome screen with logo, PIN prompt, main menu, PIN change screen, and examples of success/error messages._

## ⚙️ System Requirements

*   **Operating System**:
    *   **Windows**: Recommended for full functionality, including colored text output via `<windows.h>`.
    *   **Linux/macOS**: Basic functionality with default console colors; screen clearing should work via `system("clear")`.
*   **C++ Compiler**: A C++ compiler supporting C++11 or later (e.g., g++, clang++, MSVC).
*   **Standard C++ Libraries**: `<iostream>`, `<string>`, `<vector>` (if used internally), `<limits>`, `<iomanip>`.
*   Windows-specific library: `<windows.h>` (conditionally included for color and console functions).
*   📄 **`Display.hpp` Header File (User-Provided/Module Core)**: This project component **requires** a header file named `Display.hpp`. This file must contain the declaration of the `Display` class and its member functions/variables.

## 🧩 Core Header (`Display.hpp`)

The `Display.hpp` file is essential for this module. It should declare the `Display` class, for example:

```cpp
#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <iostream>
#include <string>
#include <vector> // If used for menu items, etc.
#include <limits>   // For std::numeric_limits
#include <iomanip>  // For std::setw, etc.

#ifdef _WIN32
#include <windows.h> // For Windows-specific console functions
#endif

class Display {
public:
    // Constructor (if needed)
    Display();

    // Core UI Methods
    void showWelcome() const;
    void showPinPrompt(const std::string& message = "Enter PIN:") const;
    void showSuccess(const std::string& message) const;
    void showError(const std::string& errorMessage) const;
    void showMainMenu() const;
    void showChangePinMenu() const;
    int getMenuChoice(int minOption, int maxOption) const; // Validates input

    // Console Management
    void clearScreen() const;

private:
    // Color constants (Windows-specific values)
    // Could be an enum or static const int
    // Example:
    // static const int COLOR_YELLOW = 14;
    // static const int COLOR_LIGHT_CYAN = 11;
    // static const int COLOR_DEFAULT = 7;

    void setTextColor(int color) const; // Windows-specific
    void resetColor() const;        // Resets to default, Windows-specific
    void drawSimpleLogo() const;    // Renders ASCII logo
};

#endif // DISPLAY_HPP
```

*The implementation of these methods would typically reside in `Display.cpp`.*

## 🛠️ Integration and Setup

This `Display` class is intended to be used as a module within a larger C++ banking system application.

1.  **Obtain Files**:
    *   Ensure you have `Display.hpp` (containing the class declaration) and `Display.cpp` (containing the class implementation).

2.  **Include in Your Project**:
    *   Add `Display.hpp` and `Display.cpp` to your banking system project.
    *   Include `Display.hpp` in your main application file or other relevant modules where UI calls are needed:
    ```cpp
    #include "Display.hpp"
    // ... other includes ...

    int main() {
        Display consoleDisplay; // Create an instance of the Display class
        // ... your bank system logic ...
        consoleDisplay.showWelcome();
        // ...
        return 0;
    }
    ```

3.  **Compile Your Project**:
    When compiling your main banking application, ensure `Display.cpp` is included in the compilation command along with your other source files.
    **Example using g++:**
    ```bash
    g++ main_bank_app.cpp Display.cpp BankLogic.cpp User.cpp -o bank_system -std=c++11
    ```
    *(Adjust command based on your project's actual file names and structure).*

4.  **Run the Banking Application**:
    *   On Windows: `.\bank_system.exe`
    *   On Linux/macOS: `./bank_system`

## 💡 Usage in a Bank System

The `Display` class provides methods to be called at various points in your banking application's flow:

*   **Start-up**: Call `display.showWelcome();`
*   **Login**: Call `display.showPinPrompt();` to get PIN input. Use `display.showSuccess()` or `display.showError()` for feedback.
*   **Main Menu**: After successful login, call `display.showMainMenu();` and use `display.getMenuChoice()` to get user selection.
*   **PIN Change**: Call `display.showChangePinMenu();` for the new PIN interface.
*   **General UI**: Use `display.clearScreen()` before showing new "pages" or menus. `setTextColor()` can be used for emphasis if needed (Windows).

**Example Interaction Flow:**
```cpp
// In your main application logic
Display consoleUI;
consoleUI.showWelcome();

// --- PIN Prompt Logic ---
// std::string pin = getPinFromUser(); // Assuming you have a separate function for secure PIN input
// if (bankLogic.validatePin(currentUser, pin)) { // Example
//    consoleUI.showSuccess("Access Granted!");
//    consoleUI.showMainMenu();
//    int choice = consoleUI.getMenuChoice(1, 3);
//    // ... handle choice ...
// } else {
//    consoleUI.showError("Invalid PIN.");
// }
```
## 🗂️ File Structure

For this specific module:

*   `Display.cpp`: Source file containing the implementation of the `Display` class methods.
*   `Display.hpp`: Header file containing the declaration of the `Display` class.
*   `README.md`: This documentation file (describing the `Display` module).

When integrated into a larger project, these files would be part of that project's source directory.

## 📝 Technical Notes

*   **Windows-Specific Enhancements**: Colored text output (via `setTextColor`/`resetColor` using `SetConsoleTextAttribute`) and potentially other Windows API calls are conditionally compiled using `#ifdef _WIN32`. On non-Windows systems, these calls are typically omitted, resulting in standard monochrome console output.
*   **Cross-Platform `clearScreen`**: Achieved by using `system("cls")` on Windows and `system("clear")` on other POSIX-compliant systems.
*   **Input Validation**: `getMenuChoice` includes logic to handle non-numeric input and ensure the choice is within the valid range, clearing `std::cin` error states and ignoring bad input.
*   **Modularity**: The `Display` class encapsulates all UI-related concerns, promoting separation of concerns from the core banking logic.
*   **Minimal Dependencies**: Primarily relies on standard C++ libraries, with `<windows.h>` being the main platform-specific dependency for enhanced features.

## 🤝 Contributing

While this is a module, contributions to improve its functionality, cross-platform support, or add new display features are welcome, especially if it's part of a larger open-source banking system project.

1.  Fork the repository (or the main project repository where this module resides).
2.  Create a new branch for your feature (`git checkout -b feature/UIEnhancement`).
3.  Make your changes to `Display.hpp` and `Display.cpp`.
4.  Commit your changes (`git commit -m 'Enhance: Add new display feature'`).
5.  Push to the branch (`git push origin feature/UIEnhancement`).
6.  Open a Pull Request.

Please ensure your code is well-commented and maintains a clean separation of UI concerns.

## 📃 License

This module is licensed under the **MIT License**.
(If part of a larger project, it would typically inherit or be compatible with the main project's license. If this `README.md` is for the module itself, then the MIT license applies to these specific files.)

## 📧 Contact

Module created by **Adrian Lesniak**.
For questions or feedback regarding this `Display` module, please open an issue on the GitHub repository where it's hosted or contact the repository owner.

---
✨ _Crafting clear and engaging console interfaces for secure applications._
