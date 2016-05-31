
#define POSITIVE_SIGN 1
#define NEGATIVE_SIGN -1
#define READ_END_SIGN -2

#include <stdio.h>
#include <stdlib.h>
#include "LinSeperator.h"
#include "LinSeperatorHelperFunctions.h"

// the assigment function LinSeperator
void LinSeperator(const char *In, const char *Out)
{
    Orange orangeW;
    int nDim, nPositiveSample, nNegativeSample;

    Orange orangeCurrentRead;
    double ansScalarMultipication;
    int bEndOfFile = 0;

    FILE *fIn;
    FILE *fOut;

    fIn = fopen(In, "r");
    fOut = fopen(Out, "w");

    if (fIn == NULL || fOut == NULL)
    {
        printf("file couldn't open, \n exit from program");
        return;
    }

    fscanf(fIn, "%d %d %d", &nDim, &nPositiveSample, &nNegativeSample);

    resetZeroOrange(&orangeW, nDim);

    readSampleVectorFromFile(fIn, nPositiveSample, nDim, POSITIVE_SIGN,
                             &orangeW);
    readSampleVectorFromFile(fIn, nNegativeSample, nDim, NEGATIVE_SIGN,
                             &orangeW);

    // classified AndWrite Ans on FILE
    while (!bEndOfFile)
    {
        readVectorFromFile(&orangeCurrentRead, fIn, nDim, 0);
        if (orangeCurrentRead.nSign == READ_END_SIGN)   // if the flag of end of file is on
        {
            bEndOfFile = 1;
            break;
        }
        ansScalarMultipication =
            vectorScalarMultiplay(&orangeCurrentRead, &orangeW, nDim);

        if (ansScalarMultipication >= 0)
        {
            fprintf(fOut, "%d\n", POSITIVE_SIGN);
        } else
        {
            fprintf(fOut, "%d\n", NEGATIVE_SIGN);
        }
    }

    fclose(fOut);
    fclose(fIn);

}


// implement here helper functions that their headers are in "LinSeperatorHelperFunctions.h"

// get: point for vector p and dim
// do: resset all value of vector p to zero, and nSign to zero.
void resetZeroOrange(Orange * p, const int dim)
{
    size_t i;
    for (i = 0; i < dim; i++)
    {
        p->vector[i] = 0;
    }
    p->nSign = 0;
}

// get: pointer to read file, num of vector to read, dim,
                  // initial sign for orange and pointer to vector w
// do: check if vector w need update, if yes send to updateOrangeValue
void readSampleVectorFromFile(FILE * fIn, int numOfVectors, const int dim,
                              const int sign, Orange * orangeW)
{
    Orange orangeCurrent;
    size_t i;
    double dScalarMultiplicationAns;
    for (i = 0; i < numOfVectors; i++)
    {
        readVectorFromFile(&orangeCurrent, fIn, dim, sign);
        dScalarMultiplicationAns =
            vectorScalarMultiplay(&orangeCurrent, orangeW, dim);
        if ((dScalarMultiplicationAns <= 0 && sign == POSITIVE_SIGN)
            || (dScalarMultiplicationAns >= 0 && sign == NEGATIVE_SIGN))
        {
            updateOrangeValue(orangeW, &orangeCurrent, dim);    // update vector w
        }
    }
}


// Read vector from file
// get: pointer to file, and default sign to insert him
// return: new Orange Struct, if end of file
//         (or error in read, return orange with sign READ_END_SIGN)
void readVectorFromFile(Orange * target, FILE * fIn, const int dim, const int sign)
{
    size_t i;
    char cJunk;
    target->nSign = sign;
    for (i = 0; i < dim - 1; i++)
    {
        if (fscanf(fIn, "%lf%c", &(target->vector[i]), &cJunk) != 2)
        {
            target->nSign = READ_END_SIGN;
        }
    }
    if (fscanf(fIn, "%lf", &(target->vector[dim - 1])) != 1)
    {
        target->nSign = READ_END_SIGN;
    }
}


// Get: point for two oranges struct, and dim
// return: the scalar multiplay ans of two oranges
double vectorScalarMultiplay(Orange * a, Orange * b, const int dim)
{
    double ans = 0;
    size_t i;
    for (i = 0; i < dim; i++)
    {
        ans += a->vector[i] * b->vector[i];
    }
    return ans;
}

// get: point for two oranges, orange w (the assigment vector), oprange p and dim
// do: update vector w with the assigment rule
void updateOrangeValue(Orange * w, Orange * p, const int dim)
{
    size_t i;
    for (i = 0; i < dim; i++)
    {
        w->vector[i] = w->vector[i] + (p->vector[i]) * (p->nSign);
    }
}
