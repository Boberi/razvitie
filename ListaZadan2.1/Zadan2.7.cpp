#include <iostream>

using namespace std;

void createArr(int *T, const unsigned n){
    for (unsigned i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            T[i] = i * 2;
        } else {
            T[i] = i;
        }
    }
}

void printArr(int* T, const unsigned n) {
    for (unsigned i = 0; i < n; i++)
    {
        cout << T[i] << " ";
    }
}

int main(){
    const unsigned n = 10;
    int T[n];
    createArr(T, n);
    printArr(T, n);
    return 0;
}