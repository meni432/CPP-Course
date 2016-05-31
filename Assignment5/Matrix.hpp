#include <vector>
#include <cstdlib>

#include "myassert.hpp"

template < typename T > class Matrix
{
  public:

  /**
   * Constructors
  */

    // Default Constructor
    Matrix():_numRows(NUM_ROW), _numCols(NUM_COL)
    {
        std::vector < T > v(_numRows * _numCols);
        v[0] = T();             // initialize the only value in this vector
        _vector = v;            // set local vector as v
    };

    // Vector Constructor
    // create new matrix with in size n * m
    // if n and m don't match the vector size, place T() value instead
    Matrix(const size_t n, const size_t m,
           const std::vector < T > &other):_numRows(n), _numCols(m) {
        myassert(_numRows >= NUM_ROW && _numCols >= NUM_COL);   // cehck if size are legal
        _vector = std::vector < T > (_numRows * _numCols, T());
        for (size_t i = 0; i < _numRows; i++)
        {
            for (size_t j = 0; j < _numCols; j++)
            {
                //check if has value for current _vector[i][j] in other[i][j]
                if (getIndex(i, j) < other.size())
                {
                    _vector[getIndex(i, j)] = other[getIndex(i, j)];
                }
            }
        }
    };

    // Copy Constructor use the defualt implimentation

    // Operator  = use the defualt implimentation

    // Plus operator
    const Matrix < T > operator+(const Matrix < T > &other) const
    {
        // check if two matrix has the same dimantions
        myassert(_numRows == other._numRows && _numCols == other._numCols);

        std::vector < T > vectorAns(other._numRows * other._numCols);   // make vector  fitting size
        Matrix < T > ans(_numRows, _numCols, vectorAns);        // make matrix for ans
        for (size_t i = 0; i < _numRows; i++) {
            for (size_t j = 0; j < _numCols; j++) {
                ans._vector[getIndex(i, j)] =
                    _vector[getIndex(i, j)] +
                    other._vector[getIndex(i, j)];
            }
        }
        return ans;
    };

    // multiplication  operator (matrix * matrix)
    const Matrix < T > operator*(const Matrix < T > &other) const
    {
        // check if matrixs fitness to multiplication
        myassert(_numCols == other._numRows);

        std::vector < T > vectorAns(_numRows * other._numCols, T());    // make vector with fitting size, and initialize to defualt value (e.g. for int  = 0)
        Matrix < T > ans(_numRows, other._numCols, vectorAns);  // make matrix for ans
        // multiplay the matrixs and store the ans in ans matrix
        for (size_t i = 0; i < _numRows; i++)
        {
            for (size_t j = 0; j < other._numCols; j++)
            {
                for (size_t k = 0; k < _numCols; k++)
                {
                    ans._vector[i * other._numCols + j] =
                        ans._vector[i * other._numCols + j] +
                        _vector[i * _numCols + k] *
                        other._vector[k * other._numCols + j];
                }
            }
        }
        return ans;
    };

    // multiplication operator (matrix * scalar)
    const Matrix < T > operator*(const T & scalar) const
    {
        std::vector < T > vectorAns(_numRows * _numCols);       // make vector fitting size
        Matrix < T > ans(_numRows, _numCols, vectorAns);        // make matrix for ans
        // multiplay the matrix with scalar and store the in ans matrix
        for (size_t i = 0; i < _numRows; i++)
        {
            for (size_t j = 0; j < _numCols; j++)
            {
                // multiplay each [i][j] by scalar
                ans._vector[getIndex(i, j)] =
                    _vector[getIndex(i, j)] * scalar;
            }
        }
        return ans;
    };

  /**
  * Matrix functions
  */

    // transpose function (replce A[i,j] to A[j,i])
    const Matrix < T > transpose() const
    {
        std::vector < T > vectorAns(_numRows * _numCols);       // make vector fitting size
        Matrix < T > ans(_numCols, _numRows, vectorAns);        // make matrix for ans

        // get over half of the matrix, and replace Matrix[i,j] = Matrix[j,i]
        for (size_t i = 0; i < _numRows; i++)
        {
            for (size_t j = 0; j < _numCols; j++)
            {
                ans._vector[j * (ans._numCols) + i] =
                    _vector[getIndex(i, j)];
            }
        }
        return ans;
    };
    // trace function,
    // if the matrix is square,
    //          calculate the trace value and put the value in t and return true.
    // else put value 0 in t, and retrun false.
    const bool hasTrace(T & t) const
    {
        t = T();
        if (_numRows != _numCols)
        {
            return false;
        }

        // calculate sum of diagonal
        for (size_t i = 0; i < _numRows; i++)
        {
            t = t + _vector[getIndex(i, i)];
        }

        return true;
    };
    // get Col Num
    const size_t getColNum() const
    {
        return _numCols;
    };
    // get Row Num
    const size_t getRowNum() const
    {
        return _numRows;
    };
    // isSquareMatrix function, retrun true if matrix is square
    const bool isSquareMatrix() const
    {
        return _numRows == _numCols;
    };

  /**
  * booleans operators
  */

    // equals operators
    const bool operator==(const Matrix < T > &other) const
    {
        if (_numRows != other._numRows || _numCols != other._numCols) {
            return false;
        }

        for (size_t i = 0; i < _numRows; i++)
        {
            for (size_t j = 0; j < _numCols; j++)
            {
                // check if evry value on _vector[i][j] = other._vector[i][j]
                if (_vector[getIndex(i, j)] !=
                    other._vector[getIndex(i, j)])
                {
                    return false;               // if _vector[i][j] != other._vector[i][j] return false
                }
            }
        }
        return true;
    };

    // not equals operator (!=)
    // return the inverse of ==
    const bool operator!=(const Matrix < T > &other) const {
        return !(*this == other);
    };



  private:
    enum initialize_vars:size_t {
        NUM_ROW = 1,            // defualt initialize num row for defualt Constructor
        NUM_COL = 1             // defualt initialize num Col for defualt Constructor
    };

    std::vector < T > _vector;
    size_t _numRows, _numCols;  // size of matrix

    /**
     * get index of Matrix[i][j] in Vector format (in array)
     */
    size_t getIndex(const size_t i, const size_t j) const {
        return i * _numCols + j;
    };


};
