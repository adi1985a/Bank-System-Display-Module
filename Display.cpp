#include "Display.hpp"
#include <iostream>
#include <limits>
#ifdef _WIN32
#include <windows.h>
#endif

void Display::showWelcome() const {
    drawSimpleLogo();  // Changed from drawBankLogo to drawSimpleLogo
    std::cout << "\nWelcome to our Bank System\n" << std::endl;
}

void Display::showPinPrompt() const {
    std::cout << "Please enter your PIN: ";
}

void Display::showSuccess() const {
    std::cout << "\n✓ Access granted! Welcome to your account.\n" << std::endl;
}

void Display::showError(const std::string& message) const {
    std::cout << "\n✗ Error: " << message << "\n" << std::endl;
}

void Display::clearScreen() const {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Display::setTextColor(int color) const {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#endif
}

void Display::resetColor() const {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
#endif
}

void Display::drawSimpleLogo() const {
    setTextColor(14); // Yellow
    std::cout << R"(
    +------------------+
    |   SECURE BANK    |
    +------------------+
    )" << std::endl;
    resetColor();
}

void Display::showMainMenu() const {
    clearScreen();
    drawSimpleLogo();
    setTextColor(11); // Light cyan
    std::cout << "\n1. Check Balance";
    std::cout << "\n2. Change PIN";
    std::cout << "\n3. Logout\n";
    std::cout << "\nEnter your choice (1-3): ";
    resetColor();
}

void Display::showChangePinMenu() const {
    clearScreen();
    drawSimpleLogo();
    setTextColor(11);
    std::cout << "\nChange PIN";
    std::cout << "\n-----------------";
    std::cout << "\nEnter new PIN (4 digits): ";
    resetColor();
}

int Display::getMenuChoice() const {
    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}
