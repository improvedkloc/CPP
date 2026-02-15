#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : _name("unnamed") {}

Zombie::~Zombie() {
    std::cout << _name << ": BraiiiiiiinnnzzzZ... (destroyed)" << std::endl;
}

void Zombie::setName(const std::string &name) {
    _name = name;
}

void Zombie::announce(void) const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
