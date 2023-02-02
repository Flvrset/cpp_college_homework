#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

struct Student
{
    char name, surname;
    double points;
};

int main()
{
    const int W = 4, K = 4, G = 8;
    Student A[W][K], best_student, worst_student, temp;
    int best_student_row=0, best_student_column=0, worst_student_row=1, worst_student_column=1;

    srand(time(0));
    for (int i = 0; i < W; i++)
        for (int j = 0; j < K; j++)
            A[i][j] = {char('A' + rand() % ('Z' + 1 - 'A')),
                       char('A' + rand() % ('Z' + 1 - 'A')),
                       rand() / double(RAND_MAX) * G};

    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < K; j++)
            cout << A[i][j].name << A[i][j].surname << " " << setprecision(2) << fixed << A[i][j].points << "\t";
        cout << endl;
    }
    best_student = A[0][0];
    if (K < 2 && W < 2)
    {
        cout << "Tablica jest za mala.\n";
        return 0;
    }
    worst_student = A[1][1];
    for (int i = 0; i < W; i++)
        for (int j = 0; j < K; j++)
        {
            if (i == 0 || i == W - 1 || (i != 0 && i != W - 1 && (j == 0 || j == K - 1)))
            {
                if (A[i][j].points > best_student.points)
                {
                    best_student = A[i][j];
                    best_student_column = j;
                    best_student_row = i;
                }
            }
            else
            {
                if (A[i][j].points < worst_student.points)
                {
                    worst_student = A[i][j];
                    worst_student_column = j;
                    worst_student_row = i;
                }
            }
        }
    printf("Polozenie najlepszego studenta na obwodzie tablicy: [%d,%d]\n\
Polozenie najslabszego studenta wewnatrz tablicy: [%d,%d]\n",
           best_student_row, best_student_column, worst_student_row, worst_student_column);
    temp = A[best_student_row][best_student_column];
    A[best_student_row][best_student_column] = A[worst_student_row][worst_student_column];
    A[worst_student_row][worst_student_column] = temp;
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < K; j++)
            cout << A[i][j].name << A[i][j].surname << " " << setprecision(2) << fixed << A[i][j].points << "\t";
        cout << endl;
    }
}