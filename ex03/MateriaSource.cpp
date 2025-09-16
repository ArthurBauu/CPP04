#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (materias[i])
			delete materias[i];
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	for (int i = 0; i < 4; i++) {
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
		else
			materias[i] = NULL;
	}
	std::cout << "MateriaSource copied" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (materias[i])
				delete materias[i];
			if (other.materias[i])
				materias[i] = other.materias[i]->clone();
			else
				materias[i] = NULL;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
	if (!m) {
		std::cout << "Cannot learn a null materia" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (!materias[i]) {
			materias[i] = m;
			std::cout << "Learned materia of type: " << m->getType() << std::endl;
			return;
		}
	}
	std::cout << "MateriaSource is full, cannot learn more materias" << std::endl;
	delete m;
}

AMateria *MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] && materias[i]->getType() == type)
			return materias[i]->clone();
	}
	std::cout << "Materia of type " << type << " not found" << std::endl;
	return NULL;
}
