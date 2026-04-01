/**
 * @file math_lib.cpp
 * @author Marek Beran (xberanm00)
 * @note Project: Calculator - JuHaBeGl
 */

#include "math_lib.h"

#include <stack>
#include <stdexcept>
#include <vector>

/**
 * @brief Token types for expression parsing.
 *
 * Represents the different types of tokens that can appear
 * in a mathematical expression during parsing.
 */
enum TokenType {
    NUMBER,
    OPERATOR,
    FACTORIAL,
    //ROUND,
    ABS_OPEN,
    ABS_CLOSE,
    ABS_FUNC,
    BRACKET_OPEN,
    BRACKET_CLOSE
};

/**
 * @brief Represents a token in the mathematical expression.
 *
 * Stores the type of token and it's associated value of operator.
 */
struct Token {
    TokenType type;
    double value;
    char operation;
};

/**
 * @brief Makes number positive.
 * @param a Any number.
 * @return The absolute value.
 */
double absoluteValue(double a) { return a >= 0 ? a : -a; }

/**
 * @brief Adds two numbers together.
 * @param a First number to be added.
 * @param b Second number to be added.
 * @return The sum of the two numbers.
*/
double add(double a, double b) { return a + b; }

/**
 * @brief Subtracts two numbers.
 * @param a Number to be subtracted from.
 * @param b Number to substract.
 * @return The difference between the two numbers.
 */
double subtract(double a, double b) { return a - b; }

/**
 * @brief Multiplies two numbers.
 * @param a First number to multiply.
 * @param b Second number to multiply.
 * @return The result of multipling a and b.
 */
double multiply(double a, double b) { return a * b; }

/**
 * @brief Divides two numbers.
 * @param a Number to be divided from.
 * @param b Number to divide.
 * @return The result of dividing a and b.
 */
double divide(double a, double b) {
    if (b == 0.0) {
        throw std::invalid_argument("Error: Division by zero!\n");
    }

    return a / b;
}

/**
 * @brief Calculates factorial of a number.
 * @param n The integer to calculate the factorial for. (must not be negative)
 * @return Factorial of the number.
 */
double factorial(int n) {
    if (n < 0.0) {
        throw std::invalid_argument("Error: Factorial for negative numbers is not defined!\n");
    }

    double result = 1;

    while (n > 0) {
        result *= n--;
    }

    return result;
}

/**
 * @brief Raises a base number to a given power.
 * @param base The base number.
 * @param exponent The exponent (must be natural number)
 * @return The result of the base raised by exponent.
 */
double power(double base, int exponent) {
    double result = 1;

    if (base == 0 && exponent <= 0) {
        throw std::invalid_argument("Error: Undefined\n");
    }

    for (int _ = absoluteValue(exponent); _ > 0; _--) {
        result *= base;
    }

    return exponent >= 0 ? result : (1 / result);
}

/**
 * @brief Calculates the root of a number.
 * @param degree The type of root.
 * @param base The number to find the root of.
 * @return The result of the root.
 */
double root(int degree, double base) {
    if (degree == 0) {
        throw std::invalid_argument("Error: Invalid degree of root!\n");
    } else if ((degree % 2 == 0) && (base < 0)) {
        throw std::invalid_argument("Error: Result is not a real number!\n");
    } else if (base == 0 && degree < 0) {
        throw std::invalid_argument("Error: Division by hehehzero!\n");
    }

    double absBase = absoluteValue(base);
    int absDegree = absoluteValue(degree);

    /* Early return for simple numbers */
    if ((absBase == 1.0) || (base == 0.0) || (degree == 1)) {
        return base;
    }

    /* Initial guess for Newton-Raphson method */
    double result = absBase < 1 ? 1 : absBase;

    /* Tolerance for error */
    double tolerance = 1e-12;

    double previous;

    /* Applying the Newton-Raphson method */
    do {
        previous = result;

        result = ((absDegree - 1) * result + base / (power(result, absDegree - 1))) / absDegree;
    } while (absoluteValue(result - previous) > tolerance * absoluteValue(previous));

    return degree > 0 ? result : (1 / result);
}

/**
 * @brief Rounds decimal number.
 * @param a The number to round.
 * @param decimalPlaces Number of decimal places to round to.
 * @return The rounded number.
 */
double roundNumber(double a, int decimalPlaces) {
    int places = power(10, decimalPlaces);
    double abs = absoluteValue(a);

    /* Scales the absolute value */
    abs *= places;

    /* Truncates the scaled number */
    double intPart = (double)(long long)(abs);
    double decimalPart = abs - intPart;

    /* Rounds up the original number if necessary */
    if (decimalPart >= 0.5) {
        intPart += 1.0;
    }

    /* Negates the number if necessary */
    if (a < 0) {
        intPart *= -1;
    }

    /* Scales back the number */
    return intPart / places;
}

/**
 * @brief Performs a root or power.
 * @param base The base used for calculation.
 * @param exponent The exponent to choose between root and power and to calculate it.
 * @return The result of root or power.
 */
double rootOrPower(double base, double exponent) {
    /* Check if the operation should be root */
    if (0 < absoluteValue(exponent) && absoluteValue(exponent) < 1) {
        exponent = 1 / exponent;

        if (exponent != roundNumber(exponent, 0)) {
            throw std::invalid_argument("Error: Exponent must be a round number\n");
        }

        /* Calculates a root */
        return root((int)exponent, base);
    }

    if (exponent != roundNumber(exponent, 0)) {
        throw std::invalid_argument("Error: Exponent must be a round number\n");
    }

    /* Calculates a power */
    return power(base, (int)exponent);
}

/**
 * @brief Decides priority of operation.
 * @param operation The operation to give priority to.
 * @return The priority of operation.
 */
int priority(char operation) {
    if (operation == '^') return 3;
    if (operation == '*' || operation == '/') return 2;
    if (operation == '+' || operation == '-') return 1;
    if (operation == '~') return 4;
    return 0;
}

/**
 * @brief Checks right-associativeness of operation.
 * @param operation The operation to check the right-associativeness of.
 * @return The result of root or power.
 */
bool rigthAssociative(char operation) { return operation == '^'; }

/**
 * @brief Parse given expression into tokens.
 * @param expression The expression to be parsed.
 * @return The tokens parsed from expression.
 */
std::vector<Token> parseInput(std::string expression) {
    std::vector<Token> tokens;
    bool abs_open = true;
    bool expectOperand = true;

    if (expression.size() == 0) {
        throw std::invalid_argument("Error: No input given\n");
    }

    /* Scan given expression */
    for (size_t i = 0; i < expression.size(); i++) {
        char c = expression[i];

        if (c == ' ') continue;

        /* Get a number */
        if (((c >= '0') && (c <= '9')) || (c == '.')) {
            size_t start = i;
            /* Get the whole number */
            while (i < expression.size() &&
                   (((expression[i] >= '0') && (expression[i] <= '9')) || (expression[i] == '.'))) {
                i++;
            }

            std::string numberStr = expression.substr(start, i - start);
            double number = std::stod(numberStr);

            tokens.push_back({NUMBER, number, 0});
            expectOperand = false;

            i--;
        } else if ((c == '+') || (c == '*') || (c == '/') || (c == '^') || (c == '~')) {
            /* Get a binary operator */
            tokens.push_back({OPERATOR, 0.0, c});
            expectOperand = true;
        } else if (c == '-') {
            /* Get a minus operator */
            /* Check if the minus is unary operator*/
            if (expectOperand) {
                tokens.push_back({NUMBER, 0.0, 0});
            }

            tokens.push_back({OPERATOR, 0.0, '-'});
            expectOperand = true;
        } else if (c == '(') {
            /* Get open bracket */
            tokens.push_back({BRACKET_OPEN, 0.0, 0});
            expectOperand = true;
        } else if (c == ')') {
            /* Get close bracket */
            tokens.push_back({BRACKET_CLOSE, 0.0, 0});
            expectOperand = false;
        } else if (c == '!') {
            /* Get factorial */
            tokens.push_back({FACTORIAL, 0.0, 0});
        } else if (c == '|') {
            /* Get absolute value bracket */
            /* Check if the bracket is openning bracket */
            if (abs_open) {
                tokens.push_back({ABS_OPEN, 0.0, 0});
                abs_open = !abs_open;
                expectOperand = true;
            } else {
                /* Closing bracket */
                tokens.push_back({ABS_CLOSE, 0.0, 0});
                abs_open = !abs_open;
                expectOperand = false;
            }
        } else {
            throw std::invalid_argument("Error: Unexpected input!\n");
        }
    }

    return tokens;
}

/**
 * @brief Performs a Shunting Yard Algorithm.
 * @param tokens The tokens to do the algirithm over.
 * @return Correctly sorted tokens for evaluation.
 */
std::vector<Token> shuntingYard(std::vector<Token> tokens) {
    std::vector<Token> output;
    std::stack<Token> operation;

    for (Token token : tokens) {
        if (token.type == NUMBER) {
            output.push_back(token);
        } else if (token.type == FACTORIAL) {
            output.push_back(token);
        } else if ((token.type == BRACKET_OPEN) ||
                   (token.type == ABS_OPEN)) {
            operation.push(token);
        } else if (token.type == BRACKET_CLOSE) {
            /* Add tokens inside brackets higher in final vector */
            while (!operation.empty() && operation.top().type != BRACKET_OPEN) {
                output.push_back(operation.top());
                operation.pop();
            }

            if (operation.empty()) {
                throw std::invalid_argument("Error: Empty brackets!\n");
            }

            operation.pop();


            /*if (!operation.empty() && operation.top().type == ROUND) {
                output.push_back(operation.top());
                operation.pop();
            }*/
        } else if (token.type == ABS_CLOSE) {
            /* Add tokens inside absolute value higher in final vector */
            while (!operation.empty() && operation.top().type != ABS_OPEN) {
                output.push_back(operation.top());
                operation.pop();
            }

            if (operation.empty()) {
                throw std::invalid_argument("Error: Empty absolute value!\n");
            }

            /* Add operation that performs absolute value */
            operation.pop();
            output.push_back({ABS_FUNC, 0.0, 0});
        } else if (token.type == OPERATOR) {
            /* Sort operators by priority and by associativeness */
            while (!operation.empty() && operation.top().type == OPERATOR &&
                   (priority(operation.top().operation) > priority(token.operation) ||
                    (priority(operation.top().operation) == priority(token.operation) &&
                     !rigthAssociative(token.operation)))) {
                output.push_back(operation.top());
                operation.pop();
            }

            operation.push(token);
        }
    }

    /* Add the rest of the operators to the final vector */
    while (!operation.empty()) {
        if (operation.top().type == BRACKET_OPEN || operation.top().type == BRACKET_CLOSE ||
            operation.top().type == ABS_OPEN || operation.top().type == ABS_CLOSE) {
            throw std::invalid_argument("Error: Mismatched brackets\n");
        }

        output.push_back(operation.top());
        operation.pop();
    }

    return output;
}

/**
 * @brief Evaluates the tokens in postfix.
 * @param postfix The postfix to be evaluated.
 * @return The result of mathematical operations.
 */
double evaluate(std::vector<Token> postfix) {
    std::stack<double> numbers;

    for (auto token : postfix) {
        if (token.type == NUMBER) {
            numbers.push(token.value);
        } else if (token.type == OPERATOR) {
            /* Get numbers for binary operations */
            double b;
            double a;
            if (numbers.size() >= 2) {
                b = numbers.top();
                numbers.pop();
                a = numbers.top();
                numbers.pop();
            } else {
                throw std::invalid_argument("Error: Too many operators!\n");
            }

            double result;

            /* Perform correct operation */
            switch (token.operation) {
                case '+':
                    result = add(a, b);
                    break;

                case '-':
                    result = subtract(a, b);
                    break;

                case '*':
                    result = multiply(a, b);
                    break;
                    ;

                case '/':
                    result = divide(a, b);
                    break;

                case '^':
                    result = rootOrPower(a, b);
                    break;

                case '~':
                    result = roundNumber(a, b);
                    break;

                default:
                    throw std::runtime_error("Error: Unknown operator\n");
                    break;
            }

            numbers.push(result);
        } else {
            /* Get a number for unary operations */
            double a;
            if (numbers.size() >= 1) {
                a = numbers.top();
            } else {
                throw std::invalid_argument("Error: Too many operators!\n");
            }
            numbers.pop();
            double result;

            /* Perform correct operation */
            switch (token.type) {
                case FACTORIAL:
                    result = factorial((int)a);
                    break;

                case ABS_FUNC:
                    result = absoluteValue(a);
                    break;

                default:
                    throw std::runtime_error("Error: Unexpected token in postfix expression\n");
                    break;
            }

            numbers.push(result);
        }
    }

    return numbers.top();
}

/**
 * @brief Reads text to calculate.
 * @param expression The text to calculate.
 * @return The result of the expression.
 */
double evalString(std::string expression) {
    auto tokens = parseInput(expression);
    auto postfix = shuntingYard(tokens);
    return evaluate(postfix);
}
