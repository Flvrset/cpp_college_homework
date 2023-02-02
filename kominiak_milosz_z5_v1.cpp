#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    const int N = 4, C = 2, P = 2, W = 10;
    double A[N][N], min_double;
    int min_row;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            A[i][j] = C;
    ifstream input_file("DaneR.txt");
    ofstream output_file;
    string output_file_name;

    if (!input_file.is_open())
    {
        cout << "Blad wczytania pliku" << endl;
        return 0;
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            input_file >> A[i][j];
    input_file.close();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << setprecision(P) << fixed << setw(W) << A[i][j];
        cout << endl;
    }
    min_double = A[0][0];
    for (int i = 0; i < N; i++)
    {
        if (A[i][i] < min_double)
        {
            min_double = A[i][i];
            min_row = i;
        }
    }
    for (int j = 0; j < N; j++)
        A[min_row][j] = min_double;

    // use min_double as a storage since it is no longer used
    min_double = A[0][N - 1];
    A[0][N - 1] = A[N - 1][0];
    A[N - 1][0] = min_double;

    cout << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << setprecision(P) << fixed << setw(W) << A[i][j];
        cout << endl;
    }

    cout << "Do jakiego pliku zapisac dane?\n";
    getline(cin, output_file_name);

    output_file.open(output_file_name);
    for (int i = 0; i < N; i += 2)
    {
        for (int j = 0; j < N; j++)
            output_file << setprecision(P) << fixed << setw(W) << A[i][j];
        output_file << endl;
    }
    output_file.close();
}