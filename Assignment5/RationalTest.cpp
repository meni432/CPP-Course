#include "Rational.hpp"

#include "gtest/gtest.h"




TEST(rational, rational_tests1)
{
    Rational r1(2,4);
    Rational r2(1,1);

  EXPECT_EQ(1, r1.getNumerator());
	EXPECT_EQ(2, r1.getDenominator());
	EXPECT_EQ(Rational(3,2), r1+r2);
	EXPECT_EQ(Rational(1,2), r1*r2);
}


TEST(rational, test_string_constructor)
{
    Rational r1 ("2/4");
    Rational r2 ("1/1");
    Rational r3 ("0/100");


  //check  string constructor with positiove number
  EXPECT_EQ(1, r1.getNumerator());
	EXPECT_EQ(2, r1.getDenominator());

  EXPECT_EQ(Rational(1,2), r1);
  EXPECT_EQ(Rational(1,1), r2);
  EXPECT_EQ(Rational(0,1), r3);

  // check string constructor with negative number
  EXPECT_EQ(Rational(-1,3),Rational("-3/9"));
  EXPECT_EQ(Rational(-1,3),Rational("3/-9"));
  EXPECT_EQ(Rational(1,3),Rational("-3/-9"));

}

TEST(rational, test_string_custing)
{
  Rational r1 ("2/4");
  std::string s1 = r1;
  EXPECT_EQ("1/2", s1);

  Rational r2 (0);

  std::string s2 = r2;
  EXPECT_EQ("0/1", s2);
}

TEST(rational, test_minus)
{
    Rational r1 ("2/-4");
    Rational r2 (0,-1);
    Rational r3 (8/-4);
    Rational r4 (-8/-2);

	EXPECT_EQ(Rational(-1,2), r1);
	EXPECT_EQ(Rational(0,1), r2);;
	EXPECT_EQ(Rational(-2,1), r3);
	EXPECT_EQ(Rational(4,1), r4);
}

TEST (rational, empty_constructor_test)
{
  Rational r1;
  EXPECT_EQ(r1.getNumerator(), 0);
  EXPECT_EQ(r1.getDenominator(), 1);
  EXPECT_EQ(Rational(0,1), r1);
}

TEST(rational, sum_tests)
{
  Rational r1 (1,4);
  Rational r2 (2,5);
  Rational r3;
  Rational negSign("-1/1");

  EXPECT_EQ(Rational(13,20), r1+r2);
  EXPECT_EQ(Rational(13,20),r1+r2+r3);
  EXPECT_EQ(Rational(13,20), r1+(r2*negSign)+r2+r2);
}

TEST(rational, multiplay_tests)
{
  Rational r1 (2);
  Rational r2 (2,3);
  Rational negSign(-1,1);
  EXPECT_EQ(Rational(4,3), r1*r2);
  EXPECT_EQ(Rational(2,3), r1+r1*negSign+r2);

}

TEST(rational, gcd_tests)
{
  Rational r;
  EXPECT_EQ(3,r._greatestCommonDivisor(9,6));
  EXPECT_EQ(3,r._greatestCommonDivisor(-9,-6));
  EXPECT_EQ(1,r._greatestCommonDivisor(1,0));
  EXPECT_EQ(4,r._greatestCommonDivisor(4,8));
  EXPECT_EQ(4,r._greatestCommonDivisor(8,4));
  EXPECT_EQ(4,r._greatestCommonDivisor(-4,8));
  EXPECT_EQ(4,r._greatestCommonDivisor(4,-8));
  EXPECT_EQ(4,r._greatestCommonDivisor(-4,-8));
  EXPECT_EQ(4,r._greatestCommonDivisor(8,-4));
}
