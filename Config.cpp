#include "Config.hpp"

Config::Config() {
    correctPin = "1234";  // Default PIN
    maxAttempts = 3;      // Default max attempts
}

void Config::updatePin(const std::string& newPin) {
    correctPin = newPin;
}
