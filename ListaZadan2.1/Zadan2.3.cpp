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
    int T[20];
    printArr(T, 20);
}
