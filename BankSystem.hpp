#pragma once
#include <string>
#include <memory>
#include "Config.hpp"
#include "Display.hpp"

class BankSystem {
private:
    std::string pin;
    int attempts;
    std::shared_ptr<Config> config;
    std::shared_ptr<Display> display;
    bool isLoggedIn;

    void handleMainMenu();
    void changePin();
    void showBalance();
    bool validateNewPin(const std::string& newPin);

public:
    BankSystem();
    void run();
    bool validatePin(const std::string& input);
    void handleLogin();
};
