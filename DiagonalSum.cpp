#include <iostream>
using namespace std;

void diagonalSum(int mat[][4], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += mat[i][i]; // for primary diagonal
        if (i != n - i - 1)
        {
            sum += mat[i][n - i - 1]; // for secondary diagonal
        }
    }
    cout << "Sum of diagonal elements: " << sum << endl;
}

int main()
{
    int matrix[4][4] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
                        {13, 14, 15, 16}};

    diagonalSum(matrix, 4);
    return 0;
}