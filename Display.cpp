#include "Display.hpp"
#include <iostream>
#include <limits>

#ifdef _WIN32
  #include <windows.h>
#endif

#ifdef _WIN32
  // Windows‐specific color constants:
  constexpr WORD COLOR_RESET    = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;      // White
  constexpr WORD COLOR_HEADER   = FOREGROUND_GREEN | FOREGROUND_BLUE   | FOREGROUND_INTENSITY; // Bright Cyan
  constexpr WORD COLOR_PROMPT   = FOREGROUND_RED   | FOREGROUND_GREEN  | FOREGROUND_INTENSITY; // Bright Yellow
  constexpr WORD COLOR_INPUT    = FOREGROUND_RED| FOREGROUND_INTENSITY;                 // Bright Yellow
  constexpr WORD COLOR_SUCCESS  = FOREGROUND_GREEN | FOREGROUND_INTENSITY;                 // Bright Green
  constexpr WORD COLOR_ERROR    = FOREGROUND_RED   | FOREGROUND_INTENSITY;                 // Bright Red
#else
  constexpr int COLOR_RESET    = 0;
  constexpr int COLOR_HEADER   = 0;
  constexpr int COLOR_PROMPT   = 0;
  constexpr int COLOR_INPUT    = 0;
  constexpr int COLOR_SUCCESS  = 0;
  constexpr int COLOR_ERROR    = 0;
#endif

void Display::setTextColor(int color) const {
  #ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
  #endif
}

void Display::resetColor() const {
  #ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_RESET);
  #endif
}

void Display::clearScreen() const {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

void Display::drawLogo() const {
  setTextColor(COLOR_HEADER);
  // ASCII art for "PIN"
  std::cout << R"(
  ____  _   _ _   _
 |  _ \| | | | \ | |
 | |_) | | | |  \| |
 |  __/| |_| | |\  |
 |_|    \___/|_| \_|

  )" << "\n";
  resetColor();
}

void Display::showWelcome() const {
  clearScreen();
  drawLogo();
  std::cout << "\n";
  setTextColor(COLOR_PROMPT);
  std::cout << "Welcome to Secure PIN System\n";
  std::cout << "----------------------------\n\n";
  resetColor();
}

void Display::showPinPrompt() const {
  setTextColor(COLOR_PROMPT);
  std::cout << "Please enter your 4-digit PIN: ";
  resetColor();
}

void Display::showSuccess(const std::string& msg) const {
  setTextColor(COLOR_SUCCESS);
  std::cout << "\n\u2713 " << msg << "\n\n"; // ✓
  resetColor();
}

void Display::showError(const std::string& message) const {
  setTextColor(COLOR_ERROR);
  std::cout << "\n\u2717 Error: " << message << "\n\n"; // ✗
  resetColor();
}

void Display::showMainMenu() const {
  clearScreen();
  drawLogo();
  setTextColor(COLOR_PROMPT);
  std::cout << "1) Check Balance\n";
  std::cout << "2) Deposit Funds\n";
  std::cout << "3) Withdraw Funds\n";
  std::cout << "4) Change PIN\n";
  std::cout << "5) Logout\n";
  std::cout << "Enter choice (1-5): ";
  resetColor();
}

void Display::showBalance(double balance) const {
  setTextColor(COLOR_PROMPT);
  std::cout << "\n--- Your Balance ---\n\n";
  setTextColor(COLOR_INPUT);
  std::cout << "Current Balance: $" << balance << "\n\n";
  resetColor();
}

void Display::showDepositMenu() const {
  setTextColor(COLOR_PROMPT);
  std::cout << "\n--- Deposit Funds ---\n";
  std::cout << "Enter amount to deposit: $";
  resetColor();
}

void Display::showWithdrawMenu() const {
  setTextColor(COLOR_PROMPT);
  std::cout << "\n--- Withdraw Funds ---\n";
  std::cout << "Enter amount to withdraw: $";
  resetColor();
}

void Display::showChangePinMenu() const {
  clearScreen();
  drawLogo();
  setTextColor(COLOR_PROMPT);
  std::cout << "\n--- Change PIN ---\n";
  std::cout << "Enter new 4-digit PIN: ";
  resetColor();
}

int Display::getMenuChoice(int min, int max) const {
  int choice;
  while (true) {
    if ((std::cin >> choice) && choice >= min && choice <= max) {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return choice;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    showError("Invalid selection. Please enter a number between " +
              std::to_string(min) + " and " + std::to_string(max) + ".");
    setTextColor(COLOR_PROMPT);
    std::cout << "Enter choice (" << min << "-" << max << "): ";
    resetColor();
  }
}

double Display::promptAmount(const std::string& prompt) const {
  double amt;
  while (true) {
    setTextColor(COLOR_PROMPT);
    std::cout << prompt;
    resetColor();
    if ((std::cin >> amt) && amt > 0.0) {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return amt;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    showError("Invalid amount. Enter a positive number.");
  }
}

void Display::pause() const {
  setTextColor(COLOR_PROMPT);
  std::cout << "Press Enter to continue...";
  resetColor();
  std::cin.get();
}
