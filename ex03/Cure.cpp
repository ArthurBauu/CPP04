#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure() {
	std::cout << "Cure materia destructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other) {
	std::cout << "Cure copied" << std::endl;
}

Cure &Cure::operator=(const Cure &other) {
	std::cout << "Cure assignment operator called" << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	std::cout << "* Viouuuuuum... Heals " << target.getName() << "'s wounds *"<< std::endl;
}
