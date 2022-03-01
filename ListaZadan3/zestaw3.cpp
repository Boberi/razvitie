#include <iostream>
/*
Zadanie 1.
Zaprojektowa¢ i zaimplementowa¢ funkcj¦ obliczaj¡c¡ sum¦ dwóch liczb przekazanych,
jako parametry oraz zwracaj¡c¡ wynik tej operacji.
Zadanie 2.
Zaprojektowa¢ i zaimplementowa¢ funkcj¦ obliczaj¡c¡ ró»nic¦ dwóch liczb przekazanych,
jako parametry oraz zwracaj¡c¡ wynik tej operacji.
Zadanie 3.
Zaprojektowa¢ i zaimplementowa¢ funkcj¦ obliczaj¡c¡ iloczyn dwóch liczb przekazanych,
jako parametry oraz zwracaj¡c¡ wynik tej operacji.
Zadanie 4.
Zaprojektowa¢ i zaimplementowa¢ funkcj¦ obliczaj¡c¡ iloraz dwóch liczb przekazanych,
jako parametry oraz zwracaj¡c¡ wynik tej operacji.
Zadanie 5.
Zaprojektowa¢ i zaimplementowa¢ funkcj¦ obliczaj¡c¡ kwadrat liczby przekazanej, jako
parametr oraz zwracaj¡c¡ wynik tej operacji.
Zadanie 6.
Zaprojektowa¢ i zaimplementowa¢ funkcj¦ obliczaj¡c¡ sze±cian liczby przekazanej, jako
parametr oraz zwracaj¡c¡ wynik tej operacji.
Zadanie 7.
Zaprojektowa¢ i zaimplementowa¢ funkcj¦ obliczaj¡c¡ warto±¢ poni»szego wyra»enia dla
liczby przekazanej, jako parametr oraz zwracaj¡c¡ wynik tej operacji.
f(x)
Zadanie 8.
Zaprojektowa¢ i zaimplementowa¢ funkcj¦ obliczaj¡c¡ obwód trójk¡ta dla dªugo±ci boków
przekazanych, jako parametry oraz zwracaj¡c¡ wynik tej operacji.
Zadanie 9.
Zaprojektowa¢ i zaimplementowa¢ funkcj¦ obliczaj¡c¡ pole trójk¡ta dla dªugo±ci boków
przekazanych, jako parametry oraz zwracaj¡c¡ wynik tej operacji. W zadaniu nale»y wykorzysta¢ funkcj¦ zwracaj¡c¡ obwód trójk¡ta (wzór Herona).
Zadanie 10.
Zaprojektowa¢ i zaimplementowa¢ funkcj¦, z wykorzystaniem instrukcji wyboru switch,
symuluj¡c¡ dziaªanie kalkulatora oferuj¡cego dziaªania okre±lone wszystkimi wcze±niej
zaimplementowanymi funkcjami. Program powinien posiada¢ menu umo»liwiaj¡ce wybór
*/

float sum(float a, float b){
    return a + b;
}

float roznic(float a, float b){
    return a - b;
}

float iloczyn(float a, float b){
    return a * b;
}

float iloraz(float a, float b){
    return a / b;
}

float kwadrat(float a){
    return iloczyn(a, a);
}

float szeszcian(float a){
    return iloczyn(a, kwadrat(a));
}

float fun(float a){
    return (float) iloczyn(sum(iloczyn(10, szeszcian(a)), iloczyn(2.5, kwadrat(a))), roznic(iloraz(a, 2), iloraz(1, kwadrat(a))));
}

float obwod(float a, float b, float c){
    return sum(sum(a,b),c);
}

float korzen(float a)
{
    float error = 0.00001f; 
    float s = a;
    float b;
    while ((roznic(s, iloraz(a , s))) > error)
    {
        b = sum(s, iloraz(a, s));
        s = iloraz(b, 2.0f);
    }
    return s;
}

float pole(float a, float b, float c){
    float p = iloraz(obwod(a, b, c), 2.0f);
    float pole = korzen(iloczyn(
        iloczyn(
            iloczyn(
                roznic(p, b), roznic(p, c)
                ), roznic(p, a)), p));
    return pole;
}

void kalkulator(){
    while (true)
    {
        int n , a , b, c;
        std::cout << "Kalkulator \n1: Summa \n2: Roznica \n3: Iloczyn \n4: Iloraz \n5: Kwadrat \n6: Szeszcian \n7: Func \n8: Obwod \n9: Pole \n0: Exit \n";
        std::cin >> n;
        switch (n)
        {
        case 1:
            std::cout << "a: ";
            std::cin >> a;
            std::cout << "b: ";
            std::cin >> b;
            std::cout << "Wynik: " << sum(a, b) << std::endl;
            break;
        case 2:
            std::cout << "a: ";
            std::cin >> a;
            std::cout << "b: ";
            std::cin >> b;
            std::cout << "Wynik: " << roznic(a, b) << std::endl;
            break;
        case 3:
            std::cout << "a: ";
            std::cin >> a;
            std::cout << "b: ";
            std::cin >> b;
            std::cout << "Wynik: " << iloczyn(a, b) << std::endl;
            break;
        case 4:
            std::cout << "a: ";
            std::cin >> a;
            std::cout << "b: ";
            std::cin >> b;
            std::cout << "Wynik: " << iloraz(a, b) << std::endl;
            break;
        case 5:
            std::cout << "a: ";
            std::cin >> a;
            std::cout << "Wynik: " << kwadrat(a) << std::endl;
            break;
        case 6:
            std::cout << "a: ";
            std::cin >> a;
            std::cout << "Wynik: " << szeszcian(a) << std::endl;
            break;
        case 7:
            std::cout << "a: ";
            std::cin >> a;
            std::cout << "Wynik: " << fun(a) << std::endl;
            break;
        case 8:
            std::cout << "a: ";
            std::cin >> a;
            std::cout << "b: ";
            std::cin >> b;
            std::cout << "c: ";
            std::cin >> c;
            std::cout << "Wynik: " << obwod(a, b, c) << std::endl;
            break;
        case 9:
            std::cout << "a: ";
            std::cin >> a;
            std::cout << "b: ";
            std::cin >> b;
            std::cout << "c: ";
            std::cin >> c;
            std::cout << "Wynik: " << pole(a, b, c) << std::endl;
            break;
        case 0:
            return;        
        default:
            break;
        }
    }
    
}


int main (){
    kalkulator();
    return 0;
}

