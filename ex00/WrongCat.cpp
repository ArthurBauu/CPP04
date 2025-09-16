#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "WrongCat copied" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat meows: Miaou Miaou" << std::endl;
}

