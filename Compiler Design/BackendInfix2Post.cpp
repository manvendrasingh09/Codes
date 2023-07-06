#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
int getPrecedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}
vector<string> infixToPostfix(string expression) {
    vector<string> postfix;
    stack<char> operators;
    for (char c : expression) {
        if (isalnum(c)) {
            postfix.push_back(string(1, c));
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix.push_back(string(1, operators.top()));
                operators.pop();
            }
            operators.pop();
        } else {
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(c)) {
                postfix.push_back(string(1, operators.top()));
                operators.pop();
            }
            operators.push(c);
        }
    }
    while (!operators.empty()) {
        postfix.push_back(string(1, operators.top()));
        operators.pop();
    }
    return postfix;
}
vector<vector<string>> generateQuadruples(vector<string> postfix) {
    vector<vector<string>> quadruples;
    stack<string> operands;
    int tempCount = 0;
    for (string token : postfix) {
        if (isalnum(token[0])) {
            operands.push(token);
        } else {
            string op2 = operands.top();
            operands.pop();
            string op1 = operands.top();
            operands.pop();
            string temp = "t" + to_string(tempCount++);
            quadruples.push_back({token, op1, op2, temp});
            operands.push(temp);
        }
    }
    return quadruples;
}
vector<string> generateAssembly(vector<vector<string>> quadruples) {
    vector<string> assembly;
    int labelCount = 0;

    for (vector<string> quad : quadruples) {
        string opcode = quad[0];
        string operand1 = quad[1];
        string operand2 = quad[2];
        string result = quad[3];
        if (opcode == "+") {
            assembly.push_back("mov A, " + operand1);
            assembly.push_back("add A, " + operand2);
            assembly.push_back("mov " + result + ", A");
        } else if (opcode == "-") {
            assembly.push_back("mov A, " + operand1);
            assembly.push_back("subb A, " + operand2);
            assembly.push_back("mov " + result + ", A");
        } else if (opcode == "*") {
            assembly.push_back("mov A, " + operand1);
            assembly.push_back("mul AB, " + operand2);
            assembly.push_back("mov " + result + ", A");
        } else if (opcode == "/") {
            assembly.push_back("mov A, " + operand1);
            assembly.push_back("div AB, " + operand2);
            assembly.push_back("mov " + result + ", A");
        }
    }
    return assembly;
}
int main() {
    string infixExpression;
    cout << "Enter the infix expression: ";
    getline(cin, infixExpression);
    vector<string> postfix = infixToPostfix(infixExpression);
    vector<vector<string>> quadruples = generateQuadruples(postfix);
    cout << "Postfix Expression: ";
    for (string token : postfix) {
        cout << token << " ";
    }
    cout << endl;
    cout << "\nQuadruples:" << endl;
    for (vector<string> quad : quadruples) {
        for (string token : quad) {
            cout << token << " ";
        }
        cout << endl;
    }
    vector<string> assembly = generateAssembly(quadruples);
    cout << "\nAssembly Instructions:" << endl;
    for (string instruction : assembly) {
        cout << instruction << endl;
    }
    return 0;
}