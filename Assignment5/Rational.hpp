/**
 * Rational - a class that represents a ratioanl number -
 * a ratio between two integers (long ints).
 *
 * 1. This rational should be represented using two integer values (long int): the numerator
 * (MONE) and the denominator (MECHANE) of the ratio.
 * 2. The denominator cannot be zero.
 * 3. The numerator and the denominator should be coprime (MISPARIM ZARIM):
 * their greatest common divisor is 1.
 * 4. The zero element of this field is zero, and it should only be represented
 * with numerator of 0 and denominator of 1. If you reach some other
 * representation that equals 0 (like 0/5 or -0/1) change the representation to
 * 0/1 using private function fixZero().
 * The zero element is the value created by the default constructor (meaning
 * when calling constructor without any arguments) or by the constructor when
 * sending a long int argument of 0.
 * 5. For both add and mul we should remember to make sure the end
 * representation of the ratio has coprime numerator and denominator (TZIMTZUM
 * SHVARIM). For that purpose we should use the greatestCommonDivisor function
 * (private static function) and the makeRepresentationCoprime() private
 * non-static function to take care of it at the end of add and mul functions.
 * 6. If the rational value is positive, both the numerator and the denominator
 * in the representation should be positive.
 * 7. If the ratioanl value is negative, the numerator should be negative and
 * the denominator should be positive. For this, use the fixNegativity()
 * private function.
 * 8. If Rational(const long int& numerator, const long int& denominator)
 * constructor gets a zero denominator, it should fail with an assert.
 */
#pragma once

#include "myassert.hpp"

#include <gtest/gtest_prod.h>

#include <cstdlib>
#include <cmath>
#include <string>


class Rational {

    // static const char delimSign = 47;

  public:

  /**
	 * Constructors getting a long int or default which is set to 0
	 */
    Rational(const long int &value = 0)
    {
    /**
		 *  value
		 * -------
		 *    1
		 */
        _numerator = value;
        _denominator = defaultDenValue;
    };

  /**
	 * Constructors getting numerator and denominator
	 */
    Rational(const long int &numerator, const long int &denominator)
		{
    /**
		 *   numerator
		 * --------------
		 *  denominator
		 */
        myassert(denominator != 0);
        _numerator = numerator;
        _denominator = denominator;
        _fixZero();
        _fixNegativity();
        _makeRepresentationCoprime();
    };

  /**
	 * Constructors by string "numerator/denominator"
	 */
    Rational(const std::string & str)
		{
        size_t diviadorPosition = str.find(delimSign);
        std::string sNumerator = str.substr(0, diviadorPosition);
        std::string sDenominator = str.substr(diviadorPosition + delimLen);
        _numerator = stol(sNumerator, nullptr, decimalBase);
        _denominator = stol(sDenominator, nullptr, decimalBase);

        myassert(_denominator != 0);
        _fixZero();
        _fixNegativity();
        _makeRepresentationCoprime();
    };

  /**
	 * custring to string operator in pattern "_numerator/_denominator"
	 */
    operator  const std::string() const
		{
        return std::to_string(_numerator) +
                  std::string(delimLen, delimSign) +
                                std::to_string(_denominator);
    };
  /**
	 * Returns the numerator
	 */
    const long int getNumerator() const
		{
        return _numerator;
    };

  /**
	 * Returns the denominator
	 */
    const long int getDenominator() const
		{
        return _denominator;
    };

    /**
     * Returns true if the Rationals are equal and false otherwise
     */
    const bool operator==(const Rational & other) const
		{
        return _numerator == other.getNumerator()
            && _denominator == other.getDenominator();
    };

    /*
     * Return the invece of == operator
     */
    const bool operator!=(const Rational & other) const
		{
        return !(*this == other);
    };

  /**
	 * Returns the multiplication of this Rational and other
	 * Multiplication should be calculated in the way we calculate
	 * multiplication of 2 ratios (separately for the numerator and for the
	 * denominator).
	 */
    const Rational operator*(const Rational & other) const
		{
        long int a, b, c, d;
         a = _numerator;
         b = _denominator;
         c = other.getNumerator();
         d = other.getDenominator();

          /**
					 *  a     c		   ac
					 * --- * --- =  ----
					 *  b     d			 bd
					 */

         return Rational(a * c, b * d);
    };

  /**
	 * Returns the sum of this Rational and other
	 */
    const Rational operator+(const Rational & other) const {
        long int a, b, c, d;
         a = _numerator;
         b = _denominator;
         c = other.getNumerator();
         d = other.getDenominator();

        /**
				 *  a     c		   ad + cb
				 * --- + --- =  ---------
				 *  b     d			 	 bd
				 */

         return Rational(a * d + c * b, b * d);
    };


  private:
    enum define_vars {
        defaultDenValue = 1,    // default denominator value
        negativeSign = -1,
        delimLen = 1,           // length for delim sign
        decimalBase = 10        // base use for long int to
    };

    enum define_delim {
        delimSign = '/'         // delim between numerator and denominator
    };


    long int _numerator;
    long int _denominator;

    void _fixZero() {
        if (_numerator == 0)
        {
                        /**
			 *  		0    					0
			 * ------------ =  -------
			 *  any value 				1
			 */
            _denominator = defaultDenValue;
        }
    };

  /**
   * If the ratioanl value is negative, the numerator should be negative and
   * the denominator should be positive.
	 */
    void _fixNegativity() {
                /**
		 * in case of:
		 *
		 *  		_numerator > 0					(-)_numerator
		 *    -------------------- =   ----------------
		 *      _denominator < 0				(-)_denominator
 		 * or in case of:
 		 *
 		 *  		_numerator < 0					(-)_numerator
 		 *    -------------------- =   ----------------
 		 *      _denominator < 0				(-)_denominator
 		 */
        if (_denominator < 0)
        {
            _numerator = _numerator * negativeSign;
            _denominator = _denominator * negativeSign;
        }
    };

  /**
	 * minimise the numerator and denominator
	 */
    void _makeRepresentationCoprime() {
                /**
		 *   _numerator    	  _numerator / gcd()
		 * -------------- = -----------------------
		 *  _denominator 		  _denominator / gcd()
		 */
        long int nGcd = _greatestCommonDivisor(_numerator, _denominator);
        _numerator = _numerator / nGcd;
        _denominator = _denominator / nGcd;
    };


 /**
	 * retrun the gcd of two numbers
	 * gcd(a,b)
	 */
    FRIEND_TEST(rational, gcd_tests);
    static const long int _greatestCommonDivisor(const long int &a,
                                                      const long int &b) {
        long int x = a;
        long int y = b;
        while (y != 0)
        {
            long int temp = y;
            y = x % y;
            x = temp;
        }
        return abs(x);
    };

};
