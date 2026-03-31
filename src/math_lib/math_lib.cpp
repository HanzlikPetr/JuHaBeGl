/**
 * @file math_lib.cpp
 * @author Marek Beran (xberanm00)
 * @note Project: Calculator - JuHaBeGl
 */

#include "math_lib.h"

#include <stack>
#include <stdexcept>
#include <vector>

enum TokenType {
    NUMBER,
    OPERATOR,
    FACTORIAL,
    ROUND,
    ABS_OPEN,
    ABS_CLOSE,
    ABS_FUNC,
    BRACKET_OPEN,
    BRACKET_CLOSE
};

struct Token {
    TokenType type;
    double value;
    char operation;
};

double absoluteValue(double a) { return a >= 0 ? a : -a; }

double add(double a, double b) { return a + b; }

double subtract(double a, double b) { return a - b; }

double multiply(double a, double b) { return a * b; }

double divide(double a, double b) {
    if (b == 0.0) {
        throw std::invalid_argument("Error: Division by zero!\n");
    }

    return a / b;
}

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

double root(int degree, double base) {
    /* Check for conditions by definition */
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

    /* tolerance for error */
    double tolerance = 1e-12;

    double previous;

    /* Applying the Newton-Raphson method */
    do {
        previous = result;

        result = ((absDegree - 1) * result + base / (power(result, absDegree - 1))) / absDegree;
    } while (absoluteValue(result - previous) > tolerance * absoluteValue(previous));

    return degree > 0 ? result : (1 / result);
}

// TODO
double roundNumber(double a, int decimalPlaces) {
    int places = power(10, decimalPlaces);
    double abs = absoluteValue(a);
    abs *= places;
    double intPart = (double)(long long)(abs);
    double decimalPart = abs - intPart;

    if (decimalPart >= 0.5) {
        intPart += 1.0;
    }

    if (a < 0) {
        intPart *= -1;
    }

    return intPart / places;
}

int priority(char operation) {
    if (operation == '^') return 3;
    if (operation == '*' || operation == '/') return 2;
    if (operation == '+' || operation == '-') return 1;
    if (operation == '~') return 4;
    return 0;
}

bool rigthAssociative(char operation) { return operation == '^'; }

std::vector<Token> parseInput(std::string expression) {
    std::vector<Token> tokens;
    bool abs_open = true;

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

            i--;
        } else if ((c == '+') || (c == '*') || (c == '/') || (c == '^')) {
            tokens.push_back({OPERATOR, 0.0, c});
        } else if (c == '-') {
            if (tokens.empty() || tokens[tokens.size() - 1].type != NUMBER) {
                tokens.push_back({NUMBER, 0.0, 0});
            }
            tokens.push_back({OPERATOR, 0.0, '-'});
        } else if (c == '(') {
            tokens.push_back({BRACKET_OPEN, 0.0, 0});
        } else if (c == ')') {
            tokens.push_back({BRACKET_CLOSE, 0.0, 0});
        } else if (c == '~') {
            // tady
            tokens.push_back({OPERATOR, 0.0, '~'});
        } else if (c == '!') {
            tokens.push_back({FACTORIAL, 0.0, 0});
        } else if (c == '|') {
            if (abs_open) {
                tokens.push_back({ABS_OPEN, 0.0, 0});
                abs_open = !abs_open;
            } else {
                tokens.push_back({ABS_CLOSE, 0.0, 0});
                abs_open = !abs_open;
            }
        } else {
            throw std::invalid_argument("Error: Unexpected input!\n");
        }
    }

    return tokens;
}

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
            while (!operation.empty() && operation.top().type != BRACKET_OPEN) {
                output.push_back(operation.top());
                operation.pop();
            }

            if (operation.empty()) {
                throw std::invalid_argument("Error: Empty brackets!\n");
            }

            operation.pop();

            // here could be the factorial also I quess
            if (!operation.empty() && operation.top().type == ROUND) {
                output.push_back(operation.top());
                operation.pop();
            }
        } else if (token.type == ABS_CLOSE) {
            while (!operation.empty() && operation.top().type != ABS_OPEN) {
                output.push_back(operation.top());
                operation.pop();
            }

            if (operation.empty()) {
                throw std::invalid_argument("Error: Empty absolute value!\n");
            }

            operation.pop();
            output.push_back({ABS_FUNC, 0.0, 0});
        } else if (token.type == OPERATOR) {
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

double evaluate(std::vector<Token> postfix) {
    std::stack<double> numbers;

    for (auto token : postfix) {
        if (token.type == NUMBER) {
            numbers.push(token.value);
        } else if (token.type == OPERATOR) {
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
                    // choose between power and root - TODO
                    result = power(a, (int)b);
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
            double a;
            if (numbers.size() >= 1) {
                a = numbers.top();
            } else {
                throw std::invalid_argument("Error: Too many operators!\n");
            }
            numbers.pop();
            double result;

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

double evalString(std::string expression) {
    auto tokens = parseInput(expression);
    auto postfix = shuntingYard(tokens);
    return evaluate(postfix);
}
