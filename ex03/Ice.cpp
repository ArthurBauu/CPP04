#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice materia destructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other) {
	std::cout << "Ice copied" << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
	std::cout << "Ice assignment operator called" << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout << "*shoots an ice spear on " << target.getName() << "*"<< std::endl;
}


