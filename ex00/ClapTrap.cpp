#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap()
    : _name("unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap default constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : _name(other._name),
      _hitPoints(other._hitPoints),
      _energyPoints(other._energyPoints),
      _attackDamage(other._attackDamage) {
  std::cout << "ClapTrap copy constructor called for " << _name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  if (this != &other) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
  }
  std::cout << "ClapTrap copy assignment operator called for " << _name
            << std::endl;
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

void ClapTrap::attack(const std::string &target) {
  if (_hitPoints <= 0) {
    std::cout << "ClapTrap " << _name << " can't attack because it has no hit points left."
              << std::endl;
    return;
  }
  if (_energyPoints <= 0) {
    std::cout << "ClapTrap " << _name
              << " can't attack because it has no energy points left." << std::endl;
    return;
  }
  --_energyPoints;
  std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hitPoints <= 0) {
    std::cout << "ClapTrap " << _name << " is already out of hit points." << std::endl;
    return;
  }
  if (amount >= static_cast<unsigned int>(_hitPoints)) {
    _hitPoints = 0;
  } else {
    _hitPoints -= static_cast<int>(amount);
  }
  std::cout << "ClapTrap " << _name << " takes " << amount
            << " points of damage and now has " << _hitPoints << " hit points."
            << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_hitPoints <= 0) {
    std::cout << "ClapTrap " << _name
              << " can't repair itself because it has no hit points left." << std::endl;
    return;
  }
  if (_energyPoints <= 0) {
    std::cout << "ClapTrap " << _name
              << " can't repair itself because it has no energy points left."
              << std::endl;
    return;
  }
  --_energyPoints;
  _hitPoints += static_cast<int>(amount);
  std::cout << "ClapTrap " << _name << " repairs itself for " << amount
            << " hit points and now has " << _hitPoints << " hit points."
            << std::endl;
}
