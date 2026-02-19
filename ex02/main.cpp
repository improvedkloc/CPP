#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap clap("CL4P");
    ScavTrap scav("SC4V");
    FragTrap frag("FR4G");

    clap.attack("target");
    scav.attack("target");
    frag.attack("target");

    scav.guardGate();
    frag.highFivesGuys();

    frag.takeDamage(95);
    frag.beRepaired(10);

    for (int i = 0; i < 101; ++i)
        frag.attack("dummy");

    return 0;
}
