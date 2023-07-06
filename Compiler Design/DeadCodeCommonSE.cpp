#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

// Function to eliminate dead code
string eliminateDeadCode(const string& input) {
    istringstream iss(input);
    string line;
    string result;

    unordered_map<string, bool> variables;

    while (getline(iss, line)) {
        if (line.find('=') != string::npos) {
            string variable = line.substr(0, line.find('='));
            variables[variable] = true;
        }
    }

    iss.clear();
    iss.seekg(0, ios::beg);

    while (getline(iss, line)) {
        string variable = line.substr(0, line.find('='));
        if (variables[variable]) {
            result += line + '\n';
        }
    }

    return result;
}

// Function to eliminate common subexpressions
string eliminateCommonExpressions(const string& input) {
    istringstream iss(input);
    string line;
    string result;

    unordered_map<string, string> expressions;
    unordered_map<string, string> expressionsMap;

    while (getline(iss, line)) {
        string variable = line.substr(0, line.find('='));
        string expression = line.substr(line.find('=') + 1);

        if (expressions.find(expression) == expressions.end()) {
            expressions[expression] = variable;
        }

        if (expressionsMap.find(expression) == expressionsMap.end()) {
            expressionsMap[expression] = variable;
            result += line + '\n';
        } else {
            result += expressions[expression] + '=' + expression + '\n';
        }
    }

    return result;
}

int main() {
    ifstream inputFile("input3.txt");
    stringstream buffer;
    buffer << inputFile.rdbuf();
    string input = buffer.str();

    // Perform dead code elimination
    string afterDeadCodeElimination = eliminateDeadCode(input);

    cout << "After dead code elimination:\n";
    cout << afterDeadCodeElimination << '\n';

    // Perform common subexpression elimination
    string afterCommonExpressionElimination = eliminateCommonExpressions(afterDeadCodeElimination);

    cout << "Eliminate Common Expression:\n";
    cout << afterCommonExpressionElimination << '\n';

    cout << "Optimized code:\n";
    cout << eliminateDeadCode(afterCommonExpressionElimination) << '\n';

    return 0;
}
