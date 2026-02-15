#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    int startIndex;
    typedef void (Harl::*ComplainFn)(void);
    const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    ComplainFn handlers[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    if (level.empty())
        startIndex = -1;
    else
        switch (level[0]) {
        case 'D': startIndex = (level == "DEBUG") ? 0 : -1; break;
        case 'I': startIndex = (level == "INFO") ? 1 : -1; break;
        case 'W': startIndex = (level == "WARNING") ? 2 : -1; break;
        case 'E': startIndex = (level == "ERROR") ? 3 : -1; break;
        default: startIndex = -1; break;
        }

    if (startIndex == -1) {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return;
    }

    for (int i = startIndex; i < 4; ++i) {
        if (i > startIndex)
            std::cout << std::endl;
        if (levels[i] == level || i > startIndex)
            (this->*handlers[i])();
    }
}
