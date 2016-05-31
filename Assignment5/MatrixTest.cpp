#include "Matrix.hpp"
#include "Rational.hpp"

#include "gtest/gtest.h"

TEST(matrix, matrix_test)
{
	Matrix<int> mat1(1, 1, std::vector<int>(1,2));

	EXPECT_EQ(1, mat1.getRowNum());
	EXPECT_EQ(1, mat1.getColNum());

	int t= 0;
	EXPECT_TRUE(mat1.hasTrace(t));
  EXPECT_TRUE(mat1.isSquareMatrix());

	Matrix<int> transpose_mat= mat1;
	EXPECT_EQ(transpose_mat, mat1.transpose());

	Matrix<int> mat2(1, 1, std::vector<int>(1,3));
    Matrix<int> add_mat(1, 1, std::vector<int> (1,5));
	EXPECT_EQ(add_mat, mat1+mat2);

	Matrix<int> multi_mat(1, 1, std::vector<int>(1,6));
	EXPECT_EQ(multi_mat, mat1*mat2);

	Matrix<int> scalar_multi_mat(1, 1, std::vector<int>(1,4));
	EXPECT_EQ(scalar_multi_mat, mat1*2);

}

TEST(matrix, constructors_test)
{
	std::vector<int> sampleMatrix1 {0};
	Matrix<int> mat1;
	Matrix<int> mat2(1,1, sampleMatrix1);

	EXPECT_EQ(mat1, mat2);

	std::vector<int> sampleMatrix2 {1,2,3,4};
	std::vector<int> sampleMatrix3 {1,2,3,4,0,0};

	Matrix<int> mat3(3,2, sampleMatrix2);
	Matrix<int> mat4(3,2, sampleMatrix3);

	EXPECT_EQ(mat3, mat4);

	EXPECT_EQ(3, mat3.getRowNum());
	EXPECT_EQ(2,mat3.getColNum());


}

TEST(matrix, matrix_copy_and_equal_test)
{
	std::vector<int> sampleMatrix1 {1,2,3,4};
	Matrix<int> mat1(2, 2, sampleMatrix1);  // create matrix
	Matrix<int> mat2(mat1); // copy the matrix to other with copy constructor
	EXPECT_EQ(mat1, mat2); // check if the matrix are equals
	EXPECT_NE(mat1.transpose(), mat2); // check if transpose of the matrix are realy not equals (matrix are not symatric)

	std::vector<int> sampleMatrix2 {5,6,7,8};
	Matrix<int> mat3(2, 2, sampleMatrix2);	// create other matrix for test, with other values
	Matrix<int> mat4 = Matrix<int>(mat3); // copy the matrix to other with equals operator
	EXPECT_EQ(mat3, mat4);
	mat3 = mat1; //  change mat3
	EXPECT_NE(mat3, mat4);
	EXPECT_EQ(mat1, mat2); // check if matrix1 has no change after mat3 = mat1;
}

TEST (matrix, isSquareMatrix_test)
{
	Matrix<Rational> mat1; // check defualt matrix 1 X 1 - square
	EXPECT_TRUE(mat1.isSquareMatrix());

	Matrix<Rational> mat2 (2, 2, std::vector<Rational> (4)); // check 2 X 2 matrix - square
	EXPECT_TRUE(mat2.isSquareMatrix());

	Matrix<std::string> mat3 (2,3, std::vector<std::string> (6)); // check 2 X 3 matrix - not square
	EXPECT_FALSE(mat3.isSquareMatrix());

	Matrix<int> mat4 (1, 1, std::vector<int> (1)); // check again 1 X 1 , diffrent constructor -- square
	EXPECT_TRUE(mat4.isSquareMatrix());

}

TEST (matrix, check_calculation_operator)
{
	std::vector<int> vSampleMatrix1 {1,2,3,4};
	std::vector<int> vSampleMatrix2 {1,1,1,1};
	std::vector<int> vSampleMatrix3 {1,1,1,1,1,1};
	std::vector<int> vAnsSum {2,3,4,5};
	std::vector<int> vAnsMul1 {3,3,7,7};
	std::vector<int> vAnsMul2 {4,6,4,6,4,6};
	std::vector<int> vAnsMulScalar {2,4,6,8};

	Matrix<int> mSampleMatrix1(2,2,vSampleMatrix1);// {1,2,3,4};
	Matrix<int> mSampleMatrix2(2,2,vSampleMatrix2); // {1,1,1,1};
	Matrix<int> mAnsSum(2,2,vAnsSum); // {2,3,4,5};
	Matrix<int> mAnsMul1(2,2,vAnsMul1); // {3,3,7,7};
	Matrix<int> mAnsMulScalar(2,2,vAnsMulScalar);  // {2,4,6,8};
	Matrix<int> mSampleMatrix3(3,2,vSampleMatrix3); // {1,1,1,1,1,1};
	Matrix<int> mAnsMul2(3,2,vAnsMul2); // {4,6,4,6,4,6};

	// operator +
	EXPECT_EQ(mAnsSum, mSampleMatrix1 + mSampleMatrix2);

	// operator *
	EXPECT_EQ(mAnsMul1, mSampleMatrix1 * mSampleMatrix2); // multiplay mul square
	EXPECT_EQ(mAnsMul2, mSampleMatrix3 * mSampleMatrix1); // multiplay mul non square
	EXPECT_EQ(mAnsMulScalar, mSampleMatrix1 * 2); // scalar multiplay


}

TEST (matrix, special_test_matrix_operators)
{
	std::vector<std::string> vStringMatrix {"fall", "winter", "summer", "spring"};
	std::vector<std::string> vStringMtrixAns1 {" hello fall", " hello winter", " hello summer", " hello spring"};
	std::vector<std::string> vStringMtrixAns2 {"fall hello ", "winter hello ", "summer hello ", "spring hello "};

	Matrix<std::string> mStringMatrix(2,2, vStringMatrix);
	Matrix<std::string> mStringMtrixAns1(2,2, vStringMtrixAns1);
	Matrix<std::string> mStringMtrixAns2(2,2, vStringMtrixAns2);
	Matrix<std::string> mStringMatrixToAdd(2,2, std::vector<std::string> (4, " hello "));

	EXPECT_EQ(mStringMtrixAns1, mStringMatrixToAdd + mStringMatrix);
	EXPECT_NE(mStringMtrixAns1, mStringMatrix + mStringMatrixToAdd);
	EXPECT_EQ(mStringMtrixAns2, mStringMatrix + mStringMatrixToAdd);

}

TEST(matrix, check_trace)
{
	// check non square trace
	std::vector<int> sampleMatrix1 {1,2,3,4,5,6};
	Matrix<int> mat1(2,3,sampleMatrix1);
	int trace;
	EXPECT_FALSE(mat1.hasTrace(trace));

	// check square trace
	std::vector<int> sampleMatrix2 {1,2,3,4};
	Matrix<int> mat2(2,2,sampleMatrix2);
	EXPECT_TRUE(mat2.hasTrace(trace));
	EXPECT_EQ(5, trace);


	// check 1 X 1 trace
	std::vector<int> vSampleMatrix3 {100};
	Matrix<int> mat3(1,1, vSampleMatrix3);
	EXPECT_TRUE(mat3.hasTrace(trace));
	EXPECT_EQ(100, trace);

	// check rational trace
	Rational rTemp;
	std::vector<Rational> vSampleMatrix4  {Rational(1),Rational(1,2),Rational(1,3),Rational(1,4)};
	Matrix<Rational> mat4(2,2, vSampleMatrix4);
	EXPECT_TRUE(mat4.hasTrace(rTemp));
	EXPECT_EQ(Rational(5,4), rTemp);

}

TEST(matrix, check_transpose)
{

	// check square transpose
	std::vector<int> vSampleMatrix1 {1,2,3,4};
	std::vector<int> vSampleMatrix1Transpose {1,3,2,4};
	Matrix<int> mSampleMatrix1(2, 2, vSampleMatrix1);
	Matrix<int> mSampleMatrix1Transpose(2,2, vSampleMatrix1Transpose);

	EXPECT_EQ(mSampleMatrix1Transpose, mSampleMatrix1.transpose());
	EXPECT_EQ(mSampleMatrix1, mSampleMatrix1.transpose().transpose());
	//check non square transpose
	std::vector<int> vSampleMatrix2 {1,2,3,4,5,6};
	std::vector<int> vSampleMatrix2Transpose {1,4,2,5,3,6};
	Matrix<int> mSampleMatrix2(2, 3, vSampleMatrix2);
	Matrix<int> mSampleMatrix2Transpose(3,2, vSampleMatrix2Transpose);

	EXPECT_EQ(mSampleMatrix2Transpose, mSampleMatrix2.transpose());
	EXPECT_EQ(mSampleMatrix2, mSampleMatrix2.transpose().transpose());


	// cehck 1 X 1 matrix transpose
	std::vector<int> vSampleMatrix3 {1};
	std::vector<int> vSampleMatrix3Transpose {1};
	Matrix<int> mSampleMatrix3(1, 1, vSampleMatrix3);
	Matrix<int> mSampleMatrix3Transpose(1,1, vSampleMatrix3Transpose);

	EXPECT_EQ(mSampleMatrix3Transpose, mSampleMatrix3.transpose());
	EXPECT_EQ(mSampleMatrix3, mSampleMatrix3.transpose().transpose());

	// Rational transpose test
	std::vector<Rational> vSampleMatrix4 {Rational(1),Rational(1,2),Rational(1,3),Rational(1,4),Rational(1,5), Rational(1,6)};
	std::vector<Rational> vSampleMatrix4Transpose {Rational(1),Rational(1,4),Rational(1,2),Rational(1,5),Rational(1,3),Rational(1,6)};
	Matrix<Rational> mSampleMatrix4(2, 3, vSampleMatrix4);
	Matrix<Rational> mSampleMatrix4Transpose(3,2, vSampleMatrix4Transpose);

	EXPECT_EQ(mSampleMatrix4Transpose, mSampleMatrix4.transpose());
	EXPECT_EQ(mSampleMatrix4, mSampleMatrix4.transpose().transpose());


}

TEST(matrix, check_transpose_trace_properies)
{
	std::vector<Rational> vSampleSquereMatrix {Rational(1),Rational(1,2),Rational(1,3),Rational(1,4)};
	Matrix<Rational> a(2, 2, vSampleSquereMatrix);

	Matrix<Rational> b(a*Rational(1,4)); // create more square matrix, but diffrent

	// check if transpose(a+b) = transpose(a) + transpose(b)
	EXPECT_EQ((a+b).transpose(), a.transpose() + b.transpose());

	// check if transpose(a*b) = transpose(b) * transpose(a)
	EXPECT_EQ((a*b).transpose(), b.transpose() * a.transpose());

	// check if a * transpose(a) is symatric
	Matrix<Rational> tempAns = a*a.transpose();
	EXPECT_EQ(tempAns.transpose(), tempAns);

	Rational trace1, trace2, trace3;

	// cehck if tr(a + b) = tr(a) + tr(b)
	EXPECT_TRUE(a.hasTrace(trace1) && b.hasTrace(trace2) && (a+b).hasTrace(trace3));
	EXPECT_EQ(trace1 + trace2, trace3);

	trace1 = Rational(0), trace2 = Rational(0), trace3 = Rational(0);
	// cehck if tr(ab) = tr(ba)
	EXPECT_TRUE((a*b).hasTrace(trace1) && (b*a).hasTrace(trace2));
	EXPECT_EQ(trace1, trace2);


	trace1 = Rational(0), trace2 = Rational(0), trace3 = Rational(0);
	//check if tr(a) = tr( transpose(a)  )
	EXPECT_TRUE(a.hasTrace(trace1) && a.transpose().hasTrace(trace2));
	EXPECT_EQ(trace1, trace2);

}
