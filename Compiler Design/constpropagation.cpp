#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <stack>
#include <stdexcept>

using namespace std;

map<string, string> variables;

int getPrecedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return -1;
}

int evaluateExpression(const string& expression) {
    stack<char> operators;
    stack<int> operands;

    for (size_t i = 0; i < expression.length(); ++i) {
        if (expression[i] == ' ')
            continue;

        if (isdigit(expression[i])) {
            int operand = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            operands.push(operand);
            i--;
        } else if (isalpha(expression[i])) {
            string variable;
            while (i < expression.length() && isalnum(expression[i])) {
                variable += expression[i];
                i++;
            }
            if (variables.find(variable) == variables.end()) {
                throw out_of_range("Variable not found: " + variable);
            }
            int value = evaluateExpression(variables[variable]);
            operands.push(value);
            i--;
        } else if (expression[i] == '(') {
            operators.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                int operand2 = operands.top();
                operands.pop();
                int operand1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                int result = 0;
                switch (op) {
                    case '+':
                        result = operand1 + operand2;
                        break;
                    case '-':
                        result = operand1 - operand2;
                        break;
                    case '*':
                        result = operand1 * operand2;
                        break;
                    case '/':
                        result = operand1 / operand2;
                        break;
                }
                operands.push(result);
            }
            if (!operators.empty())
                operators.pop(); // Remove '('
        } else {
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(expression[i])) {
                int operand2 = operands.top();
                operands.pop();
                int operand1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                int result = 0;
                switch (op) {
                    case '+':
                        result = operand1 + operand2;
                        break;
                    case '-':
                        result = operand1 - operand2;
                        break;
                    case '*':
                        result = operand1 * operand2;
                        break;
                    case '/':
                        result = operand1 / operand2;
                        break;
                }
                operands.push(result);
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty()) {
        int operand2 = operands.top();
        operands.pop();
        int operand1 = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        int result = 0;
        switch (op) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
        }
        operands.push(result);
    }

    return operands.top();
}

int main() {
    ifstream inputFile("input2.txt");
    string line;
    while (getline(inputFile, line)) {
        size_t pos = line.find("=");
        if (pos != string::npos) {
            string variable = line.substr(0, pos);
            string expression = line.substr(pos + 1);
            variables[variable] = expression;
        }
    }

    //cout << "After constant propagation" << endl;
    for (const auto& variable : variables) {
        cout << variable.first << "=" << variable.second << endl;
        try {
            int value = evaluateExpression(variable.second);
            cout << "Result: " << variable.first << "=" << value << endl;
        } catch (const out_of_range& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
