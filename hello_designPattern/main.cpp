#include <iostream>
using namespace std;

/*
	基类 动物类
		构造函数
		析构函数
		纯虚函数
		虚函数
		函数
	子类 狗类 猫类
*/

class Animal
{
public:
	Animal(){cout << "Animal construct" << endl;};
	virtual ~Animal(){cout << "Animal deconstruct" << endl;};
	// virtual void bark() = 0;
	virtual void walk(){cout << "Animal walking" << endl;};
	void userun(){cout << "Animal userun:";walk();};
	void run(){cout << "Animal runing" << endl;};
};

class Dog:public Animal
{
public:
	Dog(){cout << "Dog construct" << endl;};
	~Dog(){cout << "Dog deconstruct" << endl;};
	// virtual void bark() = 0;
	virtual void walk(){cout << "Dog walking" << endl;};
	void userun(){cout << "Dog userun:";Animal::walk();};
	void run(){cout << "Dog runing" << endl;};
};

int main()
{
	// Animal* ani = new Animal;
	Animal *ani = new Dog;
	ani->walk();
	ani->run();
	ani->userun();
	delete ani;
	
	cout << "----------------------------------------" << endl;
	Dog dog;
	dog.walk();
	dog.run();
	dog.userun();

	return 0;
};