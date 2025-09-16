#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "Dog.hpp"
#include "Cat.hpp"

int main() {

	// Animal est abstraite donc :
	// Animal a;
	// Animal *a = new Animal();
	// est impossible (erreur de compilation)


	std::cout << "=== Abstract class test ===" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); // Cat sound
	j->makeSound(); // Dog sound

	delete j;
	delete i;

	std::cout << "\n=== Deep copy test ===" << std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea(0, "Play fetch");
	Dog dog2 = dog1;

	std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;

	dog2.getBrain()->setIdea(0, "Eat food");
	std::cout << "After change:" << std::endl;
	std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;

	return 0;
}
