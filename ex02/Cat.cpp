#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	brain = new Brain(*other.brain);
	std::cout << "Cat copied" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Cat meows : Miaou Miaou" << std::endl;
}

Brain *Cat::getBrain() const {
	return brain;
}