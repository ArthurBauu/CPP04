#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "=== Animal Test ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();


	std::cout << "\n=== Sound Test ===" << std::endl;
	std::cout << "Animal type : " << dog->getType() << " " << std::endl;
	dog->makeSound();

	std::cout << "Animal type : "<< cat->getType() << " " << std::endl;
	cat->makeSound();

	std::cout << "Animal type : "<< meta->getType() << " " << std::endl;
	meta->makeSound();

	std::cout << "\n=== Cleanup ===" << std::endl;
	delete meta;
	delete dog;
	delete cat;

	std::cout << "\n=== WrongAnimal Test ===" << std::endl;
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << " ";
	wrongCat->makeSound(); // Affiche le son de WrongAnimal car makeSound() n'est pas virtual

	std::cout << wrong->getType() << " "<< std::endl;
	wrong->makeSound();

	delete wrong;
	delete wrongCat;

	return 0;
}
