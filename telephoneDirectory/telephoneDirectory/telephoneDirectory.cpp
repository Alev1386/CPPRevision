#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct person
{
    string name;
    string phone;
    string adress;
};

void show(vector<person> &a);
void add(vector<person> &a);
void remove(vector<person> &a);

int main()
{
    vector<person> list;
    int option = 0;

    while (option!=4)
    {
        cout << "1.Add contact\n2.Show directory\n3.Remove contact\n4.Exit\n";
        cin >> option;

        switch (option)
        {
        case 1:
            add(list);
            break;
        case 2:
            show(list);
            break;
        case 3:
            remove(list);
            break;
        case 4:
            break;
        default:
            cout << "Invalid choise!\n";
            break;
        }
    }
}

void add(vector<person> &a){
    string _name;
    string _phone;
    string _adress;

    cout << "Enter name, phone, adress:" << endl;
    cout << "Name: ";
    cin >> _name;
    cout << "\nPhone: ";
    cin >> _phone;
    cout << "\nAdress: ";
    cin >> _adress;

    a.push_back({_name,_phone, _adress});

    cout << endl << "New contact addded!" << endl;
}

void show(vector<person> &a) {
    cout << "\tName\tPhone\tAdress\n";
    for (int i = 0; i < a.size(); i++)
    {
        cout << i+1 << ".\t" << a.at(i).name << "\t" << a.at(i).phone << "\t" << a.at(i).adress << endl;
    }
}

void remove(vector<person> &a) {
    show(a);
    int k;
    cout << "\n\nSelect an index of object to be deleted:";
    cin >> k;
    if (k > 0 && k < a.size())
    {
        a.erase(a.begin()+k);
    }
    else
    {
        cout << "Invalid number!" << endl;
    }
}