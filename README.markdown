# 🏦🔒 PUN SecureBank: Console Mini-Bank System

_A C++ console application simulating a secure mini-bank system with PIN authentication, menu navigation, and robust error handling. Features a modular UI via the `Display` class and a main control flow managed by `BankSystem`._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B%2011%2B-blue.svg)](https://isocpp.org/)
[![Platform: Windows (Full) / Cross-platform (Basic)](https://img.shields.io/badge/Platform-Windows%20%7C%20Cross--platform-lightgrey.svg)]()

## 📋 Table of Contents
1. [Overview](#-overview)
2. [Key Features](#-key-features)
3. [Screenshots (Conceptual)](#-screenshots-conceptual)
4. [System Requirements](#-system-requirements)
5. [Core Components](#-core-components)
6. [Integration and Setup](#️-integration-and-setup)
7. [Usage Example](#️-usage-example)
8. [File Structure](#-file-structure)
9. [Technical Notes](#-technical-notes)
10. [Contributing](#-contributing)
11. [License](#-license)
12. [Contact](#-contact)

## 📄 Overview

The **SecureBank Mini-Bank System**, authored by Adrian Lesniak, is a C++ console application that simulates a simple banking environment. It features secure PIN entry, a main menu for banking operations, and robust error handling. The UI is managed by a dedicated `Display` class, while the application flow and logic are encapsulated in the `BankSystem` class.

The entry point (`main.cpp`) creates a `BankSystem` object and runs the application, handling any exceptions gracefully.

![Demo GIF](screenshots/1.gif)

## ✨ Key Features

* **Secure PIN Authentication**: Prompts for and validates user PINs.
* **Menu Navigation**: Main menu with options (e.g., check balance, change PIN, logout).
* **User Feedback**: Success and error messages with colored output (on Windows).
* **Screen Management**: Clears and redraws screens for a clean UI.
* **Robust Input Handling**: Validates menu choices and handles invalid input.
* **Cross-Platform Considerations**: Works on Windows (full features) and Linux/macOS (basic).

## 🖼️ Screenshots (Conceptual)

_Example screens: welcome, PIN prompt, main menu, PIN change, success/error messages._

<p align="center">
  <img src="screenshots\1.jpg" width="300"/>
  <img src="screenshots\2.jpg" width="300"/>
  <img src="screenshots\3.jpg" width="300"/>
  <img src="screenshots\4.jpg" width="300"/>
  <img src="screenshots\5.jpg" width="300"/>
  <img src="screenshots\6.jpg" width="300"/>
  <img src="screenshots\7.jpg" width="300"/>
  <img src="screenshots\8.jpg" width="300"/>
  <img src="screenshots\9.jpg" width="300"/>
  <img src="screenshots\11.jpg" width="300"/>
</p>

## ⚙️ System Requirements

* **Operating System**:
    * **Windows**: Full functionality (colored output).
    * **Linux/macOS**: Basic functionality (default colors).
* **C++ Compiler**: C++11 or later.
* **Standard Libraries**: `<iostream>`, `<string>`, `<limits>`, `<iomanip>`.
* **Windows-specific**: `<windows.h>` (for color, optional).
* **Project Files**: `main.cpp`, `BankSystem.hpp/cpp`, `Display.hpp/cpp`.

## 🧩 Core Components

### `main.cpp`

The entry point. Handles application startup and error reporting:

```cpp
#include <iostream>
#include <stdexcept>
#include "BankSystem.hpp"

int main() {
    try {
        BankSystem bank;
        bank.run();
    }
    catch (const std::exception& e) {
        std::cerr << "\nError: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
```

### `BankSystem` Class

Encapsulates the main banking logic and uses the `Display` class for UI. Responsible for authentication, menu flow, and user actions.

### `Display` Class

Handles all console UI: screen clearing, colored output, logo, menus, and messages. See [Display Module Documentation](#-display-module) for details.

## 🛠️ Integration and Setup

1. **Obtain Files**: Ensure you have `main.cpp`, `BankSystem.hpp/cpp`, `Display.hpp/cpp`.
2. **Include in Project**: Add all files to your project directory.
3. **Compile**: Example (g++):
    ```bash
    g++ main.cpp BankSystem.cpp Display.cpp -o minibank -std=c++11
    ```
4. **Run**:
    * Windows: `.\minibank.exe`
    * Linux/macOS: `./minibank`

## 💡 Usage Example

The main application flow is managed by `BankSystem`:

```cpp
#include "BankSystem.hpp"

int main() {
    try {
        BankSystem bank;
        bank.run(); // Handles login, menu, and actions
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
```

Within `BankSystem`, the `Display` class is used for all UI interactions:

```cpp
// Example inside BankSystem methods
display.showWelcome();
display.showPinPrompt();
display.showMainMenu();
int choice = display.getMenuChoice(1, 3);
// ... handle choice ...
```

## 🗂️ File Structure

* `main.cpp` — Application entry point.
* `BankSystem.hpp/cpp` — Main banking logic and flow.
* `Display.hpp/cpp` — Console UI module.
* `README.markdown` — This documentation.
* `screenshots/` — Example UI images.

## 📝 Technical Notes

* **Exception Handling**: All runtime errors are caught in `main.cpp` and reported.
* **UI Separation**: All display logic is encapsulated in `Display`.
* **Cross-Platform**: Uses conditional compilation for Windows-specific features.
* **Input Validation**: Ensures robust user input handling.

## 🤝 Contributing

Contributions are welcome! Please fork, branch, and submit pull requests for improvements or new features. See [CONTRIBUTING](CONTRIBUTING.md) if available.

## 📃 License

Licensed under the **MIT License**.

## 📧 Contact

Created by **Adrian Lesniak**. For questions or feedback, open an issue or contact the repository owner.

---
✨ _Secure, modular, and user-friendly C++ console banking system._
