#include <iostream>

using namespace std;

void swap(int* a, int* b);


int main()
{
    int a = 10;
    int b = 44;
    std::cout << a << "\t" << b << endl;
    swap(&a,&b);
    std::cout << a << "\t" << b << endl;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}