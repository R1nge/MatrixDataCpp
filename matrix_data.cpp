#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
using namespace std;

class MatrixData
{
private:

    float* fileData;

    void readFileData()
    {
        constexpr size_t size = 200 * sizeof(float);
        float* mas = (float*) malloc(size);

        for (int i = 0; i < 100; i++){
            mas[i] = i;
        }
        
        fileData = &mas[0];
    }

    float getSquareSum(float data[]) // sum of squared values of x for matrx A (1;1)
    {
        float squareSum = 0;
        
        for (int i = 0; i < 100; ++i)
        {
            squareSum += data[i] * data[i];
        }
        
        return squareSum;
    }
    
    float getSum(float data[], int c) // sum of x or y
    {
        float sum = 0;
        
        for (int i = 0; i < 100; ++i)
        {
            sum += data[i + c];
        }
        
        return sum;
    }
    
    float getXY(float data[])
    {
        float xy = 0;
        
        for (int i = 0; i < 100; ++i)
        {
            xy += data[i] * data[99 + i]; //Index out of range exception
        }
        
        return xy;
    }
    
public:

    MatrixData()
    {
        readFileData();
    }
    
    ~MatrixData()
    {
        free(fileData);
    }

    float* getMatrix(int a, int b)
    {
        constexpr size_t size = 4 * sizeof(float);
        float* A = (float*) malloc(size);
        A[2] = getSum(fileData, 0);
        A[1] = getSum(fileData, 0);
        A[0] = getSquareSum(fileData);
        A[3] = 100;
        return &A[0];
    }
    
    float* getMatrix(int a)
    {
        constexpr size_t size = 2 * sizeof(float);
        float* B = (float*) malloc(size);
        B[0] = getXY(fileData);
        B[1] = getSum(fileData, 50);
        return &B[0];
    }
};

int main()
{
    MatrixData A, B;
    float* resultA = A.getMatrix(1, 1);
    for (int i = 0; i < 4; i++){
        cout << "\t" << A.getMatrix(1, 1)[i];
    }
    
    free(resultA);
    float* resultB = B.getMatrix(1);
    free(resultB);
}
