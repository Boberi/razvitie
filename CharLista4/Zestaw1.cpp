#include <iostream>

char* copy(const char* zrodlo)
{
	char* cel = new char[64];
	int i = 0;
	for (; zrodlo[i] != 0; ++i)
	{
		cel[i] = std::toupper(zrodlo[i]);
	}
	cel[i] = 0;
	return cel;
}

char* wstaw(const char* zrodlo, char symbol)
{
	int size = 2;
	for (int k = 0; zrodlo[k] != 0; ++k)
	{
		size++;
	}
	size += size / 3;

	char* result = new char[size];
	int i = 0;
	int mod = 0;
	for (; zrodlo[i] != 0; ++i, ++mod)
	{
		if (i % 3 == 0)
		{
			result[mod] = symbol;
			++mod;
		}
		result[mod] = zrodlo[i];
	}
	result[mod] = '\0';
	return result;
}

void wstaw1(char*& cel, const char* zrodlo, char symbol)
{
	int i = 0;
	int mod = 0;
	int size = 2;
	for (int k = 0; zrodlo[k] != 0; ++k)
	{
		size++;
	}
	size += size / 3;

	cel = new char[size];
	for (; zrodlo[i] != 0; ++i, ++mod)
	{
		if (i % 3 == 0)
		{
			cel[mod] = symbol;
			++mod;
		}
		cel[mod] = zrodlo[i];
	}
	cel[mod] = '\0';
}

void wstaw(char* cel, const char* zrodlo, char symbol)
{
	int i = 0;
	int mod = 0;
	for (; zrodlo[i] != 0; ++i, ++mod)
	{
		if (i % 3 == 0)
		{
			cel[mod] = symbol;
			++mod;
		}
		cel[mod] = zrodlo[i];
	}
	cel[mod] = '\0';
}

int szukaj(const char* zrodlo, char symbol)
{
	int result = 0;
	for (int i = 0; zrodlo[i] != 0; ++i)
	{
		if (zrodlo[i] == symbol)
		{
			result++;
		}
	}
	return result;
}

int main(int argc, char* argv[])
{
	const char* a = wstaw(argv[1], argv[2][0]);
	char *b, *c;
	b = new char[64];
	wstaw(b, argv[1], argv[2][0]);
	wstaw1(c, argv[1], argv[2][0]);
	std::cout << b << std::endl;
	std::cout << a << std::endl;
	std::cout << c << std::endl;
	std::cout << szukaj(a, 's') << std::endl;
	delete[] a;
	a = copy(argv[1]);
	std::cout << a << std::endl;
	delete[] a;
	delete[] b;
	delete[] c;
}
