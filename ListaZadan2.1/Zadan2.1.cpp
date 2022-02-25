#include <iostream>

using namespace std;

void write(unsigned n)
{
	for (unsigned i = 0; i < n; i++)
	{
		cout << "Roman Tosakov" << endl;
	}
}


int main()
{
	unsigned n;
	cout << "Write number of lines: ";
	cin >> n;
	write(n);
}
