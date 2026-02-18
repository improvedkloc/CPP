#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    std::cout << "=== Abstract polymorphism test ===" << std::endl;
    const Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    for (int i = 0; i < 4; ++i) {
        std::cout << animals[i]->getType() << " -> ";
        animals[i]->makeSound();
    }

    for (int i = 0; i < 4; ++i)
        delete animals[i];

    std::cout << "\n=== Deep copy test ===" << std::endl;
    Dog d1;
    d1.setIdea(1, "Find the ball");
    Dog d2 = d1;
    d2.setIdea(1, "Sleep in the sun");
    std::cout << "d1 idea[1]: " << d1.getIdea(1) << std::endl;
    std::cout << "d2 idea[1]: " << d2.getIdea(1) << std::endl;

    Cat c1;
    c1.setIdea(2, "Observe birds");
    Cat c2;
    c2 = c1;
    c2.setIdea(2, "Ignore humans");
    std::cout << "c1 idea[2]: " << c1.getIdea(2) << std::endl;
    std::cout << "c2 idea[2]: " << c2.getIdea(2) << std::endl;

    return 0;
}
