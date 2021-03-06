#include <iostream>

using namespace std;

void readArr(int *T, const unsigned n){
    cout << "Write " << n << " number to the console.";
    for (unsigned i = 0; i < n; i++)
    {
        cout << i + 1<< ": ";
        cin >> T[i];
    }
}

int findMax(int *T, const unsigned n){
    int max = T[0];
    for (unsigned i = 1; i < n; i++)
    {
        if (T[i] > max)
        {
            max = T[i];
        }
        
    }
    return max;
    
}

int main(){
    const unsigned n = 5; // n > 0
    int T[n];
    readArr(T, n);
    cout << "Max number: " << findMax(T, n);
    return 0;
}