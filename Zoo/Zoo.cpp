#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Animal {
public:
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

class Zoo {
public:
	Zoo()
	{

	}

	void addAnimal(Animal* animal)
	{
		if (animal == nullptr)
		{
			cout << "동물 추가에 문제가 생겼습니다. \" nullptr!! \"\n";
			return;
		}

		if (count < 10)
		{
			pAnimals[count] = animal;
			//cout << count << endl;
			count++;
		}
		else
		{
			cout << "동물원이 꽉 찼습니다!! 더이상 동물을 추가할 수 없습니다.\n";
		}
	}

	void performActions()
	{
		for (int i = 0; i < count; ++i) {
			if (pAnimals[i]) {
				pAnimals[i]->makeSound();
			}
		}

	}

	~Zoo()
	{
		for (int i = 0; i < count; ++i) 
		{
			delete pAnimals[i];
		}
	}

private:
	Animal* pAnimals[10] = { nullptr }; // 동물 객체를 저장하는 포인터 배열
	int count = 0;
};

Animal* createRandomAnimal()
{
	int randomValue = std::rand() % 3;
	Animal* randomCreatedAnimal = nullptr;
	switch (randomValue)
	{
	case 0:
		randomCreatedAnimal = new Dog();
		break;
	case 1:
		randomCreatedAnimal = new Cat();
		break;
	case 2:
		randomCreatedAnimal = new Cow();
		break;
	Default:
		break;
	}

	return randomCreatedAnimal;
}


int main()
{
	Animal* pAnimalArr[3];

	pAnimalArr[0] = new Dog();
	pAnimalArr[1] = new Cat();
	pAnimalArr[2] = new Cow();

	for (int i = 0; i < 3; ++i) {
		pAnimalArr[i]->makeSound();
	}

	Zoo myZoo;
	int instanceCount(5);

	for (int i = 0; i < instanceCount; ++i)
	{
		myZoo.addAnimal(createRandomAnimal());
	}

	std::cout << "동물들의 장기자랑 보고 가실게요~" << std::endl;
	myZoo.performActions();

	return 0;
}
