extern "C" {
    #include "LinSeperator.h"
	#include "LinSeperatorHelperFunctions.h"
}
#include "gtest/gtest.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>



TEST(LinSeperator, Symetric_Test) {
	std::string TestInFile = "LinSeperator.in.1";              // given Input example
	std::string TestOutFile = "LinSeperator.out.1";            // givem Output example for comppersion
	std::string TestOutDest = "testLin1.out";                            // output for the test
    LinSeperator(TestInFile.c_str(), TestOutDest.c_str());              // Call for the LinSeperator function with the inut and output file
    std::string diffCMD = "diff -w " + TestOutFile + " " + TestOutDest;
	int result = std::system(diffCMD.c_str());                          // should return 0 on success. 1 for difference
    ASSERT_EQ(0, result);
}



TEST(LinSeperator, Simple_Test) {
	std::string TestInFile = "LinSeperator.in.2";              // given Input example
	std::string TestOutFile = "LinSeperator.out.2";            // givem Output example for comppersion
	std::string TestOutDest = "testLin2.out";                            // output for the test
    LinSeperator(TestInFile.c_str(), TestOutDest.c_str());              // Call for the LinSeperator function with the inut and output file
    std::string diffCMD = "diff -w " + TestOutFile + " " + TestOutDest;
	int result = std::system(diffCMD.c_str());                          // should return 0 on success. 1 for difference
    ASSERT_EQ(0, result);
}


TEST(LinSeperator, One_Vector_Test) {
	std::string TestInFile = "LinSeperator.in.3";              // given Input example
	std::string TestOutFile = "LinSeperator.out.3";            // givem Output example for comppersion
	std::string TestOutDest = "testLin3.out";                            // output for the test
    LinSeperator(TestInFile.c_str(), TestOutDest.c_str());              // Call for the LinSeperator function with the inut and output file
    std::string diffCMD = "diff -w " + TestOutFile + " " + TestOutDest;
	int result = std::system(diffCMD.c_str());                          // should return 0 on success. 1 for difference
    ASSERT_EQ(0, result);
}


TEST(LinSeperator, DIM_TWO_TEST) {
	std::string TestInFile = "LinSeperator.in.4";              // given Input example
	std::string TestOutFile = "LinSeperator.out.4";            // givem Output example for comppersion
	std::string TestOutDest = "testLin4.out";                            // output for the test
    LinSeperator(TestInFile.c_str(), TestOutDest.c_str());              // Call for the LinSeperator function with the inut and output file
    std::string diffCMD = "diff -w " + TestOutFile + " " + TestOutDest;
	int result = std::system(diffCMD.c_str());                          // should return 0 on success. 1 for difference
    ASSERT_EQ(0, result);
}






// function get two double arrays and dim
// check if all element are equals (A[i] == B[i])
void test_array_equals(const double  A[MAX_DIM], const double B[MAX_DIM], int n){
  int i;
  for (i = 0; i < n; i++)
  {
    EXPECT_EQ(A[i],B[i]);
  }
}

// void resetZeroOrange(Orange * p, int dim);
TEST(resetZeroOrange, Naive_Test) {
  const int testDimSize = 10;
  const double arrayTest[MAX_DIM] = {0};
  Orange orange = {.vector = {1,1,1}, .nSign = 1};
  resetZeroOrange(&orange, testDimSize);
  EXPECT_EQ(0, orange.nSign);
  test_array_equals(arrayTest, orange.vector, testDimSize);
}

// void readVectorFromFile(Orange * target, FILE * fIn, int dim, int sign);
TEST(readVectorFromFile, Naive_Test) {
  FILE * fIn;
  Orange target;
  const int dim = 3;
  const int sign = 1;
  const double expect_vector[] = {1,2,3};
  const char in_file[] = "LinSeperator.in.readTest";

  fIn = fopen(in_file, "r");
  readVectorFromFile(&target, fIn, dim, sign);
  EXPECT_EQ(sign, target.nSign);
  test_array_equals(expect_vector, target.vector, dim);
  fclose(fIn);
}

// double vectorScalarMultiplay(Orange * a, Orange * b, int dim);

TEST(vectorScalarMultiplay, Naive_Test) {
  double ans;
  const int dim = 2;
  Orange orangeA, orangeB;

  orangeA.vector[0] = 1;
  orangeA.vector[1] = 1;
  orangeB.vector[0] = -1;
  orangeB.vector[1] = 1;

  ans = vectorScalarMultiplay(&orangeA, &orangeB, dim);
  EXPECT_EQ(0, ans);
}

TEST(vectorScalarMultiplay, Dim_Eror_Check) {
  double ans;
  // dim should be 2
  const int dim = 1;
  Orange orangeA, orangeB;

  orangeA.vector[0] = 1;
  orangeA.vector[1] = 1;
  orangeB.vector[0] = -1;
  orangeB.vector[1] = 1;

  ans = vectorScalarMultiplay(&orangeA, &orangeB, dim);
  EXPECT_NE(0, ans);
}



// void updateOrangeValue(Orange * w, Orange * p, int dim);
TEST(updateOrangeValue, Naive_Test) {
  const int dim = 2;
  Orange orangeW, orangeA;
  double expect_vector[] = {2,2};

  orangeW.nSign = 1;
  orangeA.nSign = 1;
  orangeW.vector[0] = 1;
  orangeW.vector[1] = 1;
  orangeA.vector[0] = 1;
  orangeA.vector[1] = 1;
  updateOrangeValue(&orangeW, &orangeA, dim);
  test_array_equals(expect_vector, orangeW.vector, dim);
}


//void readSampleVectorFromFile(FILE * fIn, int numOfVectors, int dim,
                              // int sign, Orange * orangeW);
TEST(readSampleVectorFromFile, Naive_Test) {
  FILE * fIn;
  const int numOfVectors = 1;
  const int dim = 3;
  const int sign = 1;
  Orange orangeW = {.vector = {1,1,1}, .nSign = 1};
  const double expect_vector[] = {1,1,1};
  const char in_file[] = "LinSeperator.in.readTest";

  fIn = fopen(in_file, "r");
  readSampleVectorFromFile(fIn, numOfVectors, dim, sign, &orangeW);
  fclose(fIn);
  test_array_equals(expect_vector, orangeW.vector, dim);

}







// also make sure you test your helper functions
