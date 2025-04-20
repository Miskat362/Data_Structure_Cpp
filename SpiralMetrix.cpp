#include <iostream>
using namespace std;

void spiralMatrix(int mat[][4], int n, int m)
{
    int sRow = 0, sCol = 0;
    int eRow = n - 1, eCol = m - 1;

    while (sRow <= eRow && sCol <= eCol)
    {
        // top
        for (int j = sCol; j <= eCol; j++)
        {
            cout << mat[sRow][j] << " ";
        }
        // right
        for (int i = sRow + 1; i <= eRow; i++)
        {
            cout << mat[i][eCol] << " ";
        }
        // bottom
        for (int j = eCol - 1; j >= sCol; j--)
        {
            if (sRow == eRow)
            {
                break;
            }
            cout << mat[eRow][j] << " ";
        }
        // left
        for (int i = eRow - 1; i >= sRow + 1; i--)
        {
            if (sCol == eCol)
            {
                break;
            }
            cout << mat[i][sCol] << " ";
        }
        sRow++;
        sCol++;
        eRow--;
        eCol--;
    }
}

int main()
{
    int matrix[4][4] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
                        {13, 14, 15, 16}};

    spiralMatrix(matrix, 4, 4);

    return 0;
}