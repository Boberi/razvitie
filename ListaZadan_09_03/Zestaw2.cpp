#include <iostream>

int* createTable(const unsigned n)
{
	int a, b;
	std::cout << "Napisz min: ";
	std::cin >> a;
	std::cout << "Napisz max: ";
	std::cin >> b;
	int* t = new int[n];
	for (unsigned i = 0; i < n; ++i)
	{
		t[i] = a + (rand() % (b - a + 1));
	}
	return t;
}

int* createUserTable(const unsigned n)
{
	int* t = new int[n];
	for (unsigned i = 0; i < n; ++i)
	{
		std::cin >> t[i];
	}
	return t;
}

void wypisz(const int* t, const unsigned int n)
{
	for (unsigned i = 0; i < n; ++i)
	{
		std::cout << t[i] << " ";
	}
}

bool checkResult(const int* t1, const int* t2, const unsigned n)
{
	for (unsigned i = 0; i < n; ++i)
	{
		if (t1[i] == t2[i])
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int* a = createTable(10);
	int* b = createUserTable(10);
	wypisz(a, 10);
	std::cout << "\n";
	wypisz(b, 10);
	std::cout << "\n";
	if (checkResult(a, b, 10))
	{
		std::cout << "You won";
	}
	else
	{
		std::cout << "You lose";
	}

	return 0;
}
