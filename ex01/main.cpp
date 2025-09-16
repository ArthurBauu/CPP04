#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	// const Animal* dog = new Dog();
	// const Animal* cat = new Cat();

	// dog->makeSound();
	// cat->makeSound();

	// delete dog;
	// delete cat;


	// /* DEEP COPY */
	// std::cout << "\n=== Deep Copy Test ===" << std::endl;
	// Dog dog1;
	// dog1.getBrain()->setIdea(0, "I want a bone");
	// Dog dog2 = dog1; // copie

	// std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
	// std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;

	// dog2.getBrain()->setIdea(0, "I want food");
	// std::cout << "After modification:" << std::endl;
	// std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
	// std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;


	/* POLYMOPHY */

	std::cout << "=== Polymorphism Test with Array ===" << std::endl;

	const int size = 6;
	Animal* animals[size];

	// Half Dogs, half Cats
	for (int i = 0; i < size; i++) {
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n=== Make them sound ===" << std::endl;
	for (int i = 0; i < size; i++) {
		animals[i]->makeSound();
	}

	std::cout << "\n=== Cleanup ===" << std::endl;
	for (int i = 0; i < size; i++) {
		delete animals[i];
	}

	std::cout << "\n=== Deep Copy Test ===" << std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea(99, "I want to eat");

	Dog dog2 = dog1; // deep copy
	std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(99) << std::endl;
	std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(99) << std::endl;

	dog2.getBrain()->setIdea(99, "I want to play fetch");
	std::cout << "After modification:" << std::endl;
	std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(99) << std::endl;
	std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(99) << std::endl;
	std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;


	return 0;
}


// int main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;//should not create a leak
// 	delete i;

// 	return 0;
// }