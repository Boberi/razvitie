#include <iostream>

void wypisz(const int *t, const unsigned n){
	for (unsigned i = 0; i < n; ++i)
	{
		std::cout << t[i] << " ";
	}
}

int* utworz1(const unsigned n){
	int *t = new int[n];
	for (unsigned i = 0; i < n; ++i)
	{
		t[i] = 0;
	}
	return t;
}

void utworz2(int*& t, const unsigned n){
	delete t;
	t = new int[n]; 
	for (unsigned i = 0; i < n; ++i)
	{
	t[i] = 0;
	}
}

void utworz3(int* t, const unsigned n){
	for (unsigned i = 0; i < n; i++)
	{
		t[i] = 0;
	}
	
}

void usun(int *t){
	if(t){
		delete[] t;
		t = nullptr;
		}
}

void zad4(int* t, const unsigned n){
		for (unsigned i = 0; i < n; i++)
		{
			if (i < n / 2) {
				t[i] = 0;
			} else {
				t[i] = i + 1;
			}
		}
		
}

void zad5(int *t, const unsigned n){
		for (unsigned i = 0; i < n; i++)
		{
			t[i] = rand() % 100;
		}
		
}

void zad6(int *t, const unsigned n){
		int a, b;
		std::cout << "Min: ";
		std::cin >> a;
		std::cout << "Max: ";
		std::cin >> b;
		for (unsigned i = 0; i < n; i++)
		{
			t[i] = a + (rand() % (b - a + 1));
		}
}

int* suma1(const int* t1, const int* t2, const unsigned n){
	int* result = new int(0);
	for (unsigned i = 0; i < n; i++)
	{
		*result += t1[i] + t2[i];
	}
	return result;
}

void suma2(const int* t1, const int* t2, int*& t3, const unsigned n){
		delete t3;
		t3 = new int(0);
		for (unsigned i = 0; i < n; i++)
		{
			*t3 += t1[i] + t2[i];
		}
}
void suma3(const int* t1, const int* t2, int* t3, const unsigned n){
        delete t3;
		*t3 = 0;
		for (unsigned i = 0; i < n; i++)
		{
			*t3 += t1[i] + t2[i];
		}
}

void usunElement(int *& t, unsigned& n){
	wypisz(t, n);
	int element = 0;
	unsigned index = 0;
	bool choose = true;
	int *buff = new int[n - 1];
	while(choose){
			std::cout <<"\nWybierz: ";
			std::cin >> element;
			for (unsigned i = 0; i < n; i++)
			{
				if (t[i] == element)
				{
					choose = false;
					index = i;
					break;
				}
			}
	}
	for (unsigned i = 0; i < n - 1; i++)
	{
		if (i >= index)
		{
			buff[i] = t[i + 1];
		} else{
			buff[i] = t[i];
		}
	}
	std::cout << "\n";
	usun(t);
	t = buff;
	wypisz(t, n - 1);
	n--;
}

void dodajElement(int*&t, unsigned& n){
	wypisz(t, n);
	int element;
	int* buff = new int[n + 1];
	std::cout << "\nWypisz: ";
	std::cin >> element;
	buff[0] = element;
	for (unsigned i = 1; i < n + 1; i++)
	{
		buff[i] = t[i - 1];
	}
	usun(t);
	t = buff;
	wypisz(t, n + 1);
	n++;
	
}

int main(){
	unsigned n;
	std::cout << "Rozmiar : ";
	std::cin >> n;
	int *a = utworz1(n);
	wypisz(a, n);
	zad5(a, n);
	std::cout << "\n";
	dodajElement(a, n); 
	usun(a);	
}
