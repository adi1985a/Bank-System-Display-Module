#include "BankSystem.hpp"
#include <iostream>
#include <algorithm>
#include <limits>

BankSystem::BankSystem()
  : attempts(0), isLoggedIn(false), balance(1000.00) 
{
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
    if (input.length() != 4 || 
        !std::all_of(input.begin(), input.end(), ::isdigit)) 
    {
        display->showError("PIN must be exactly 4 digits");
        return false;
    }
    return (input == config->getPin());
}

void BankSystem::handleLogin() {
    while (attempts < config->getMaxAttempts()) {
        display->showPinPrompt();
        std::string input;
        std::getline(std::cin, input);

        if (validatePin(input)) {
            display->showSuccess("PIN correct! Access granted.");
            display->pause();
            isLoggedIn = true;
            return;
        }

        attempts++;
        display->showError(
          "Invalid PIN. Attempts left: " + 
          std::to_string(config->getMaxAttempts() - attempts)
        );

        // If not yet locked out, allow user to read message
        if (attempts < config->getMaxAttempts()) {
            display->pause();
        }
        display->clearScreen();
    }

    display->showError("Card blocked. Please contact your bank.");
    display->pause();
}

void BankSystem::handleMainMenu() {
    bool running = true;
    while (running && isLoggedIn) {
        display->showMainMenu();
        int choice = display->getMenuChoice(1, 5);
        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                depositFunds();
                break;
            case 3:
                withdrawFunds();
                break;
            case 4:
                changePin();
                break;
            case 5:
                display->showSuccess("Logged out.");
                display->pause();
                running = false;
                break;
            default:
                display->showError("Invalid choice");
                display->pause();
        }
    }
}

void BankSystem::checkBalance() {
    display->clearScreen();
    display->showBalance(balance);
    display->pause();
}

void BankSystem::depositFunds() {
    display->clearScreen();
    display->showDepositMenu();
    double amount = display->promptAmount("Amount: $");
    balance += amount;
    display->showSuccess("Deposited $" + std::to_string(amount) + ".");
    display->pause();
}

void BankSystem::withdrawFunds() {
    display->clearScreen();
    display->showWithdrawMenu();
    double amount = display->promptAmount("Amount: $");
    if (amount > balance) {
        display->showError("Insufficient funds.");
    } else {
        balance -= amount;
        display->showSuccess("Withdrew $" + std::to_string(amount) + ".");
    }
    display->pause();
}

void BankSystem::changePin() {
    display->clearScreen();
    display->showChangePinMenu();
    std::string newPin;
    std::getline(std::cin, newPin);

    if (newPin.empty()) {
        display->showError("No input entered.");
        display->pause();
        return;
    }

    if (!validateNewPin(newPin)) {
        display->pause();
        return;
    }

    config->updatePin(newPin);
    display->showSuccess("PIN changed successfully.");
    display->pause();
}

bool BankSystem::validateNewPin(const std::string& newPin) {
    if (newPin.length() != 4 || 
        !std::all_of(newPin.begin(), newPin.end(), ::isdigit)) 
    {
        display->showError("New PIN must be 4 digits");
        return false;
    }

    if (newPin == config->getPin()) {
        display->showError("New PIN must differ from current PIN");
        return false;
    }
    return true;
}
