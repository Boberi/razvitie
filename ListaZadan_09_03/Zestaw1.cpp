#include <iostream>

void wypisz(const int* t, const unsigned int n)
{
	for (unsigned i = 0; i < n; i++)
	{
		std::cout << t[i] << " ";
	}
}

int* utowrz1(const unsigned n)
{
	int* arr = new int[n];
	for (unsigned i = 0; i < n; ++i)
	{
		arr[i] = 0;
	}
	return arr;
}

void utworz2(int*& t, const unsigned n)
{
	t = new int[n];
	for (unsigned i = 0; i < n; ++i)
	{
		t[i] = 0;
	}
}

void utworz3(int* t, const unsigned n)
{
	for (unsigned i = 0; i < n; ++i)
	{
		t[i] = 0;
	}
}

void zad4(int* t, const unsigned n)
{
	for (unsigned i = 0; i < n; ++i)
	{
		if (i < n / 2)
		{
			t[i] = 0;
		}
		else
		{
			t[i] = i + 1;
		}
	}
}

void zad5(int* t, const unsigned n)
{
	for (unsigned i = 0; i < n; ++i)
	{
		t[i] = rand() % 100;
	}
}

void zad6(int* t, const unsigned n)
{
	int a, b;
	std::cout << "Napisz min: ";
	std::cin >> a;
	std::cout << "Napisz max: ";
	std::cin >> b;
	for (unsigned i = 0; i < n; ++i)
	{
		t[i] = a + (rand() % (b - a + 1));
	}
}

int* suma1(const int* t1, const int* t2, const unsigned n)
{
	int* suma = new int(0);
	for (unsigned i = 0; i < n; ++i)
	{
		*suma += t1[i] + t2[i];
	}
	return suma;
}

void suma2(const int* t1, const int* t2, int*& t3, const unsigned n)
{
	*t3 = 0;
	for (unsigned i = 0; i < n; ++i)
	{
		*t3 += t1[i] + t2[i];
	}
}

void suma3(const int* t1, const int* t2, int* t3, const unsigned n)
{
	*t3 = 0;
	for (unsigned i = 0; i < n; ++i)
	{
		*t3 += t1[i] + t2[i];
	}
}

void deleteElement(int*& t, unsigned& n)
{
	wypisz(t, n);
	int element, index;
	bool choose = true;
	int* buff = new int[n - 1];
	while (choose)
	{
		std::cout << "\nWybierz element: ";
		std::cin >> element;

		for (unsigned i = 0; i < n; ++i)
		{
			if (t[i] == element)
			{
				choose = false;
				index = i;
				break;
			}
		}
	}
	for (unsigned i = 0; i < n - 1; ++i)
	{
		if (i >= index)
		{
			buff[i] = t[i + 1];
		}
		else
		{
			buff[i] = t[i];
		}
	}
	t = buff;
	n--;
}

void wpisz(int*& t, unsigned& n)
{
	wypisz(t, n);
	int element;
	bool choose = true;
	int* buff = new int[n + 1];
	std::cout << "\nNapisz element: ";
	std::cin >> element;
	buff[0] = element;
	for (unsigned i = 1; i < n + 1; ++i)
	{
		buff[i] = t[i - 1];
	}
	t = buff;
	n++;
}


int main()
{
	unsigned n;
	std::cout << "Rozmiar: ";
	std::cin >> n;

	int* a = new int[n];
	int* t3 = new int(0);
	zad5(a, n);
	wpisz(a, n);
	wypisz(a, n);
	delete[] a;
	return 0;
}
