#include <iostream>
#include <string>

int main() {
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string &stringREF = brain;

    std::cout << "Address of brain    : " << &brain << std::endl;
    std::cout << "Address in stringPTR: " << stringPTR << std::endl;
    std::cout << "Address in stringREF: " << &stringREF << std::endl;

    std::cout << "Value of brain      : " << brain << std::endl;
    std::cout << "Value via stringPTR : " << *stringPTR << std::endl;
    std::cout << "Value via stringREF : " << stringREF << std::endl;
    return 0;
}
