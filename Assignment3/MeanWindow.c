#include <stdio.h>
#include <stdlib.h>
#include "MeanWindow.h"
#include "MeanWindowHelperFunctions.h"

// the assignment function MeanWindow
void MeanWindow(const char *InFile, const char *OutFile)
{
    int n;                      // number of row in matrix
    int m;                      // number of col in matrix
    int w;                      // size of windows
    double mInput[MAX_ROW_COL][MAX_ROW_COL];    // matrix that store data from file on matrix
    double mSums[MAX_ROW_COL][MAX_ROW_COL];     // matrix that store the sum rows cols from mInput
    double matrixS[MAX_ROW_COL][MAX_ROW_COL];   // the  assigment matrix S


    FILE *fIn;
    FILE *fOut;

    fIn = fopen(InFile, "r");
    fOut = fopen(OutFile, "w");

    // if one of the file's couldn't open, tell the user and exit from the program
    if (fIn == NULL)
    {
        printf("file couldn't open, \n exit from program");
        return;
    }

    fscanf(fIn, "%d %d %d", &n, &m, &w);        // read first 3 initial elements

    readElementFromFile(fIn, mInput, n, m);     //fill the matrix with the elements from file
    fillMatrixSums(mInput, mSums, n, m);        //fill the matrix with rows cols sums
    calcMatrixS(matrixS, mSums, n, m, w);       // calculte and fill the assigment matrix

    fprintf(fOut, "%d %d %d\n", n, m, w);       // print to out file the first line, with input args
    printMatrixToFile(fOut, matrixS, n, m);     // print the matrix S to file

    fclose(fIn);
    fclose(fOut);
}

// implement here helper functions that their headers are in "MeanWindowHelperFunctions.h"



// read elements from file
// get: pointer to file, matrix to fill in, and number of cols and rows
// do: fill the matrix with the elements from file
void readElementFromFile(FILE * fIn, double matrix[][MAX_ROW_COL], int n,
                         int m)
{
    size_t i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            fscanf(fIn, "%lf", &matrix[i][j]);
        }

    }
}


// calculte rows cols sum
// get: input matrix, matrix to fill, and number of cols and rows
// do: fill the matrix with sum area until matrix[i][j]
void fillMatrixSums(double mInput[][MAX_ROW_COL],
                    double mS[][MAX_ROW_COL], int n, int m)
{
    size_t i, j;
    mS[0][0] = mInput[0][0];

    // initial the first
    for (i = 1; i < n; i++)
    {
        mS[i][0] = mS[i - 1][0] + mInput[i][0];
    }
    for (j = 1; j < m; j++)
    {
        mS[0][j] = mS[0][j - 1] + mInput[0][j];
    }
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < m; j++)
        {
            mS[i][j] =
                mS[i - 1][j] + mS[i][j - 1] + mInput[i][j] -
                mS[i - 1][j - 1];
        }
    }
}


// get: matrixS to fill, matrix with row cols sums, and number of rows, cols, windows size
// do: calculte the assigment S matrix
void calcMatrixS(double matrixS[][MAX_ROW_COL],
                 double mSums[][MAX_ROW_COL], int n, int m, int w)
{
    size_t i, j;
    int r;
    r = (w - 1) / 2;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            //  if index is negative ignore ( <==> put zero);
            //  if index is high the limit matrix, set index as (n or m) <==> min((row/col limit), index)
            matrixS[i][j] = mSums[min(n - 1, i + r)][min(m - 1, j + r)];

            if (i - r - 1 >= 0)
            {
                matrixS[i][j] -= mSums[i - r - 1][min(m - 1, j + r)];
            }

            if (j - r - 1 >= 0)
            {
                matrixS[i][j] -= mSums[min(n - 1, i + r)][j - r - 1];
            }

            if ((i - r - 1) >= 0 && (j - r - 1) >= 0)
            {
                matrixS[i][j] += mSums[i - r - 1][j - r - 1];
            }

            matrixS[i][j] /= (double) (w * w);  // division by squares size of windows
        }
    }
}

// get: point to file, matrix, number of rows and cols
// do: write matrix to pointed file
void printMatrixToFile(FILE * fOut, double matrix[][MAX_ROW_COL], int n,
                       int m)
{
    size_t i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            fprintf(fOut, "%lf  ", matrix[i][j]);
        }
        fprintf(fOut, "\n");
    }
}

// get: two integer number
// return: the minimal of them
int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}
