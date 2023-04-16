#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
using namespace std;

class matrix_data
{
private:

    float* read_input_file()  // read data from file
    {
        float data[200];
        ifstream file;
        file.open("C:\\data_for_lab.txt");
        
        if (!file)
        {
            throw std::invalid_argument("No such file directory");
        }

        for (int i = 0; i < 200; ++i) // summ of number X and Y = 200
        {
            file >> data[i];
        }
        
        return nullptr;
    }

    float sum_sq_numb(float data[]) // sum of squared values of x for matrx A (1;1)
    {
        float sum_sq = 0;
        
        for (int i = 0; i < 100; ++i)
        {
            sum_sq = sum_sq + data[i] * data[i];
        }
        
        return sum_sq;
    }
    
    float sum(float data[], int c) // sum of x or y
    {
        float sum = 0;
        
        for (int i = 0; i < 100; ++i)
        {
            sum = sum + data[i + c];
        }
        
        return sum;
    }
    
    float xy(float data[])
    {
        float xy = 0;
        
        for (int i = 0; i < 100; ++i)
        {
            xy = xy + data[i] * data[99 + i];
        }
        
        return xy;
    }
    
public:

    float* matrix(int a, int b)
    {
        constexpr size_t size = 4;
        float A[size];
        float* mas = (float*) malloc(size);
        A[2] = sum(read_input_file(), 0);
        A[1] = sum(read_input_file(), 0);
        A[0] = sum_sq_numb(read_input_file());
        A[3] = 100;
        return &mas[0];
    }
    
    float* matrix(int a)
    {
        constexpr size_t size = 2;
        float B[size];
        float* mas = (float*) malloc(size);
        B[0] = xy(read_input_file());
        B[1] = sum(read_input_file(), 50);
        return &mas[0];
    }
};

int main()
{
    matrix_data A, B;
    A.matrix(1, 1);
    B.matrix(1);
}
