#include "ScavTrap.hpp"

int main() {
    ClapTrap c("CL4P");
    ScavTrap s("SC4V");

    c.attack("intruder");
    s.attack("intruder");
    s.guardGate();

    s.takeDamage(30);
    s.beRepaired(10);

    for (int i = 0; i < 52; ++i)
        s.attack("dummy");

    return 0;
}
