#include "Character.hpp"

Character::Character() : name("Default") {
	for (int i = 0; i < MAX_MATERIA; i++)
		inventory[i] = NULL;
	std::cout << "Character default constructor called" << std::endl;
}

Character::~Character() {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (inventory[i])
			delete inventory[i];
	}
	std::cout << "Character destructor called" << std::endl;
}

Character::Character(const std::string &name) : name(name) {
	for (int i = 0; i < MAX_MATERIA; i++)
		inventory[i] = NULL;
	std::cout << "Character constructor called for " << name << std::endl;
}

Character::Character(const Character &other) : name(other.name) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
	std::cout << "Character copy constructor called for " << name << std::endl;
}

Character &Character::operator=(const Character &other) {
	if (this != &other) {
		name = other.name;
		for (int i = 0; i < MAX_MATERIA; i++) {
			if (inventory[i]) {
				delete inventory[i];
				inventory[i] = NULL;
			}	
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}
	std::cout << "Character assignment operator called for " << name << std::endl;
	return *this;
}

std::string const &Character::getName() const {
	return name;
}

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << "Cannot equip a null materia." << std::endl;
		return;
	}
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (!inventory[i]) {
			inventory[i] = m;
			std::cout << "Equipped " << m->getType() << " materia in slot " << i << "." << std::endl;
			return;
		}
	}
	std::cout << "Inventory full, cannot equip more materia." << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= MAX_MATERIA) {
		std::cout << "Invalid index to unequip: " << idx << std::endl;
		return;
	}
	if (inventory[idx]) {
		std::cout << "Unequipped " << inventory[idx]->getType() << " materia from slot " << idx << "." << std::endl;
		inventory[idx] = NULL;
	} else {
		std::cout << "No materia to unequip in slot " << idx << "." << std::endl;
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx >= MAX_MATERIA) {
		std::cout << "Invalid index to use: " << idx << std::endl;
		return;
	}
	if (inventory[idx]) {
		inventory[idx]->use(target);
	} else {
		std::cout << "No materia in slot " << idx << " to use." << std::endl;
	}
}