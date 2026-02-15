#include "Zombie.hpp"
#include <iostream>

int main() {
    const int count = 5;
    Zombie *horde = zombieHorde(count, "Walker");

    if (!horde) {
        std::cerr << "Failed to allocate zombie horde" << std::endl;
        return 1;
    }

    for (int i = 0; i < count; ++i)
        horde[i].announce();

    delete[] horde;
    return 0;
}
