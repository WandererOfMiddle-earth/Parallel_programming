#include <fstream>
#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;

void multiply_matrices(const char* file_a, const char* file_b)
{
    int size_matrix = 0;

    ifstream in_a(file_a);
    in_a >> size_matrix;
    double** a;
    a = new double* [size_matrix];
    for (int i = 0; i < size_matrix; i++)
        a[i] = new double[size_matrix];
    for (int i = 0; i < size_matrix; i++)
    {
        for (int j = 0; j < size_matrix; j++)
            in_a >> a[i][j];
    }
    in_a.close();

    ifstream in_b(file_b);
    in_b >> size_matrix;
    double** b;
    b = new double* [size_matrix];
    for (int i = 0; i < size_matrix; i++)
        b[i] = new double[size_matrix];
    for (int i = 0; i < size_matrix; i++)
    {
        for (int j = 0; j < size_matrix; j++)
            in_b >> b[i][j];
    }
    in_b.close();

    double** c;
    c = new double* [size_matrix];
    for (int i = 0; i < size_matrix; i++)
        c[i] = new double[size_matrix];

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < size_matrix; i++)
    {
        for (int j = 0; j < size_matrix; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < size_matrix; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<float> duration = end - start;
    std::cout << "Time: " << duration.count() << " s" << endl;

    ofstream of("D:\\Matrix_C_1000.txt");
    if (of.is_open())
    {
        of << size_matrix << endl;
        for (int i = 0; i < size_matrix; i++)
        {
            for (int j = 0; j < size_matrix; j++)
                of << c[i][j] << "\t";
            of << "\n";
        }
        of.close();
    }
    else
        cout << "File not found";

    for (int i = 0; i < size_matrix; i++)
        delete[] a[i];
    delete[] a;
    for (int i = 0; i < size_matrix; i++)
        delete[] b[i];
    delete[] b;
    for (int i = 0; i < size_matrix; i++)
        delete[] c[i];
    delete[] c;
    return;
}


int main()
{
    multiply_matrices("D:\\Matrix_A_1000.txt", "D:\\Matrix_B_1000.txt");
    return 0;
}
