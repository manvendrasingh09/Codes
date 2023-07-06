#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>

std::unordered_map<std::string, std::string> expressions;  // To store expressions

// Function to perform constant propagation
std::string constantPropagation(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    std::string result;

    while (std::getline(iss, token, ' ')) {
        if (token[0] >= 'a' && token[0] <= 'z') {
            // Token is a variable
            if (expressions.find(token) != expressions.end()) {
                // Variable has an expression value
                result += expressions[token];
            } else {
                // Variable has no expression value, keep it as is
                result += token;
            }
        } else {
            // Token is an operator or constant value
            result += token;
        }
        result += ' ';
    }

    return result;
}

int evaluateExpression(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    std::string operation;
    int result = 0;
    bool isFirstToken = true;

    while (std::getline(iss, token, ' ')) {
        if (isFirstToken) {
            result = std::stoi(token);
            isFirstToken = false;
        } else if (token == "+" || token == "-") {
            operation = token;
        } else {
            int operand = std::stoi(token);
            if (operation == "+") {
                result += operand;
            } else if (operation == "-") {
                result -= operand;
            }
        }
    }

    return result;
}

int main() {
    std::ifstream inputFile("input2.txt");
    std::string line;

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string variable, equalSign, expression;
        if (std::getline(iss, variable, '=') && std::getline(iss, expression)) {
            expressions[variable] = expression;
        }
    }

    inputFile.close();

    std::ifstream inputFile2("input2.txt");
    while (std::getline(inputFile2, line)) {
        std::cout << line << std::endl;

        std::string variable, equalSign, expression;
        std::istringstream iss(line);
        if (std::getline(iss, variable, '=') && std::getline(iss, expression)) {
            std::string propagatedExpression = constantPropagation(expression);
            std::cout << variable << '=' << propagatedExpression << std::endl;

            int result;
            if (std::all_of(propagatedExpression.begin(), propagatedExpression.end(), [](char c) {
                return std::isdigit(c) || c == '+' || c == '-';
            })) {
                result = evaluateExpression(propagatedExpression);
                std::cout << "Result: " << result << std::endl;
            } else {
                std::cout << "Result: Cannot evaluate expression" << std::endl;
            }
        }

        std::cout << std::endl;
    }

    inputFile2.close();

    return 0;
}
