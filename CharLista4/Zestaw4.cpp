#include <iostream>
#include <string.h>

void wypisz_tablice_2d(unsigned** tab_2d, unsigned wiersze, unsigned kolumny)
{
	for (unsigned i = 0; i < wiersze; ++i)
	{
		for (unsigned j = 0; j < kolumny; ++j)
		{
			std::cout << "[" << tab_2d[i][j] << "]";
		}
		std::cout << std::endl;
	}
}

unsigned ile_wystapien_znaku(std::string zrodlo, const char znak)
{
	unsigned counter = 0;
	for (unsigned i = 0; i != zrodlo.size(); ++i)
	{
		if (zrodlo[i] == znak)
		{
			counter++;
		}
	}
	return counter;
}

unsigned znak_na_numer(char znak)
{
	if (znak >= 97 && znak <= 122)
	{
		return znak - 97;
	}
	return 111;
}

void statystyka(unsigned* t, std::string napis)
{
	char znak;
	for (unsigned i = 0; i < 26; ++i)
	{
		znak = i + 97;
		t[i] = ile_wystapien_znaku(napis, znak);
	}
}

unsigned** statystyki(std::string napisy[], const unsigned rozmiar)
{
	unsigned** tabl = new unsigned*[rozmiar];
	for (unsigned i = 0; i < rozmiar; ++i)
	{
		tabl[i] = new unsigned[26];
		statystyka(tabl[i], napisy[i]);
	}
	return tabl;
}

void usun(unsigned** t, unsigned rozmiar)
{
	if (t)
	{
		for (unsigned i = 0; i < rozmiar; ++i)
		{
			delete[] t[i];
		}
		delete[] t;
		t = nullptr;
	}
}

int main()
{
	std::string napisy[] = {"ala ma", "kota", "abcdefghijklmnopqrstuvwxyz"};
	unsigned** statsy = statystyki(napisy, 3);
	wypisz_tablice_2d(statsy, 3, 26);
	usun(statsy, 3);
}
