#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("UnnamedScav") {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called for " << _name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cout << "ScavTrap " << _name << " cannot attack." << std::endl;
        return;
    }
    --_energyPoints;
    std::cout << "ScavTrap " << _name << " slashes " << target << ", causing "
              << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode."
              << std::endl;
}
