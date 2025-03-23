#include <iostream>
#include <ctime>
#include <vector>
#include <string>

using namespace std;
int main() {
	int* b = new int[10];
	for (size_t i = 0; i < 10; i++)
	{
		b[i] = pow(i,2);
		cout << b[i] << endl;
	}

	delete[] b;

	int k = 5;

	return 0;
}