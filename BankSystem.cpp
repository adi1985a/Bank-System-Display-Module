#include "BankSystem.hpp"
#include <iostream>
#include <limits>
#include <algorithm>  // Add this for std::all_of

BankSystem::BankSystem() : attempts(0), isLoggedIn(false) {
    config = std::make_shared<Config>();
    display = std::make_shared<Display>();
}

void BankSystem::run() {
    display->showWelcome();
    handleLogin();
    if (isLoggedIn) {
        handleMainMenu();
    }
}

bool BankSystem::validatePin(const std::string& input) {
    if (input.length() != 4 || !std::all_of(input.begin(), input.end(), ::isdigit)) {
        display->showError("PIN must be 4 digits");
        return false;
    }
    return input == config->getPin();
}

void BankSystem::handleLogin() {
    while (attempts < config->getMaxAttempts()) {
        display->showPinPrompt();
        std::string input;
        std::getline(std::cin, input);
        
        if (validatePin(input)) {
            display->showSuccess();
            isLoggedIn = true;
            return;
        }
        
        attempts++;
        display->showError("Invalid PIN. Attempts left: " + 
                          std::to_string(config->getMaxAttempts() - attempts));
        display->clearScreen();
    }
    
    display->showError("Card blocked. Please contact your bank.");
}

void BankSystem::handleMainMenu() {
    bool running = true;
    while (running && isLoggedIn) {
        display->showMainMenu();
        switch (display->getMenuChoice()) {
            case 1: showBalance(); break;
            case 2: changePin(); break;
            case 3: running = false; break;
            default: display->showError("Invalid choice");
        }
    }
}

void BankSystem::changePin() {
    display->clearScreen();
    std::string newPin;
    display->showChangePinMenu();
    std::getline(std::cin, newPin);
    
    if (validateNewPin(newPin)) {
        config->updatePin(newPin);
        display->showSuccess();
    }
}

bool BankSystem::validateNewPin(const std::string& newPin) {
    if (newPin.length() != 4 || !std::all_of(newPin.begin(), newPin.end(), ::isdigit)) {
        display->showError("New PIN must be 4 digits");
        return false;
    }
    
    if (newPin == config->getPin()) {
        display->showError("New PIN must be different from the current PIN");
        return false;
    }
    
    return true;
}

void BankSystem::showBalance() {
    display->clearScreen();
    display->setTextColor(10); // Green
    std::cout << "\nYour current balance: $1000.00\n"; // Example balance
    display->resetColor();
    std::cout << "\nPress Enter to continue...";
    std::cin.get();
}
