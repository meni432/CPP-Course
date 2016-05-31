#include <stdio.h>
#include <stdlib.h>
#define MAX_ROW_COL 100     // maximum row col


// read elements from file
// get: pointer to file, matrix to fill in, and number of cols and rows
// do: fill the matrix with the elements from file
void readElementFromFile(FILE * fIn, double matrix[][MAX_ROW_COL], int n,
                         int m);
// calculte rows cols sum
// get: input matrix, matrix to fill, and number of cols and rows
// do: fill the matrix with sum area until matrix[i][j]
void fillMatrixSums(double mInput[][MAX_ROW_COL],
                    double mS[][MAX_ROW_COL], int n, int m);
// get: matrixS to fill, matrix with row cols sums, and number of rows, cols, windows size
// do: calculte the assigment S matrix
void calcMatrixS(double matrixS[][MAX_ROW_COL],
                 double mSums[][MAX_ROW_COL], int n, int m, int w);
// get: point to file, matrix, number of rows and cols
// do: write matrix to pointed file
void printMatrixToFile(FILE * fOut, double matrix[][MAX_ROW_COL], int n,
                      int m);
// get: two integer number
// return: the minimal of them
int min(int a, int b);
