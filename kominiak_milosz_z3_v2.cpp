#include <iostream>
#include <string>

int main()
{
    int k, stringCount = 0, stringLengths = 0;
    const int N = 5;
    char character, list[N], storage;
    std::string slowo;
    do
    {
        std::cout << "Wypisz liczbe calkowita dodatnia:\n";
        std::cin >> k;
    } while (k > 10 || k <= 0);
    switch (k)
    {
    case 1:
        std::cout << "Wypisz slowo\n";
        break;
    case 2:
    case 3:
    case 4:
        std::cout << "Wypisz " << k << " slowa\n";
        break;
    default:
        std::cout << "Wypisz " << k << " slow\n";
        break;
    }
    for (int i = 0; i < k; i++)
    {
        std::cin >> slowo;
        if (slowo[0] == slowo.back())
        {
            stringCount++;
            stringLengths += slowo.length();
        }
    }
    if (stringCount != 0)
    {
        std::cout << "Srednia dlugosc napisow, w ktorych pierwszy i ostatni znak sa takie same to: " << stringLengths / float(stringCount) << std::endl;
    }
    else
    {
        std::cout << "Brak slow, ktore koncza i zaczynaja sie na ta sama litere\n";
    }
    switch (N)
    {
    case 1:
        std::cout << "Wypisz znak\n";
        break;
    case 2:
    case 3:
    case 4:
        std::cout << "Wypisz " << N << " znaki:\n";
        break;
    default:
        std::cout << "Wypisz " << N << " znakow:\n";
    }
    for (int i = 0; i < N; i++)
    {
        std::cin >> character;
        list[i] = character;
    }
    std::cout << "Tablica: \n";
    for (int i = 0; i < N; i++)
    {
        std::cout << list[i];
    }
    storage = list[N - 1];
    for (int i = N; i > 0; i--)
    {
        list[i] = list[i - 1];
    }
    list[0] = storage;
    std::cout << "\nTablica przesunieta o jedno miejsce w prawo: \n";
    for (int i = 0; i < N; i++)
    {
        std::cout << list[i];
    }
}