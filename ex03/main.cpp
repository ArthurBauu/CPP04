#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
    std::cout << "=== MateriaSource test ===" << std::endl;
    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "\n=== Character equip test ===" << std::endl;
    ICharacter* me = new Character("Me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    tmp = src->createMateria("fire"); // type inconnu
    if (tmp)
        me->equip(tmp);

    std::cout << "\n=== Use Materias ===" << std::endl;
    ICharacter* bob = new Character("Bob");

    me->use(0, *me); // ice
    me->use(1, *bob); // cure
    me->use(2, *bob); // slot vide

    std::cout << "\n=== Deep copy test ===" << std::endl;
    Character copy = *(dynamic_cast<Character*>(me)); // copie profonde

    copy.use(0, *bob);
    copy.use(1, *me);

    std::cout << "\n=== Cleanup ===" << std::endl;
    delete bob;
    delete me;
    delete src;

    return 0;
}
