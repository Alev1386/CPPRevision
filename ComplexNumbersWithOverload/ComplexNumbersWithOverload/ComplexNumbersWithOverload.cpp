#include <iostream>

class Complex
{
public:
	Complex(double r = 0, double i = 0) : real(r), imag(i) {}

	Complex operator-(const Complex& other) {
		return Complex(real - other.real, imag - other.imag);
	}
	Complex operator+(const Complex& other) {
		return Complex(real + other.real, imag + other.imag);
	}
	double operator[](int index) const {
		if (index == 0) return real;
		if (index == 1) return imag;
		throw std::out_of_range("Index must be 0(real) or 1(imag)!");
	}

	void operator()()const {
		std::cout << "Complex number: " << real << " + " << imag << "i\n";
	}

	friend std::ostream& operator <<(std::ostream& out, const Complex& c) {
		out << c.real << " + " << c.imag << "i";
		return out;
	}

private:
	double real, imag;
};


int main()
{
	Complex a(3, 4), b(1, 2);

	Complex sum = a + b;
	Complex diff = a - b;

	std::cout << "Sum: " << sum << std::endl;
	std::cout << "Difference: " << diff << std::endl;

	std::cout << "Real part: " << a[0] << std::endl << "Imaginary part: " << a[1] << std::endl;

	a();

	return 0;
}