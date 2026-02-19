#include "ClapTrap.hpp"

int main() {
    ClapTrap a("A");
    ClapTrap b("B");

    a.attack("B");
    b.takeDamage(3);
    b.beRepaired(2);

    for (int i = 0; i < 11; ++i)
        a.attack("target dummy");

    b.takeDamage(20);
    b.beRepaired(1);

    return 0;
}
