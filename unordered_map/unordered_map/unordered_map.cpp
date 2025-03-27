#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, long long> cache;

long long factorial(int n) {
	if (n == 0 || n == 1)
	{
		return 1;
	}

	if (cache.find(n) != cache.end())
	{
		return cache[n];
	}

	return cache[n] = n * factorial(n - 1);
}

int main()
{
	cout << factorial(5) << endl;
	cout << factorial(10) << endl;

	return 0;
}