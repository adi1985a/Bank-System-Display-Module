#pragma once
#include <string>
#include <memory>
#include "Config.hpp"
#include "Display.hpp"

class BankSystem {
private:
    int attempts;
    bool isLoggedIn;
    double balance;

    std::shared_ptr<Config> config;
    std::shared_ptr<Display> display;

    void handleLogin();
    bool validatePin(const std::string& input);
    bool validateNewPin(const std::string& newPin);

    void handleMainMenu();
    void checkBalance();
    void depositFunds();
    void withdrawFunds();
    void changePin();

public:
    BankSystem();
    void run();
};
