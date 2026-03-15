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