#include <iostream>
#include <string>

using namespace std;

bool isPolyndrom(string str);

int main()
{
	string a = "aba";
	string b = "ball";
	string c = "abc";
	string d = "abba";

	cout << isPolyndrom(a) << endl;
	cout << isPolyndrom(b) << endl;
	cout << isPolyndrom(c) << endl;
	cout << isPolyndrom(d) << endl;

	return 0;
}

bool isPolyndrom(string str) {
	for (int i = 0; i < str.size()/2; i++)
	{
		if (str.at(i) != str.at(str.size()-i-1))
		{
			return 0;
		}
	}
	return 1;
}