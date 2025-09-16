#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define MAX_MATERIA 4

class Character : public ICharacter {
private:
	std::string name;
	AMateria* inventory[MAX_MATERIA];

public:
	Character();
	virtual ~Character();

	Character(const std::string &name);
	Character(const Character &other);
	Character &operator=(const Character &other);

	std::string const &getName() const;

	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

};

#endif