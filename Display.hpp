#pragma once
#include <string>

class Display {
public:
    void showWelcome() const;
    void showPinPrompt() const;
    void showSuccess(const std::string& msg = "Access granted!") const;
    void showError(const std::string& message) const;
    void clearScreen() const;
    void setTextColor(int color) const;
    void resetColor() const;

    void showMainMenu() const;
    void showBalance(double balance) const;
    void showDepositMenu() const;
    void showWithdrawMenu() const;
    void showChangePinMenu() const;

    int getMenuChoice(int min, int max) const;
    double promptAmount(const std::string& prompt) const;

    void pause() const;

private:
    void drawLogo() const;
};
