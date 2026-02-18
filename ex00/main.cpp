#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Subject test ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== Wrong polymorphism test ===" << std::endl;
    const WrongAnimal* wrong = new WrongCat();
    std::cout << wrong->getType() << std::endl;
    wrong->makeSound();
    delete wrong;

    std::cout << "\n=== Stack copy/assignment tests ===" << std::endl;
    Dog a;
    Dog b(a);
    Cat c;
    Cat d;
    d = c;
    a.makeSound();
    b.makeSound();
    c.makeSound();
    d.makeSound();

    return 0;
}
