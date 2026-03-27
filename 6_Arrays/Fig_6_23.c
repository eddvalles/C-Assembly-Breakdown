// Fig. 6.23: fig06_23.c
// Using variable length arrays in C99
#include <stdio.h>

// function prototypes
void print1DArray(size_t size, int array[size]);
void print2DArray(size_t row, size_t col, int array[row][col]);

int main(void)
{
    printf("%s", "Enter size of a one-dimensional array: ");
    int arraySize; // size of 1D array
    scanf("%d", &arraySize);

    int array[arraySize]; // declare 1-D variable-length array

    printf("%s", "Enter number of rows and columns in a 2-D array: ");
    int row1, col1; // number of rows and columns in a 2-D array
    scanf("%d %d", &row1, &col1);
}

void print1DArray(size_t size, int array[size])
{
    // output contents of array
    for (size_t i = 0; i < size; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
}

void print2DArray(size_t row, size_t col, int array[row][col])
{
    // output contents of array
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            printf("%5d", array[i][j]);
        }

        puts("");
    }
}