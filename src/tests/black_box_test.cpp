/**
 * @file black_box_test.cpp
 * @author Vojtech Jurok (xjurokv00)
 * @note Project: Calculator - JuHaBeGl
*/

#include <gtest/gtest.h>
#include "math_lib.h"
#include <stdexcept>

// Test suite for addition. 
// Covers positive, negative, decimal numbers, and zero.

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
    EXPECT_DOUBLE_EQ(add(0.25, 0.5), 0.75);
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

// Test suite for subtraction. 
// Covers positive, negative, decimal numbers, and zero.

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
TEST(SubTest, SubtractingNegative){
    EXPECT_DOUBLE_EQ(subtract(7.0, -3.0), 10.0);
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

// Test suite for multiplication. 
// Covers positive, negative, decimal numbers, and zero.

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
    EXPECT_DOUBLE_EQ(multiply(1.5, 0.5), 0.75);
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

// Test suite for division. 
// Covers standard calculations, decimal numbers, and division by zero.

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

/*
 * Tests suite for the factorial function.
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

/*
 * Test suite for power function.
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

/*
 * Test suite for n-th root function.
 * Covers standart calculations,
 * edge cases (0,1) 
 * and exceptions handling for invalid inputs
 */

/**
 * @brief Tests root of two positive numbers.
 */
TEST(RootTest, PositiveNumbers){
    EXPECT_DOUBLE_EQ(root(2, 9.0), 3.0); 
}

/**
 * @brief Tests root with decimal base number.
 */
TEST(RootTest, DecimalBase){
    EXPECT_DOUBLE_EQ(root(2, 6.25), 2.5); 
}

/**
 * @brief Tests root with zero base.
 */
TEST(RootTest, ZeroBase){
    EXPECT_DOUBLE_EQ(root(2, 0.0), 0.0); 
}

/**
 * @brief Tests root with base with number one.
 */
TEST(RootTest, BaseOne){
    EXPECT_DOUBLE_EQ(root(3, 1.0), 1.0); 
}

/**
 * @brief Tests root with degree with number one.
 */
TEST(RootTest, DegreeOne){
    EXPECT_DOUBLE_EQ(root(1, 22.0), 22.0); 
}

/**
 * @brief Tests root with odd number of degree and negative base.
 */
TEST(RootTest, NegBaseOddDegree){
    EXPECT_DOUBLE_EQ(root(3, -8.0), -2.0); 
}

/**
 * @brief Tests root with even number of degree and negative base.
 */
TEST(RootTest, NegBaseEvenDegree){
    EXPECT_THROW(root(2.0, -9.0), std::invalid_argument); 
}

/**
 * @brief Tests root with zero degree.
 */
TEST(RootTest, ZeroDegree){
    EXPECT_THROW(root(0, 4.0), std::invalid_argument); 
}

/**
 * @brief Tests root with positive base and negative degree.
 */
TEST(RootTest, NegativeDegree){
    EXPECT_DOUBLE_EQ(root(-2, 4.0), 0.5); 
}

/*
* Test suite for the absolute value function
* Covers positive and negative numbers and zero
*/

/**
 * @brief Tests absolute value with positive number.
 */
TEST(AbsoluteTest, PositiveNumbers){
    EXPECT_DOUBLE_EQ(absoluteValue(82.0), 82.0); 
}

/**
 * @brief Tests absolute value with negative number.
 */
TEST(AbsoluteTest, NegativeNumbers){
    EXPECT_DOUBLE_EQ(absoluteValue(-42.0), 42.0); 
}

/**
 * @brief Tests absolute value with zero.
 */
TEST(AbsoluteTest, Zero){
    EXPECT_DOUBLE_EQ(absoluteValue(0), 0); 
}

/*
 * Test suite for the rounding function.
 * Covers rounding up, down and whole numbers,
 * and exact half values.
 */

/**
 * @brief Tests rounding of positive number to round up.
 */
TEST(RoundTest, PositiveNumberUp){
    EXPECT_DOUBLE_EQ(roundNumber(3.8), 4.0); 
}

/**
 * @brief Tests rounding of positive number to round down.
 */
TEST(RoundTest, PositiveNumberDown){
    EXPECT_DOUBLE_EQ(roundNumber(2.2), 2.0); 
}

/**
 * @brief Tests rounding of positive number ending .5.
 */
TEST(RoundTest, PositiveNumberHalfValue){
    EXPECT_DOUBLE_EQ(roundNumber(5.5), 6.0); 
}

/**
 * @brief Tests rounding of zero.
 */
TEST(RoundTest, Zero){
    EXPECT_DOUBLE_EQ(roundNumber(0.0), 0.0); 
}

/**
 * @brief Tests rounding of a whole number.
 */
TEST(RoundTest, WholeNumber){
    EXPECT_DOUBLE_EQ(roundNumber(10.0), 10.0); 
}

/**
 * @brief Tests rounding of negative number towards zero.
 */
TEST(RoundTest, NegativeNumberDown){
    EXPECT_DOUBLE_EQ(roundNumber(-6.2), -6.0); 
}

/**
 * @brief Tests rounding of negative number away from zero.
 */
TEST(RoundTest, NegativeNumberUp){
    EXPECT_DOUBLE_EQ(roundNumber(-8.8), -9.0); 
}

/**
 * @brief Tests rounding of negative number ending .5.
 */
TEST(RoundTest, NegativeNumberHalfValue){
    EXPECT_DOUBLE_EQ(roundNumber(-5.5), -6.0); 
}


/*
 * Test suite for the EvalString function.
 * Covers basic arithmetic parsing, operator precedence,
 * brackets, whitespace handling, and syntax error exceptions.
 */


/**
 * @brief Tests EvalString function with basic numbers.
 */
TEST(EvalStringTest, BasicNumbers){
    EXPECT_DOUBLE_EQ(evalString("2 + 3"), 5.0); 
}

/**
 * @brief Tests EvalString function with decimal numbers.
 */
TEST(EvalStringTest, DecimalNumbers){
    EXPECT_DOUBLE_EQ(evalString("2.5 * 4"), 10.0); 
}

/**
 * @brief Tests EvalString function with negative numbers first.
 */
TEST(EvalStringTest, NegativeNumberFirst){
    EXPECT_DOUBLE_EQ(evalString("-4 + 5"), 1.0); 
}

/**
 * @brief Tests basic operator precedence.
 */
TEST(EvalStringTest, OperatorPrecedence){
    EXPECT_DOUBLE_EQ(evalString("2 + 3 * 6"), 20.0); 
}

/**
 * @brief Tests brackets precedence.
 */
TEST(EvalStringTest, BracketsPrecedence){
    EXPECT_DOUBLE_EQ(evalString("(2 + 3) * 6"), 30.0); 
}

/**
 * @brief Tests nested brackets precedence.
 */
TEST(EvalStringTest, NestedBracketsPrecedence){
    EXPECT_DOUBLE_EQ(evalString("((2 + 3) * 6) / 6"), 5.0); 
}

/**
 * @brief Tests EvalString function with more whitespaces.
 */
TEST(EvalStringTest, MoreWhitespaces){
    EXPECT_DOUBLE_EQ(evalString(" 2  +  3 "), 5.0); 
}

/**
 * @brief Tests EvalString function with no whitespaces.
 */
TEST(EvalStringTest, NoWhitespaces){
    EXPECT_DOUBLE_EQ(evalString("10/5"), 2.0); 
}

/**
 * @brief Tests EvalString function with more operators in a row.
 */
TEST(EvalStringTest, MoreOperators){
    EXPECT_THROW(evalString("2 + * 3"), std::invalid_argument); 
}

/**
 * @brief Tests EvalString function with missing number.
 */
TEST(EvalStringTest, MissingNumber){
    EXPECT_THROW(evalString("2 * "), std::invalid_argument); 
}

/**
 * @brief Tests failure with letters or invalid characters.
 */
TEST(EvalStringTest, InvalidCharacters){
    EXPECT_THROW(evalString("2 * asd"), std::invalid_argument); 
}

/**
 * @brief Tests EvalString function with empty string.
 */
TEST(EvalStringTest, EmptyString){
    EXPECT_THROW(evalString(""), std::invalid_argument); 
}
