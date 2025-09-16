#include "AMateria.hpp"

AMateria::AMateria() : type("AMateria") {
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const std::string &type) : type(type) {
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other) : type(other.type) {
	std::cout << "AMateria copied (type: " << type << ")" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other) {
	if (this != &other)
		type = other.type;
	std::cout << "AMateria assignment operator called (type: " << type << ")" << std::endl;
	return *this;
}

std::string const &AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter &target) {
	(void)target;
	std::cout << "* uses a " << type << " materia *" << std::endl;
}
