#pragma once
#include <string>

class Display {
public:
    void showWelcome() const;
    void showPinPrompt() const;
    void showMainMenu() const;
    void showSuccess() const;
    void showError(const std::string& message) const;
    void showChangePinMenu() const;
    void clearScreen() const;
    int getMenuChoice() const;
    void setTextColor(int color) const;
    void resetColor() const;
private:
    void drawSimpleLogo() const;
};
