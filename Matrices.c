#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void HandleMemAllocFailed()
{
    printf("Memory allocation failed!");
    exit(1);
}

void PrintMatrix(int r, int c, int arr[r][c])
{

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void SumRowsAndCols(int rows, int cols, int arr[rows][cols])
{
    int sum = 0, sumc = 0;
    printf("Row sums:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += arr[i][j];
            sumc += arr[j][i];
        }
        printf("Row %d: %d \n", i, sum);
        printf("Col %d: %d \n", i, sumc);
        sum = 0;
        sumc = 0;
    }
}

int MinMax(int r, int c, int arr[r][c], int *mx)
{
    int min = arr[0][0], max = arr[0][0];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] < min)
                min = arr[i][j];
            else if (arr[i][j] > max)
                max = arr[i][j];
        }
    }

    if (mx != NULL)
        *mx = max;
    return min;
}

void TransposeSquare(int r, int c, int arr[r][c])
{
    int temp;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i < j)
            {
                temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }
    }
}

int **Transpose(int r, int c, int arr[r][c], int *nrows, int *ncols)
{
    int **new = malloc(r * sizeof(int *));
    if(new == NULL) HandleMemAllocFailed();

    for(int i = 0; i < r; i++)
    {
        new[i] = malloc(c * sizeof(int));
        if(new[i] == NULL) HandleMemAllocFailed();
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            new[j][i] = arr[i][j];
        }
    }

    *nrows = c;
    *ncols = r;
    return new;
}

int **Add(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2], int *r, int *c)
{
    if (r1 != r2 || c1 != c2)
    {
        printf("The martices must be the sime size!");
        exit(1);
    }

    int **sum = malloc(r1 * sizeof(int *)); // allocate mem for rows
    if (sum == NULL)
    {
        printf("Memory allocation failed!");
        exit(1);
    }

    for (int i = 0; i < r1; i++)
    {
        sum[i] = malloc(c1 * sizeof(int)); // allocate mem for cols
        if (sum[i] == NULL)
        {
            printf("Memory allocation failed!");
            exit(1);
        }
    }

    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c1; j++)
            sum[i][j] = m1[i][j] + m2[i][j];
    }

    *r = r1;
    *c = c1;
    return sum;

}

int **Multiply(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2], int *r, int *c)
{
    if (c1 != r2)
    {
        printf("The number of columns of the first matrix must be equal to the number of rows of the second matrix!");
        exit(1);
    }

    int **product = malloc(r1 * sizeof(int *));

    if (product == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < r1; i++)
    {
        product[i] = malloc(c2 * sizeof(int));

        if (product[i] == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            product[i][j] = 0;
            for (int k = 0; k < r2; k++)
                product[i][j] += m1[i][k] * m2[k][j];
        }
    }

    *r = r1;
    *c = c2;
    return product;
}

bool IsSymmetric(int r, int c, int a[r][c])
{
    if(r != c) return false;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(i < j && a[i][j] != a[j][i])
                return false;
        }
    }

    return true;
}

int Trace(int r, int c, int a[r][c])
{
    if(r != c)
    {
        printf("The matrix is not a square matrix");
        exit(1);
    }
    int sum = 0;
    for(int i = 0; i < r; i++)
        sum += a[i][i];
    return sum;
}

int **Rotate90(int r, int c, int arr[r][c])
{
    int **transposed = Transpose(r,c,arr,&r,&c);
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c/2; j++)
        {
            if(transposed[i][j] == transposed[i][c - 1 - j]) continue;
            transposed[i][j] ^= transposed[i][c - 1 - j];
            transposed[i][c - 1 - j] = transposed[i][j] ^ transposed[i][c - 1 - j];
            transposed[i][j] ^= transposed[i][c - 1 - j];
        }
    }

    return transposed;
}

void FindElement(int r, int c, int arr[r][c],int element)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(arr[i][j] == element)
            {
                printf("Found element:%d at [%d][%d]\n",element,i,j);
            }
        }
    }
}

int main()
{
    int r = 3, c = 3;
    int m1[3][3] = {{1,2,3}, {4,5,6},{7,8,3}};
    FindElement(r,c,m1,3);
    /*int** rotated = Rotate90(r,c,m1);




    /*printf("Before transposition\n");
    PrintMatrix(r,c,m1);
    printf("\n");*/

    /*for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%d ",rotated[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < r; i++)
    {
        free(rotated[i]);
    }

    free(rotated);*/
    /*int r1 = 2, c1 = 3;
    int r2 = 3, c2 = 4;
    int m1[2][3] = {{1, 4, -2}, {3, 5, -6}};
    int m2[3][4] = {{5, 2, 8, -1}, {3, 6, 4, 5}, {-2, 9, 7, -3}};*/

    return 0;
}