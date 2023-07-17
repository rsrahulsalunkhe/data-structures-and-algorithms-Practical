#include<iostream>
using namespace std;

int main()
{
    int a[][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int b[][3] = {
        {1,7,8},
        {2,3,4},
        {1,2,3}
    };

    int mult[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                mult[i][j] += a[i][k] * b[k][j];
            }
            
        }
    }
    
    cout << "The multiplication of matrix a and b is " << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << mult[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}