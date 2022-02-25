#include <iostream>

using namespace std;

int fibbSum(unsigned* T, const unsigned n) {
    T[0] = 1;
    T[1] = 1;
    unsigned sum = 2;
    for (unsigned i = 2; i < n; i++) {
        T[i] = T[i - 1] + T[i - 2];
        sum += T[i];
    }
    return sum;
}

int main() {
    const unsigned n = 4; // n > 2
    unsigned T[n];
    cout << fibbSum(T, n);
    return 0;
}