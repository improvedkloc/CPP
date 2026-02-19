#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap()
    : _name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : _name(other._name), _hitPoints(other._hitPoints),
      _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << "ClapTrap copy constructor called for " << _name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " cannot attack: no hit points left."
                  << std::endl;
        return;
    }
    if (_energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " cannot attack: no energy points left."
                  << std::endl;
        return;
    }
    --_energyPoints;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
              << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " is already destroyed." << std::endl;
        return;
    }
    if (static_cast<unsigned int>(_hitPoints) <= amount)
        _hitPoints = 0;
    else
        _hitPoints -= static_cast<int>(amount);
    std::cout << "ClapTrap " << _name << " takes " << amount
              << " points of damage! Hit points left: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " cannot repair: no hit points left."
                  << std::endl;
        return;
    }
    if (_energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " cannot repair: no energy points left."
                  << std::endl;
        return;
    }
    --_energyPoints;
    _hitPoints += static_cast<int>(amount);
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount
              << " hit points. Hit points now: " << _hitPoints << std::endl;
}
