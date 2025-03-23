#include <iostream>
#include <vector>
#include <string>

using namespace std;

class animal
{
public:
	animal();
	~animal();

	void setName(string _name) {
		name = _name;
	}
	void setAge(int _age) {
		age = _age;
	}
	string getName() {
		return name;
	}
	int getAge() {
		return age;
	}

	void speak() {
		cout << "My name is " << name << "!" << endl;
	}
protected:
	string name;
	int age;

private:
	
};

animal::animal()
{
}

animal::~animal()
{
}

class cat: public animal
{
public:
	cat();
	~cat();
	void speak() {
		cout << "I'm a cat! My name is " << name << "!" << endl;
	}
private:

};

cat::cat()
{
}

cat::~cat()
{
}

class dog: public animal
{
public:
	dog();
	~dog();
	void speak() {
		cout << "I'm a dog! My name is " << name << "!" << endl;
	}
private:

};

dog::dog()
{
}

dog::~dog()
{
}

int main()
{
	cat bob;
	bob.setAge(5);
	bob.setName("Bob");

	dog mark;
	mark.setAge(8);
	mark.setName("Mark");

	bob.speak();
	mark.speak();
}