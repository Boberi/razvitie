#include <iostream>

void wypisz(int** t, const unsigned n, const unsigned m)
{
	for (unsigned i = 0; i < n; ++i)
	{
		for (unsigned j = 0; j < m; ++j)
		{
			std::cout << t[i][j] << "  ";
		}
		std::cout << "\n";
	}
}

int** utworz1(const unsigned n, const unsigned m)
{
	int** t = new int*[n];
	for (unsigned i = 0; i < n; ++i)
	{
		t[i] = new int[m];
		for (unsigned j = 0; j < m; ++j)
		{
			t[i][j] = 0;
		}
	}
	return t;
}

void utworz2(int**& t, const unsigned n, const unsigned m)
{
	t = new int*[n];
	for (unsigned i = 0; i < n; ++i)
	{
		t[i] = new int[m];
		for (unsigned j = 0; j < m; ++j)
		{
			t[i][j] = 0;
		}
	}
}

void utworz3(int** t, const unsigned n, const unsigned m)
{
	for (unsigned i = 0; i < n; ++i)
	{
		t[i] = new int[m];
		for (unsigned j = 0; j < m; ++j)
		{
			t[i][j] = 0;
		}
	}
}

void usun(int** t, const unsigned n)
{
	for (unsigned i = 0; i < n; ++i)
	{
		delete[] t[i];
	}
	delete[] t;
}

int** wypelnij(const unsigned n, const unsigned m)
{
	int max, min;
	std::cout << "Min: ";
	std::cin >> min;
	std::cout << "Max: ";
	std::cin >> max;
	int** t = new int*[n];
	for (unsigned i = 0; i < n; ++i)
	{
		t[i] = new int[m];
		for (unsigned j = 0; j < m; ++j)
		{
			t[i][j] = min + (rand() % (max - min + 1));
		}
	}
	return t;
}

int** sumMatrix(int** t1, int** t2, const unsigned n, const unsigned m)
{
	int** result = new int*[n];
	for (unsigned i = 0; i < n; ++i)
	{
		result[i] = new int[m];
		for (unsigned j = 0; j < m; ++j)
		{
			result[i][j] = t1[i][j] + t2[i][j];
		}
	}
	return result;
}

int** rozMatrix(int** t1, int** t2, const unsigned n, const unsigned m)
{
	int** result = new int*[n];
	for (unsigned i = 0; i < n; ++i)
	{
		result[i] = new int[m];
		for (unsigned j = 0; j < m; ++j)
		{
			result[i][j] = t1[i][j] - t2[i][j];
		}
	}
	return result;
}

int** iloczMatrix(int** t1, int** t2, const unsigned n1, const unsigned m1, const unsigned n2, const unsigned m2)
{
	if (n1 == m2)
	{
		int** result = utworz1(n1, m2);
		for (unsigned i = 0; i < n1; ++i)
		{
			for (unsigned j = 0; j < m2; ++j)
			{
				for (unsigned k = 0; k < m1; ++k)
				{
					result[i][j] += t1[i][k] * t2[k][j];
				}
			}
		}
		return result;
	}
	return new int*[4];
}

void transponMatrix(int**& t, unsigned& n, unsigned& m)
{
	int** result = utworz1(m, n);
	for (unsigned i = 0; i < n; ++i)
	{
		for (unsigned j = 0; j < m; ++j)
		{
			result[j][i] = t[i][j];
		}
	}
	t = result;
}

void tablica()
{
	unsigned a, b;
	std::cout << "Wpisz a: ";
	std::cin >> a;
	std::cout << "Wpisz b: ";
	std::cin >> b;
	int** t = utworz1(a, b);
	for (unsigned i = 0; i < a; ++i)
	{
		for (unsigned j = 0; j < b; ++j)
		{
			t[i][j] = (i + 1) * (j + 1);
		}
	}
	wypisz(t, a, b);
}

void iloczTest()
{
	unsigned n1, m1, n2, m2;
	std::cout << "Collumns: ";
	std::cin >> n1;
	std::cout << "Rows: ";
	std::cin >> m1;
	int** a = wypelnij(n1, m1);
	std::cout << "Collumns: ";
	std::cin >> n2;
	std::cout << "Rows: ";
	std::cin >> m2;
	int** b = wypelnij(n2, m2);
	wypisz(a, n1, m1);
	std::cout << "\n";
	wypisz(b, n2, m2);
	std::cout << "\n";
	int** result = iloczMatrix(a, b, n1, m1, n2, m2);
	wypisz(result, n1, m2);
}

void transposeTest()
{
	unsigned n1, m1, n2, m2;
	std::cout << "Collumns: ";
	std::cin >> n1;
	std::cout << "Rows: ";
	std::cin >> m1;
	int** a = wypelnij(n1, m1);
	wypisz(a, n1, m1);
	std::cout << "\n";
	transponMatrix(a, n1, m1);
	wypisz(a, m1, n1);
}

int main()
{
	tablica();
	return 0;
}
