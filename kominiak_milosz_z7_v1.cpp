#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int W = 4, K = 5;

void fillArrWithRandomChars(char start, char end, char A[W][K])
{
    srand(time(0));
    for (int i = 0; i < W; i++)
        for (int j = 0; j < K; j++)
            A[i][j] = start + rand() % (end + 1 - start);
}

void printArr(char A[W][K])
{
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < K; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void fillRowIfNoChar(char A[W][K], char filler, char charToSearch)
{
    bool containsChar;
    int index;

    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < K; j++)
        {
            if (A[i][j] == charToSearch)
            {
                containsChar = true;
                index = i;
            }
        }
        if (!containsChar)
        {
            for (int j = 0; j < K; j++)
                A[i][j] = filler;
        }
        containsChar = false;
    }
}

int main()
{
    char Li[W][K], Cy[W][K];

    fillArrWithRandomChars('A', 'Z', Li);
    fillArrWithRandomChars('0', '9', Cy);
    printArr(Li);
    printArr(Cy);
    fillRowIfNoChar(Li, '%', 'P');
    fillRowIfNoChar(Cy, '&', '5');
    printArr(Li);
    printArr(Cy);
}