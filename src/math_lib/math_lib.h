#ifndef MATH_LIB_H
#define MATH_LIB_H
#include <string>

/** 
 * @brief Adds two numbers together.
 * @param a First number to be added.
 * @param b Second number to be added.
 * @return The sum of the two numbers.
*/
double add(double a, double b);

/**
 * @brief Subtracts two numbers.
 * @param a Number to be subtracted from.
 * @param b Number to substract.
 * @return The difference between the two numbers.
 */
double subtract(double a, double b);

/**
 * @brief Multiplies two numbers.
 * @param a First number to multiply. 
 * @param b Second number to multiply.
 * @return The result of multipling a and b.
 */
double multiply(double a, double b);

/**
 * @brief Divides two numbers.
 * @param a Number to be divided from.
 * @param b Number to divide.
 * @return The result of dividing a and b.
 */
double divide(double a, double b);

/**
 * @brief Calculates factorial of a number.
 * @param n The integer to calculate the factorial for. (must not be negative)
 * @return Factorial of the number.
 */
double factorial(int n);

/**
 * @brief Raises a base number to a given power.
 * @param base The base number.
 * @param exponent The exponent (must be natural number)
 * @return The result of the base raised by exponent.
 */
double power(double base, int exponent);

/**
 * @brief Calculates the root of a number.
 * @param degree The type of root.
 * @param base The number to find the root of.
 * @return The result of the root.
 */
double root(int degree, double base);

/**
 * @brief Makes number positive.
 * @param a Any number.
 * @return The absolute value.
 */
double absoluteValue(double a);

/**
 * @brief Rounds decimal number.
 * @param a The number to round.
 * @param decimalPlaces Number of decimal places to round to.
 * @return The rounded number.
 */
double roundNumber(double a, int decimalPlaces);

/**
 * @brief Reads text to calculate.
 * @param expression The text to calculate.
 * @return The result of the expression.
 */
double evalString(std::string expression);

#endif