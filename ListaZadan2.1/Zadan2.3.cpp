#include <iostream>

using namespace std;

void printArr(int* T, unsigned n){
    int number = -5;
    for (unsigned i = 0; i < n; i++)
    {
        T[i] = number;
        number++;
        cout << T[i] << " ";
    }
}

int main()
{
    const unsigned n = 20; // n > 0
    int T[n];
    printArr(T, n);
    return 0;
}
