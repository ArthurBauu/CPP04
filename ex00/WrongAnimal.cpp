#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	std::cout << "WrongAnimal copied" << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal makes a sound: Gruff Gruff" << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}
