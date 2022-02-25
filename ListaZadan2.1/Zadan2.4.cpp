#include <iostream>

using namespace std;

void fibb(unsigned* T, const unsigned n) {
    T[0] = 1;
    T[1] = 1;
    for (unsigned i = 2; i < n; i++) {
        T[i] = T[i - 1] + T[i - 2];
    }
}

void printArr(unsigned* T, const unsigned n) {
    for (unsigned i = 0; i < n; i++)
    {
        cout << T[i] << " ";
    }
}

int main() {
    const unsigned n = 10; // n > 2
    unsigned T[n];
    fibb(T, n);
    printArr(T, n);
    return 0;
}