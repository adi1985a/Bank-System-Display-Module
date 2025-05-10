#pragma once
#include <string>

class Config {
private:
    std::string correctPin;
    int maxAttempts;

public:
    Config();
    std::string getPin() const { return correctPin; }
    int getMaxAttempts() const { return maxAttempts; }
    void updatePin(const std::string& newPin);
};
