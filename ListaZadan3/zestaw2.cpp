#include <iostream>

/*
Zadanie 1.
Zaprojektowa¢ i zaimplementowa¢ funkcj¦ przyjmuj¡c¡, jako argumenty dwie liczby caªkowite i zamieniaj¡c¡ miejscami warto±ci tych liczb. Argumenty przekaza¢ poprzez warto±¢.
void zamien1(int a, int b);
Zadanie 2.
Zaprojektowa¢ i zaimplementowa¢ funkcj¦ przyjmuj¡c¡, jako argumenty dwie liczby caªkowite i zamieniaj¡c¡ miejscami warto±ci tych liczb. Argumenty przekaza¢ poprzez wska¹nik.
void zamien2(int* a, int* b);
Zadanie 3.
Zaprojektowa¢ i zaimplementowa¢ funkcj¦ przyjmuj¡c¡, jako argumenty dwie liczby caªkowite i zamieniaj¡c¡ miejscami warto±ci tych liczb. Argumenty przekaza¢ poprzez referencj¦.
void zamien3(int& a, int& b);
*/

void zamien1(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}


void zamien2(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void zamien3(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int a = 5;
    int b = 10;
    zamien3(a, b);
    std::cout << a << std::endl << b;
    return 0;
}