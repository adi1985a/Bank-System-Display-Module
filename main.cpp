#include <iostream>
#include <stdexcept>
#include "BankSystem.hpp"

int main() {
    try {
        BankSystem bank;
        bank.run();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
