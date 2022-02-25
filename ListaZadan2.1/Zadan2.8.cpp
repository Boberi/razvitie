#include <iostream>

using namespace std;

long long silnia(const unsigned n){
    long long result = 1;
    for (unsigned i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
    
}

int main(){
    unsigned n;
    cout << "Write number: ";
    cin >> n;
    cout << silnia(n);
    return 0;
}