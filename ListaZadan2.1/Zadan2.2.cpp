#include <iostream>

using namespace std;

int max(int a, int b, int c)
{
	if (a > b && a > c)
	{
		return a;
	}
	if (b > a && b > c)
	{
		return b;
	}
	return c;
}

int main()
{
	int a, b, c;
	cout << "a: ";
	cin >> a;
	cout << endl << "b: ";
	cin >> b;
	cout << endl << "c: ";
	cin >> c;
	cout << endl << "Max: " << max(a, b, c);
}