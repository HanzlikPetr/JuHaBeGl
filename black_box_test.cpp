//Calculator - JuHaBeGl
//Vojtech Jurok (xjurokv00)

#include <gtest/gtest.h>
#include "math_lib.h"

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