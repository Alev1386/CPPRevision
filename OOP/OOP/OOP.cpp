#include <iostream>
#include <vector>
#include <string>

using namespace std;

class car
{
public:
	car();
	~car();
	void setMark(string a) {
		mark = a;
	}
	void setModel(string a) {
		model = a;
	}
	void setDateBuilt(string a) {
		dateBuilt = a;
	}

	string getMark() {
		return mark;
	}
	string getModel() {
		return model;
	}
	string getDateBuilt() {
		return dateBuilt;
	}
private:
	string mark;
	string model;
	string dateBuilt;
};

car::car()
{
}

car::~car()
{
}

class book
{
public:
	book();
	~book();

private:


};

book::book()
{
	cout << "Book is created!" << endl;
}

book::~book()
{
	cout << "Book is deleted!" << endl;
}

class figure
{
public:
	figure();
	~figure();
	int x;
};

figure::figure()
{
}

figure::~figure()
{
}


class circle : public figure
{
public:
	circle();
	~circle();
	void setX(int a) {
		x = a;
	}
private:

};

circle::circle()
{
}

circle::~circle()
{
}

int main()
{
	car c1;
	book b1;
	circle cerc1;

	cerc1.setX(10);

	c1.setMark("Toyota");
	c1.setModel("Camry");
	c1.setDateBuilt("2005");

	cout << c1.getMark() << endl << c1.getModel() << endl << c1.getDateBuilt() << endl;


}