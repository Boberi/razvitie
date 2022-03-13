#include <iostream>

int** createTable(const unsigned n)
{
	int a, b;
	std::cout << "Napisz min: ";
	std::cin >> a;
	std::cout << "Napisz max: ";
	std::cin >> b;
	int** t = new int*[n];
	for (unsigned i = 0; i < n; ++i)
	{
		t[i] = new int[50];
		t[i][0] = 50;
		for (int j = 1; j < t[i][0]; ++j)
		{
			t[i][j] = a + (rand() % (b - a + 1));
		}
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

void usunArr(int** t, unsigned coupons)
{
	for (unsigned i = 0; i < coupons; ++i)
	{
		delete[] t[i];
	}
	delete[] t;
}

void wypiszResult(int* t, unsigned coupons)
{
	for (unsigned i = 0; i < coupons; ++i)
	{
		if (t[i] == 1)
		{
			std::cout << "Coupon #" << (i + 1) << ": " << "Won" << std::endl;
		}
		else
		{
			std::cout << "Coupon #" << (i + 1) << ": " << "Lost" << std::endl;
		}
	}
}

void usunElement(int**& t, const int element, unsigned coupon)
{
	int index = 0;
	int n = t[coupon][0];
	for (int i = 1; i < n; i++)
	{
		if (t[coupon][i] == element)
		{
			index = i;
			break;
		}
	}
	int* buff = new int[n - 1];
	for (int i = 1; i < n - 1; i++)
	{
		if (i >= index)
		{
			buff[i] = t[coupon][i + 1];
		}
		else
		{
			buff[i] = t[coupon][i];
		}
	}
	buff[0] = n - 1;
	usun(t[coupon]);
	t[coupon] = buff;
}

int** createUserTable(const unsigned n, const unsigned m)
{
	int** t = new int*[n];
	for (unsigned i = 0; i < n; ++i)
	{
		std::cout << "Coupon #" << (i + 1) << ": ";
		t[i] = new int[m];
		for (unsigned j = 0; j < m; ++j)
		{
			std::cin >> t[i][j];
		}
	}
	return t;
}

void wypiszUserTable(int** t, int coupons, int m)
{
	for (int i = 0; i < coupons; ++i)
	{
		std::cout << "Coupon #" << (i + 1) << ": ";
		for (int j = 0; j < m; ++j)
		{
			std::cout << t[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void wypiszGameTable(int** t, const int n)
{
	for (int i = 0; i < n; ++i)
	{
		int size = t[i][0];
		std::cout << "Coupon #" << (i + 1) << ": ";
		for (int j = 1; j < size; ++j)
			std::cout << t[i][j] << " ";
		std::cout << std::endl;
	}
}

int* checkResult(int**& game_table, int** user_table, const int user_table_size,
                 const unsigned coupons)
{
	unsigned counter = 0;
	int element;
	int* result = new int[coupons];
	for (unsigned k = 0; k < coupons; ++k)
	{
		counter = 0;
		for (int i = 0; i < user_table_size; ++i)
		{
			int table_size1 = game_table[k][0];
			for (int j = 0; j < table_size1; ++j)
			{
				if (user_table[k][i] == game_table[k][j])
				{
					counter++;
					element = user_table[k][i];
					usunElement(game_table, element, k);
					break;
				}
			}
		}
		if (counter > 4)
		{
			result[k] = 1;
		}
		else
		{
			result[k] = 0;
		}
	}
	return result;
}

void start()
{
	const unsigned user_table_size = 8;
	unsigned coupons;
	std::cout << "Coupons: ";
	std::cin >> coupons;
	int** game_table = createTable(coupons);
	int** user_table = createUserTable(coupons, user_table_size);
	std::cout << "Game table: \n";
	wypiszGameTable(game_table, coupons);
	std::cout << "\n";
	std::cout << "User table: \n";
	wypiszUserTable(user_table, coupons, user_table_size);
	std::cout << "\n";
	int* result = checkResult(game_table, user_table, user_table_size, coupons);

	std::cout << "Game table after game: \n";
	wypiszGameTable(game_table, coupons);
	std::cout << "\n";
	wypiszResult(result, coupons);
	usunArr(game_table, coupons);
	usunArr(user_table, coupons);
	usun(result);
}


int main()
{
	start();

	return 0;
}
