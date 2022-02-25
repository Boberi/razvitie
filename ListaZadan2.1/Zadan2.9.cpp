#include <iostream>

using namespace std;

long long silnia(unsigned n){
    if (n == 1)
    {
        return 1;
    }
    return n * silnia(n - 1);
    
}


int main(){
    unsigned n;
    cout << "Write number: ";
    cin >> n;
    cout << silnia(n);
    return 0;
}