#include <iostream>

int main()
{
    int input, max, higherThanPreviousCount = 0, count = 0, previous, sum = 0;
    double avg;
    const int D = 5;
    if (D == 0)
    {
        std::cout << "Stala nie moze byc rowna 0";
        return 0;
    }
    std::cout << "Wypisz liczbe calkowita\n";
    std::cin >> input;
    max = input;
    if (-10 < input && input < 10)
    {
        sum += input;
        count = 1;
    }
    while (input % D != 0)
    {
        previous = input;
        std::cout << "Wypisz kolejna liczbe calkowita\n";
        std::cin >> input;
        if (input > max)
        {
            max = input;
        }
        if (-10 < input && input < 10)
        {
            sum += input;
            count++;
        }
        if (input > previous)
        {
            higherThanPreviousCount++;
        }
    }

    printf("Wypisales liczbe calkowita podzielna przez %d.\n\ 
Najwieksza wczytana liczba: %d\n\
Tyle liczb bylo wiekszych od swojego poprzednika: %d\n",
           D, max, higherThanPreviousCount);
    if (count != 0)
    {
        std::cout << "Srednia wszystkich liczb jednocyfrowych: " << sum / double(count) << std::endl;
    }
    else
    {
        std::cout << "Nie bylo liczb jednocyfrowych, nie moge obliczyc sredniej\n";
    }
    return 1;
}