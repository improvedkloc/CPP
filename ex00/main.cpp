#include "ClapTrap.hpp"

#include <iostream>

int main() {
  std::cout << "--- Basic constructor and action test ---" << std::endl;
  ClapTrap alpha("Alpha");
  alpha.attack("target dummy");
  alpha.takeDamage(3);
  alpha.beRepaired(2);

  std::cout << "\n--- No energy test ---" << std::endl;
  ClapTrap beta("Beta");
  for (int i = 0; i < 10; ++i)
    beta.attack("wall");
  beta.attack("wall");
  beta.beRepaired(1);

  std::cout << "\n--- No hit points test ---" << std::endl;
  ClapTrap gamma("Gamma");
  gamma.takeDamage(20);
  gamma.attack("enemy");
  gamma.beRepaired(5);

  std::cout << "\n--- Canonical form test ---" << std::endl;
  ClapTrap copy(alpha);
  ClapTrap assigned;
  assigned = alpha;

  return 0;
}
