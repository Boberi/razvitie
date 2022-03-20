#include <iostream>


unsigned potega_10(unsigned n)
{
	unsigned liczba = 1;
	for (unsigned i = 0; i < n; ++i)
	{
		liczba *= 10;
	}
	return liczba;
}

unsigned ile_cyfr(unsigned n)
{
	unsigned result = 1;
	while (true)
	{
		if (n / 10.0 > 1.0)
		{
			result++;
			n = n / 10;
		}
		else
		{
			break;
		}
	}
	return result;
}

unsigned doklej_do_liczby(unsigned zrodlo, unsigned cyfra, bool na_poczatek = true)
{
	if (cyfra > 9) return zrodlo;
	double zr = zrodlo;
	if (na_poczatek)
	{
		unsigned n = ile_cyfr(zrodlo);
		for (unsigned i = 0; i < n; i++) zr = zr / 10.0;
		zr += cyfra;
		zr = zr * potega_10(n);
		zrodlo = static_cast<unsigned>(zr + 0.5);
	}
	else
	{
		zrodlo = zrodlo * 10 + cyfra;
		return zrodlo;
	}
	return zrodlo;
}

unsigned znak_na_cyfre(char n)
{
	if (n >= 48 && n <= 57)
	{
		return n - 48;
	}
	else
	{
		std::cerr << n << " nie jest cyfra\n";
		return 0;
	}
}

unsigned zamien_na_liczbe(const char zrodlo[])
{
	unsigned result = 0;
	for (unsigned i = 0; zrodlo[i] != 0; ++i)
	{
		result *= 10;
		result += znak_na_cyfre(zrodlo[i]);
	}
	return result;
}

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		char a[256];
		std::cout << "Ciag znakow: ";
		std::cin.getline(a, 256);
		std::cout << zamien_na_liczbe(a) << std::endl;
	}
	else if (argc == 2)
	{
		std::cout << zamien_na_liczbe(argv[1]) << std::endl;
	}
	else
	{
		std::cerr << "ERROR" << std::endl;
		return -1;
	}
	std::cout << "-------TEST-------\n";
	unsigned jakas_liczba = 1212;
	std::cout << doklej_do_liczby(jakas_liczba, 5) << std::endl;
	//56572
	std::cout << doklej_do_liczby(jakas_liczba, 1, false) << std::endl;
	//65721
	unsigned jakas_druga_liczba = zamien_na_liczbe("1234");
	std::cout << jakas_druga_liczba << std::endl;
	//1234
	jakas_druga_liczba = zamien_na_liczbe("1ert234");
	std::cout << jakas_druga_liczba << std::endl;
	return 0;
}
