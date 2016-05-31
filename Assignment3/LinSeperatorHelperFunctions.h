#define MAX_DIM 100
#include <stdlib.h>
#include <stdio.h>

typedef struct Orange {
    double vector[MAX_DIM];     // the value of the vector
    int nSign;
} Orange;


// get: point for vector p and dim
// do: resset all value of vector p to zero, and nSign to zero.
void resetZeroOrange(Orange * p, int dim);

// get: pointer to read file, num of vector to read, dim,
                  // initial sign for orange and pointer to vector w
// do: check if vector w need update, if yes send to updateOrangeValue
void readSampleVectorFromFile(FILE * fIn, int numOfVectors, int dim,
                              int sign, Orange * orangeW);

// Read vector from file
// get: pointer to file, and default sign to insert him
// return: new Orange Struct, if end of file
//         (or error in read, return orange with sign READ_END_SIGN)
void readVectorFromFile(Orange * target, FILE * fIn, int dim, int sign);

// Get: point for two oranges struct, and dim
// return: the scalar multiplay ans of two oranges
double vectorScalarMultiplay(Orange * a, Orange * b, int dim);

// get: point for two oranges, orange w (the assigment vector), oprange p and dim
// do: update vector w with the assigment rule
void updateOrangeValue(Orange * w, Orange * p, int dim);
