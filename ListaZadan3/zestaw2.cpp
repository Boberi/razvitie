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

void usun(int* t)
{
	if (t)
	{
		delete[] t;
		t = nullptr;
	}
}

void usunElement(int*& t, unsigned& n, const int element)
{
	unsigned index = 0;
	for (unsigned i = 0; i < n; i++)
	{
		if (t[i] == element)
		{
			index = i;
			break;
		}
	}
	int* buff = new int[n - 1];
	for (unsigned i = 0; i < n - 1; i++)
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
	usun(t);
	t = buff;
	n--;
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

bool checkResult(int*& t1, const int* t2, unsigned& table_size, const unsigned user_table_size)
{
	unsigned counter = 0;
	int element;
	for (unsigned i = 0; i < user_table_size; ++i)
	{
		for (unsigned j = 0; j < table_size; ++j)
		{
			if (t2[i] == t1[j])
			{
				counter++;
				element = t2[i];
				usunElement(t1, table_size, element);
				break;
			}
		}
	}
	if (counter >= 4) return true;
	return false;
}

void start()
{
	const unsigned user_table_size = 8;
	unsigned table_size = 49;
	int* game_table = createTable(table_size);
	const int* user_table = createUserTable(user_table_size);
	std::cout << "Game table: ";
	wypisz(game_table, table_size);
	std::cout << "\n";
	std::cout << "User table: ";
	wypisz(user_table, user_table_size);
	std::cout << "\n";
	if (checkResult(game_table, user_table, table_size, user_table_size))
	{
		std::cout << "You won\n";
	}
	else
	{
		std::cout << "You lose\n";
	}
	std::cout << "Game table after game: ";
	wypisz(game_table, table_size);
	std::cout << "\n";
	delete[] game_table;
	delete[] user_table;
}


int main()
{
	start();

	return 0;
}
