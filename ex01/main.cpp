#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    std::cout << "=== Dynamic polymorphic array test ===" << std::endl;
    const int size = 6;
    Animal* animals[size];

    for (int i = 0; i < size / 2; ++i)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; ++i)
        animals[i] = new Cat();

    for (int i = 0; i < size; ++i) {
        std::cout << animals[i]->getType() << " -> ";
        animals[i]->makeSound();
    }

    for (int i = 0; i < size; ++i)
        delete animals[i];

    std::cout << "\n=== Deep copy test (Dog) ===" << std::endl;
    Dog originalDog;
    originalDog.setIdea(0, "Guard the house");
    Dog copiedDog(originalDog);
    copiedDog.setIdea(0, "Play fetch");
    std::cout << "Original Dog idea[0]: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copied Dog idea[0]: " << copiedDog.getIdea(0) << std::endl;

    std::cout << "\n=== Deep copy test (Cat assignment) ===" << std::endl;
    Cat originalCat;
    originalCat.setIdea(42, "Sleep on keyboard");
    Cat assignedCat;
    assignedCat = originalCat;
    assignedCat.setIdea(42, "Knock objects off table");
    std::cout << "Original Cat idea[42]: " << originalCat.getIdea(42) << std::endl;
    std::cout << "Assigned Cat idea[42]: " << assignedCat.getIdea(42) << std::endl;

    std::cout << "\n=== Leak-check subject test ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    return 0;
}
