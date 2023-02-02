#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    const int W = 5, K = 3, Wi = 5;
    float A[W][K], row_sum = 0, row_avg, col_max = 0, max[K];

    srand(time(0));
    for (int i = 0; i < W; i++)
        for (int j = 0; j < K; j++)
            A[i][j] = rand() / double(RAND_MAX) * 5;

    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < K; j++)
        {
            cout << setprecision(2) << fixed << setw(Wi) << A[i][j];
            row_sum += A[i][j];
        }
        row_avg = row_sum / K;
        cout << " Srednia: " << row_avg << endl;

        for (int j = 0; j < K; j++)
        {
            if (A[i][j] < row_avg)
                A[i][j] = row_avg;
        }
        row_sum = 0;
    }
    cout << endl;
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < K; j++)
            cout << setprecision(2) << fixed << setw(Wi) << A[i][j];
        cout << endl;
    }
    for (int j = 0; j < K; j++)
    {
        col_max = A[0][j];
        for (int i = 0; i < W; i++)
        {
            if (A[i][j] > col_max)
                col_max = A[i][j];
        }
        max[j] = col_max;
    }
    cout << "Maks: \n";
    for (int i = 0; i < K; i++)
    {
        cout << setprecision(2) << fixed << setw(Wi) << max[i];
    }
}