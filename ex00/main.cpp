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

	std::cout << dog->getType() << " ";
	dog->makeSound();

	std::cout << cat->getType() << " ";
	cat->makeSound();

	meta->makeSound();

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
