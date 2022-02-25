#include <iostream>

using namespace std;

void fillArr(unsigned *T, const unsigned n){
    for (unsigned i = 0; i < n; i++){
        if  (i % 2 == 0){
            T[i] = 2;
        } else {
            T[i] = 0;
        }
    }
}

void printArr(unsigned* T, const unsigned n) {
    for (unsigned i = 0; i < n; i++)
    {
        cout << T[i] << " ";
    }
}

int main(){
    const unsigned n = 10;
    unsigned T[n];
    fillArr(T, n);
    printArr(T, n);
    return 0;
}