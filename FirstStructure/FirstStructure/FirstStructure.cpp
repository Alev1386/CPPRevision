#include <iostream>
#include <string>

using namespace std;

struct student
{
    string name;
    int age;
    float avg;
};

int main()
{
    student one;
    one.name = "Max";
    one.age = 15;
    one.avg = 4.6;

    cout << one.name << "\t" << one.age << "\t" << one.avg << endl;
    return 0;
}
