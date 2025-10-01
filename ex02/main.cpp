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

	std::cout << "\n=== Deep Copy Test ===" << std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea(0, "I want to eat");
	dog1.getBrain()->setIdea(1, "I want to sleep");

	Dog dog2 = dog1; // deep copy
	std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog1 idea[1]: " << dog1.getBrain()->getIdea(1) << std::endl;
	std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 idea[1]: " << dog2.getBrain()->getIdea(1) << std::endl;

	std::cout << "\nModifying dog2's idea[1]..." << std::endl;
	dog2.getBrain()->setIdea(1, "I want to play fetch");
	
	std::cout << "After modification:" << std::endl;
	std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog1 idea[1]: " << dog1.getBrain()->getIdea(1) << std::endl;
	std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 idea[1]: " << dog2.getBrain()->getIdea(1) << std::endl;

	return 0;
}
