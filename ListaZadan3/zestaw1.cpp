#include <iostream>

/*
Zadanie 1.
Zaprojektowa¢ i zaimplementowa¢ funkcj¦ wyznaczaj¡c¡ rekurencyjnie warto±¢ silni z
liczby podanej przez u»ytkownika.
Zadanie 2.
Zaprojektowa¢ i zaimplementowa¢ funkcj¦ wyznaczaj¡c¡ iteracyjnie warto±¢ silni z liczby
podanej przez u»ytkownika.
Zadanie 3.
Zaprojektowa¢ i zaimplementowa¢ funkcj¦ wyznaczaj¡c¡ rekurencyjnie warto±¢ n-tego wyrazu ci¡gu Fibonacciego.
Zadanie 4.
Zaprojektowa¢ i zaimplementowa¢ funkcj¦ wyznaczaj¡c¡ iteracyjnie warto±¢ n-tego wyrazu ci¡gu Fibonacciego.
*/

long rekurSilnia(int a){

    if (a == 0)
    {
        return 1;
    }
    return rekurSilnia(a - 1) * a;

}

long iterSilnia(int a){

    long result = 1;
    for (int i = 1; i <= a; i++)
    {
        result *= i;
    }
    return result;

}

int rekurFibb(int a){

    if (a == 1 || a == 2 || a == 0)
    {
        return 1;
    }
    return rekurFibb(a - 1) + rekurFibb(a - 2);
    
}

int iterFibb(int a){

    int secondNumber, firstNumber = 0, currentNumber = 1;

        for (int i = 1; i < a ; i++) {
            secondNumber = firstNumber;
            firstNumber = currentNumber;
            currentNumber = secondNumber + firstNumber;
        }
        return currentNumber;

}

int main(){
    std::cout << iterFibb(8) << std::endl;
    std::cout << rekurFibb(5) << std::endl;
    std::cout << iterSilnia(8) << std::endl;
    std::cout << rekurSilnia(5) << std::endl;
    return 0;
}