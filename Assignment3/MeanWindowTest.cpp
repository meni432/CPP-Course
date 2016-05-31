extern "C" {
    #include "MeanWindow.h"
	#include "MeanWindowHelperFunctions.h"
}
#include "gtest/gtest.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>


TEST(MeanWindow, ONE_NON_SQUER_TEST) {
	std::string TestInFile = "MeanWindow.in.1";              // given Input example
	std::string TestOutFile = "MeanWindow.out.1";            // givem Output example for comppersion
	std::string TestOutDest = "testMean1.out";                            // output for the test
    MeanWindow(TestInFile.c_str(), TestOutDest.c_str());              // Call for the LinSeperator function with the inut and output file
    std::string diffCMD = "diff -w " + TestOutFile + " " + TestOutDest;
	int result = std::system(diffCMD.c_str());                          // should return 0 on success. 1 for difference
    ASSERT_EQ(0, result);
}

TEST(MeanWindow, SIMPLE_SQUER_TEST) {
	std::string TestInFile = "MeanWindow.in.2";              // given Input example
	std::string TestOutFile = "MeanWindow.out.2";            // givem Output example for comppersion
	std::string TestOutDest = "testMean2.out";                            // output for the test
    MeanWindow(TestInFile.c_str(), TestOutDest.c_str());              // Call for the LinSeperator function with the inut and output file
    std::string diffCMD = "diff -w " + TestOutFile + " " + TestOutDest;
	int result = std::system(diffCMD.c_str());                          // should return 0 on success. 1 for difference
    ASSERT_EQ(0, result);
}

TEST(MeanWindow, CENTER_FIX_TEST) {
	std::string TestInFile = "MeanWindow.in.3";              // given Input example
	std::string TestOutFile = "MeanWindow.out.3";            // givem Output example for comppersion
	std::string TestOutDest = "testMean3.out";                            // output for the test
    MeanWindow(TestInFile.c_str(), TestOutDest.c_str());              // Call for the LinSeperator function with the inut and output file
    std::string diffCMD = "diff -w " + TestOutFile + " " + TestOutDest;
	int result = std::system(diffCMD.c_str());                          // should return 0 on success. 1 for difference
    ASSERT_EQ(0, result);
}


TEST(MeanWindow, ZERO_TEST_SQUER) {
	std::string TestInFile = "MeanWindow.in.4";              // given Input example
	std::string TestOutFile = "MeanWindow.out.4";            // givem Output example for comppersion
	std::string TestOutDest = "testMean4.out";                            // output for the test
    MeanWindow(TestInFile.c_str(), TestOutDest.c_str());              // Call for the LinSeperator function with the inut and output file
    std::string diffCMD = "diff -w " + TestOutFile + " " + TestOutDest;
	int result = std::system(diffCMD.c_str());                          // should return 0 on success. 1 for difference
    ASSERT_EQ(0, result);
}


TEST(MeanWindow, NON_SQUER_TEST_WINDOWS_CALC) {
	std::string TestInFile = "MeanWindow.in.5";              // given Input example
	std::string TestOutFile = "MeanWindow.out.5";            // givem Output example for comppersion
	std::string TestOutDest = "testMean5.out";                            // output for the test
    MeanWindow(TestInFile.c_str(), TestOutDest.c_str());              // Call for the LinSeperator function with the inut and output file
    std::string diffCMD = "diff -w " + TestOutFile + " " + TestOutDest;
	int result = std::system(diffCMD.c_str());                          // should return 0 on success. 1 for difference
    ASSERT_EQ(0, result);
}

// get two matrix, n and m
// check if all a[i][j] = b[i][j]
void test_matrix_equals(const double matrixA[][MAX_ROW_COL] , const double matrixB[][MAX_ROW_COL], int n, int m){
  int i, j;
  for (i = 0; i < n; i++){
    for (j = 0; j < m; j++){
      EXPECT_EQ(matrixA[i][j], matrixB[i][j]);
    }
  }
}


//void fillMatrixSums(double mInput[][MAX_ROW_COL],
                    // double mS[][MAX_ROW_COL], int n, int m)
TEST(fillMatrixSums, Naive_Test) {
  const int n = 2, m = 2;
  const double mS_Expect[MAX_ROW_COL][MAX_ROW_COL] = {{1,2},{2,4}};
  double mInput[MAX_ROW_COL][MAX_ROW_COL] = {{1,1},{1,1}};
  double mS[MAX_ROW_COL][MAX_ROW_COL];

  fillMatrixSums(mInput, mS, n, m);
  test_matrix_equals(mS_Expect, mS, n, m);
}

// void calcMatrixS(double matrixS[][MAX_ROW_COL],
//                  double mSums[][MAX_ROW_COL], int n, int m, int w)
TEST(calcMatrixS, Naive_Test) {
  const int n = 3, m = 3, w = 2;
  const double mSums_Expect[MAX_ROW_COL][MAX_ROW_COL] = {{0.25,0.25,0.25},{0.25,0.25,0.25},{0.25,0.25,0.25}};
  double mInput[MAX_ROW_COL][MAX_ROW_COL] = {{1,1,1},{1,1,1},{1,1,1}};
  double mS[MAX_ROW_COL][MAX_ROW_COL];
  double mSums[MAX_ROW_COL][MAX_ROW_COL];

  fillMatrixSums(mInput, mSums, n, m);
  calcMatrixS(mS, mSums, n, m, w);
  test_matrix_equals(mSums_Expect, mS, n, m);
}

// int min(int a, int b)
TEST(min, Naive_Test) {
  const int a = 1, b = 2;
  EXPECT_EQ(1, min(a,b));
}
