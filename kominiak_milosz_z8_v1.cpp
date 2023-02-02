#include <iostream>
#include <ctime>

const int N = 4;

struct Student
{
    char name, surname;
    double points;
};

double fillStudentArr(Student A[N], double &studentAvg)
{
    const int Max = 5;
    double studentSum = 0, studentMax = 0;
    for (int i = 0; i < N; i++)
    {
        A[i] = {char('A' + rand() % ('Z' + 1 - 'A')),
                char('A' + rand() % ('Z' + 1 - 'A')),
                rand() / double(RAND_MAX) * Max};
        std::cout << A[i].name << A[i].surname << " " << A[i].points << "\t";
        studentSum += A[i].points;
        if (A[i].points > studentMax)
            studentMax = A[i].points;
    }
    std::cout << std::endl;
    studentAvg = studentSum / N;
    return studentMax;
}

int main()
{
    double studentAvgG1 = 0, studentAvgG2 = 0;
    Student G1[N], G2[N];
    srand(time(0));
    std::cout << fillStudentArr(G1, studentAvgG1) - fillStudentArr(G2, studentAvgG2) << std::endl;
    if (studentAvgG1 > studentAvgG2)
        std::cout << "W tablicy G1 jest wyzsza srednia ocen i wynosi ona: " << studentAvgG1 << std::endl;
    else if (studentAvgG1 == studentAvgG2)
        std::cout << "W tablicach G1 i G2 srednia ocen jest jednakowa :o - wynosi ona: " << studentAvgG1 << std:: endl;
    else
        std::cout << "W tablicy G2 jest wyzsza srednia ocen i wynosi ona: " << studentAvgG2 << std::endl;
}
