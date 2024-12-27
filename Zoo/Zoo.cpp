#include <iostream>

class Animal {
public :
	Animal()
	{

	}

	~Animal()
	{

	}

	virtual void makeSound() const = 0;
};

class Dog : public Animal {
public:
	void makeSound() const override {
		std::cout << "월월!!" << std::endl;
	}
};

class Cat : public Animal {
public:
	void makeSound() const override {
		std::cout << "야옹~" << std::endl;
	}
};

class Cow : public Animal {
public:
	void makeSound() const override {
		std::cout << "음머~~~~" << std::endl;
	}
};


int main()
{
	Animal* pAnimalArr[3];

	pAnimalArr[0] = new Dog();
	pAnimalArr[1] = new Cat();
	pAnimalArr[2] = new Cow();

	for (int i = 0; i < 3; ++i) {
		pAnimalArr[i]->makeSound();
	}
}
