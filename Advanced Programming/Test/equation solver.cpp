#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class EquationSolver {
private:
    string equation;
    vector<char> parenthesesStack;
    vector<pair<char, int>> variables;

public:
    EquationSolver(const string& eq) : equation(eq) {}

    bool checkParentheses() {
        for (char c : equation) {
            if (c == '(')
                parenthesesStack.push_back(c);
            else if (c == ')') {
                if (parenthesesStack.empty())
                    return false;
                parenthesesStack.pop_back();
            }
        }
        return parenthesesStack.empty();
    }

    bool checkNumbers() {
        vector<char> numbers;
        for (char c : equation) {
            if (isdigit(c) || c == '.') {
                numbers.push_back(c);
            }
            else if (!isspace(c)) {
                if (!numbers.empty()) {
                    string numberString(numbers.begin(), numbers.end());
                    double number = stod(numberString);
                    numbers.clear();

                    if (number < 0 || number > 100) {
                        return false;
                    }
                }
            }
        }

        if (!numbers.empty()) {
            string numberString(numbers.begin(), numbers.end());
            double number = stod(numberString);

            if (number < 0 || number > 100) {
                return false;
            }
        }

        return true;
    }

    void getVariableValues() {

        for (char c : equation) {
            if (isalpha(c)) {
                cout << "Enter the value for variable " << c << ": ";
                int value;
                cin >> value;
                variables.push_back(make_pair(c, value));
            }
        }
    }

    double calculateEquation() {
        double result = 0.0;
        string expression;

        equation.erase(remove_if(equation.begin(), equation.end(), ::isspace), equation.end());

        for (char c : equation) {
            if (isalpha(c)) {
                for (auto variable : variables) {
                    if (variable.first == c) {
                        expression += to_string(variable.second);
                        break;
                    }
                }
            }
            else {
                expression += c;
            }
        }

        result = evaluateExpression(expression);

        return result;
    }

    double evaluateExpression(const string& expression) {
        vector<double> operands;
        vector<char> operators;

        for (char c : expression) {
            if (isdigit(c)) {
                operands.push_back(static_cast<double>(c - '0'));
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/') {
                operators.push_back(c);
            }
        }

        while (!operators.empty()) {
            char op = operators.back();
            operators.pop_back();

            double operand2 = operands.back();
            operands.pop_back();
            double operand1 = operands.back();
            operands.pop_back();

            double result = 0.0;

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
                default:
                    break;
            }

            operands.push_back(result);
        }

        return operands.front();
    }
};

int main() {
    string equation;
    cout << "Enter the equation: ";
    getline(cin, equation);

    EquationSolver solver(equation);

    if (!solver.checkParentheses()) {
        cout << "Invalid parentheses placement." << endl;
        return 0;
    }

    if (!solver.checkNumbers()) {
        cout << "Invalid numbers." << endl;
        return 0;
    }

    solver.getVariableValues();
    double result = solver.calculateEquation();

    cout << "Result: " << result << endl;

    return 0;
}
