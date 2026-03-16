/**
 * @file black_box_test.cpp
 * @author Vojtech Jurok (xjurokv00)
 * @note Project: Calculator - JuHaBeGl
*/

#include <gtest/gtest.h>
#include "math_lib.h"
#include <stdexcept>

/**
 * @brief Tests addition of two positive numbers.
 */
TEST(AddTest, PositiveNumbers){
    EXPECT_DOUBLE_EQ(add(2.0, 4.0), 6.0);
}

/**
 * @brief Tests addition of two negative numbers.
 */
TEST(AddTest, NegativeNumbers){
    EXPECT_DOUBLE_EQ(add(-1.0, -3.0), -4.0);
}

/**
 * @brief Tests addition of positive and negative numbers.
 */
TEST(AddTest, PosNegNumbers){
    EXPECT_DOUBLE_EQ(add(-5.0, 9.0), 4.0);
}

/**
 * @brief Tests addition of two decimal numbers.
 */
TEST(AddTest, DecimalNumbers){
    EXPECT_DOUBLE_EQ(add(0.1, 0.2), 0.3);
}

/**
 * @brief Tests addition with zero.
 */
TEST(AddTest, Zero){
    EXPECT_DOUBLE_EQ(add(256.256, 0.0), 256.256);
}

/**
 * @brief Tests addition with big numbers.
 */
TEST(AddTest, BigNumbers){
    EXPECT_DOUBLE_EQ(add(1000000.0, 200000.0 ), 1200000.0);
}




/**
 * @brief Tests subtraction of two positive numbers with positive result.
 */
TEST(SubTest, PositiveNumPosRes){
    EXPECT_DOUBLE_EQ(subtract(5.0, 1.0), 4.0);
}

/**
 * @brief Tests subtraction of two positive numbers with negative result.
 */
TEST(SubTest, PositiveNumNegRes){
    EXPECT_DOUBLE_EQ(subtract(5.0, 8.0), -3.0);
}

/**
 * @brief Tests subtraction of negative number from a positive one.
 */
TEST(SubTest, SubstractingNegative){
    EXPECT_DOUBLE_EQ(subtract(7.0, -3,0), 10,0);
}

/**
 * @brief Tests subtraction of two negative numbers.
 */
TEST(SubTest, NegativeNumbers){
    EXPECT_DOUBLE_EQ(subtract(-8.0, -1.0), -7.0);
}

/**
 * @brief Tests subtraction of two decimal numbers.
 */
TEST(SubTest, DecimalNumbers){
    EXPECT_DOUBLE_EQ(subtract(4.4, -2.2), 6.6);
}

/**
 * @brief Tests subtraction with zero.
 */
TEST(SubTest, Zero){
    EXPECT_DOUBLE_EQ(subtract(5.0, 0.0), 5.0);
}

/**
 * @brief Tests substraction with big numbers.
 */
TEST(SubTest, BigNumbers){
    EXPECT_DOUBLE_EQ(subtract(1000000.0, 200000.0), 800000.0);
}




/**
 * @brief Tests multiplication with positive numbers.
 */
TEST(MultiplyTest, PositiveNumbers){
    EXPECT_DOUBLE_EQ(multiply(5.0, 2.0), 10.0);
}

/**
 * @brief Tests multiplication with negative numbers.
 */
TEST(MultiplyTest, NegativeNumbers){
    EXPECT_DOUBLE_EQ(multiply(-2.0, -2.0), 4.0);
}

/**
 * @brief Tests multiplication with negative and positive number.
 */
TEST(MultiplyTest, PosNegNumbers){
    EXPECT_DOUBLE_EQ(multiply(-2.0, 2.0), -4.0);
}

/**
 * @brief Tests multiplication with decimal number.
 */
TEST(MultiplyTest, DecimalNumbers){
    EXPECT_DOUBLE_EQ(multiply(1.2, 0.8), 0.96);
}

/**
 * @brief Tests multiplication with zero.
 */
TEST(MultiplyTest, Zero){
    EXPECT_DOUBLE_EQ(multiply(6.0, 0.0), 0.0);
}

/**
 * @brief Tests multiplication with big numbers.
 */
TEST(MultiplyTest, BigNumbers){
    EXPECT_DOUBLE_EQ(multiply(50000.0, 20000.0), 1000000000.0);
}



/**
 * @brief Tests division with positive numbers and whole result.
 */ 
TEST(DivisionTest, PosNumbersWholeRes){
    EXPECT_DOUBLE_EQ(divide(10.0, 2.0), 5.0);
}

/**
 * @brief Tests division with positive numbers and decimal result.
 */ 
TEST(DivisionTest, PosNumbersDecimalRes){
    EXPECT_DOUBLE_EQ(divide(5.0, 2.0), 2.5);
}

/**
 * @brief Tests division of positive and negative numbers.
 */ 
TEST(DivisionTest, PosNegNumbers){
    EXPECT_DOUBLE_EQ(divide(-6.0, 3.0), -2.0);
}

/**
 * @brief Tests division with negative numbers.
 */ 
TEST(DivisionTest, NegativeNumbers){
    EXPECT_DOUBLE_EQ(divide(-4.0, -2.0), 2.0);
}

/**
 * @brief Tests division with decimal numbers.
 */ 
TEST(DivisionTest, DecimalNumbers){
    EXPECT_DOUBLE_EQ(divide(2.6, 0.2), 13.0);
}

/**
 * @brief Tests division where the divided number is zero.
 */ 
TEST(DivisionTest, FirstZero){
    EXPECT_DOUBLE_EQ(divide(0.0, 6.0), 0.0);
}

/**
 * @brief Tests division where the number I divide with is a zero.
 */ 
TEST(DivisionTest, DivideByZero){
    EXPECT_THROW(divide(5.0, 0.0), std::invalid_argument);
}

/**
 * @brief Tests division where the first number is smaller than the second.
 */ 
TEST(DivisionTest, SmallerDividedByLarger){
    EXPECT_DOUBLE_EQ(divide(2.0, 10.0), 0.2);
}

/**
 * @brief Tests division with big numbers.
 */ 
TEST(DivisionTest, BigNumbers){
    EXPECT_DOUBLE_EQ(divide(1000000.0, 2000.0), 500.0);
}

/**
 * @brief Tests suite for the factorial function.
 * 
 * Covers standard positive inputs, edge cases(0, 1)
 * and invalid negative inputs
 */

/**
 * @brief Tests factorial with positive number.
 */ 
TEST(FactorialTest, PositiveNumbers){
    EXPECT_DOUBLE_EQ(factorial(3), 6.0);
}

/**
 * @brief Tests factorial with zero.
 */ 
TEST(FactorialTest, InputZero){
    EXPECT_DOUBLE_EQ(factorial(0), 1.0);
}

/**
 * @brief Tests factorial with one as an input.
 */ 
TEST(FactorialTest, InputOne){
    EXPECT_DOUBLE_EQ(factorial(1), 1.0);
}

/**
 * @brief Tests factorial with negative number.
 */ 
TEST(FactorialTest, NegativeNumbers){
    EXPECT_THROW(factorial(-4), std::invalid_argument);
}

/**
 * @brief Tests factorial with big number.
 */ 
TEST(FactorialTest, BigNumbers){
    EXPECT_DOUBLE_EQ(factorial(10), 3628800.0);
}

/**
 * @brief Test suite for power function.
 * 
 * Covers standard positive and negative inputs
 * as well as edge cases (0,1) and invalid ZeroBaseNegExponent
 * and BothZero 
 */


/**
 * @brief Tests power of a positive number.
 */
TEST(PowerTest, BothPositive){
    EXPECT_DOUBLE_EQ(power(10.0, 2), 100.0); 
}

/**
 * @brief Tests power with decimal base.
 */
TEST(PowerTest, DecimalBase){
    EXPECT_DOUBLE_EQ(power(2.5, 2), 6.25); 
}

/**
 * @brief Tests power with exponent of 1.
 */
TEST(PowerTest, ExponentOne){
    EXPECT_DOUBLE_EQ(power(9.0, 1), 9.0); 
}

/**
 * @brief Tests power with exponent of 0.
 */
TEST(PowerTest, ExponentZero){
    EXPECT_DOUBLE_EQ(power(9.0, 0), 1.0); 
}

/**
 * @brief Tests power with base of 0.
 */
TEST(PowerTest, BaseZero){
    EXPECT_DOUBLE_EQ(power(0.0, 4), 0.0); 
}

/**
 * @brief Tests power with negative base and even exponent.
 */
TEST(PowerTest, NegBaseEvenExponent){
    EXPECT_DOUBLE_EQ(power(-4.0, 2), 16.0); 
}

/**
 * @brief Tests power with negative base and odd exponent.
 */
TEST(PowerTest, NegBaseOddExponent){
    EXPECT_DOUBLE_EQ(power(-4.0, 3), -64.0); 
}

/**
 * @brief Tests power of a negative exponent and positive base.
 */
TEST(PowerTest, NegExponPosBase){
    EXPECT_DOUBLE_EQ(power(10.0, -2), 0.01); 
}

/**
 * @brief Tests power of zero base and negative exponent.
 */
TEST(PowerTest, ZeroBaseNegExponent){
    EXPECT_THROW(power(0.0, -2), std::invalid_argument); 
}

/**
 * @brief Tests power of zero base and zero exponent.
 */
TEST(PowerTest, BothZero){
    EXPECT_THROW(power(0.0, 0.0), std::invalid_argument); 
}
