#include <iostream>
#include <math.h>

int main()
{
    int a, b, c, d, max1, max2;
    double suma;
    char answer;
    std::cout << "Wypisz kolejno 4 liczby calkowite:\n";
    std::cin >> a >> b >> c >> d;
    if (a >= b)
    {
        max1 = a;
        max2 = b;
    }
    else
    {
        max1 = b;
        max2 = a;
    }
    if (c > max1)
    {
        max2 = max1;
        max1 = c;
    }
    else if (c > max2)
    {
        max2 = c;
    }
    if (d > max1)
    {
        max2 = max1;
        max1 = d;
    }
    else if (d > max2)
    {
        max2 = d;
    }

    std::cout << "Najwieksze liczby to: " << max1 << " i " << max2 << std::endl;

    if (max1 - max2 == 0)
    {
        std::cout << "Roznica tych dwoch liczb jest rowna 0. Koncze dzialanie." << std::endl;
        return 0;
    }

    suma = (max1 + max2) / double(max1 - max2);

    printf("Wypisac wynik (%d + %d) / (%d - %d) w postaci:\na) niepoprawnej (wynik obciety)\nb) poprawnej (wynik dokladny)\n", max1, max2, max1, max2);
    std::cin >> answer;
    if (answer == 'a')
    {
        std::cout << "Wypisuje wynik w postaci niepoprawnej (wynik obciety)\n"
                  << int(suma) << std::endl;
        return 1;
    }
    else if (answer == 'b')
    {
        std::cout << "Wypisuje wynik w postaci poprawnej (wynik dokladny)\n"
                  << suma << std::endl;
        return 1;
    }
    else
    {
        std::cout << "Niepoprawna odpowiedz\n";
        return 0;
    }
}