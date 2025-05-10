# Bank System Display Module

## Overview
This C++ `Display` class provides a console-based user interface for a bank system. It manages screen clearing, colored text output, and an ASCII logo. The class displays welcome messages, PIN prompts, main menu, PIN change interface, success/error messages, and handles user input for menu choices. It supports Windows-specific features and cross-platform compatibility.

## Features
- **Display Class**:
  - `showWelcome`: Displays an ASCII logo and welcome message.
  - `showPinPrompt`: Prompts for PIN input.
  - `showSuccess`: Shows access granted message.
  - `showError`: Displays error messages with a custom string.
  - `showMainMenu`: Shows menu with options: Check Balance, Change PIN, Logout.
  - `showChangePinMenu`: Displays PIN change prompt.
  - `getMenuChoice`: Retrieves validated user input for menu selections.
- **Console Management**:
  - `clearScreen`: Clears console (`cls` for Windows, `clear` for others).
  - `setTextColor`/`resetColor`: Sets colored text (yellow, light cyan) on Windows.
  - `drawSimpleLogo`: Renders an ASCII "SECURE BANK" logo.
- **Cross-Platform Support**:
  - Uses preprocessor directives (`#ifdef _WIN32`) for Windows-specific console functions.
  - Non-Windows systems use basic console output without color.

## Requirements
- C++ compiler (e.g., g++, clang++) with C++11 or later
- Standard C++ libraries: `<iostream>`, `<limits>`
- Windows-specific library: `<windows.h>` (for color and console functions)
- Custom header: `Display.hpp` (class declaration, assumed provided)
- Operating system: Windows for full functionality; others for basic output

## Setup
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```
2. Ensure `Display.hpp` is in the project directory with the `Display` class declaration.
3. Save the provided code as `Display.cpp`.
4. Compile the program (example assumes a main program including `Display`):
   ```bash
   g++ main.cpp Display.cpp -o bank_system
   ```
5. Run the program:
   ```bash
   ./bank_system
   ```

## Usage
1. Include `Display.hpp` in a main program to use the `Display` class.
2. **Interface**:
   - `showWelcome`: Shows "SECURE BANK" logo and welcome message.
   - `showPinPrompt`: Prompts for PIN entry.
   - `showMainMenu`: Displays options (1–3) for balance, PIN change, or logout.
   - `showChangePinMenu`: Prompts for a new 4-digit PIN.
   - `showSuccess`/`showError`: Shows access or error feedback.
3. **Actions**:
   - Use `getMenuChoice` to capture user input (1–3).
   - Colors (yellow for logo, cyan for menus) enhance visibility on Windows.
   - Screen clears between displays for a clean UI.
4. **Output**:
   - Example: Main menu shows logo and "1. Check Balance\n2. Change PIN\n3. Logout".
   - Errors display as "✗ Error: [message]".

## File Structure
- `Display.cpp`: Source file with `Display` class implementation.
- `Display.hpp`: Header file with `Display` class declaration (assumed, not provided).
- `README.md`: This file, providing project documentation.

## Notes
- Windows-specific for colored text and `cls`; non-Windows systems use `clear` and no colors.
- Requires `Display.hpp` with class declaration and any referenced functions (e.g., `drawSimpleLogo`).
- Input handling in `getMenuChoice` clears invalid input for robustness.
- Extend by adding more menu options, animations, or full cross-platform color support.
- No locale settings; uses English text for output.
- Minimal dependencies: standard C++ libraries and `windows.h` for Windows.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make changes and commit (`git commit -m "Add feature"`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact
For questions or feedback, open an issue on GitHub or contact the repository owner.