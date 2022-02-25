#include <iostream>

using namespace std;

void readArr(int *T, const unsigned n){
    cout << "Write " << n << " number to the console." << endl;
    for (unsigned i = 0; i < n; i++)
    {
        cout << i + 1<< ": ";
        cin >> T[i];
    }
}

float findAverage(int *T, const unsigned n){
    unsigned counter = 0;
    int sum = 0;
    for (unsigned i = 1; i < n; i++)
    {
        if (T[i] % 3 == 0)
        {
            sum += T[i];
            counter++;
        }
        
    }
    return (float) sum / counter;
    
}

int main(){
    const unsigned n = 5; // n > 0
    int T[n];
    readArr(T, n);
    cout << "Average: " << findAverage(T, n);
    return 0;
}