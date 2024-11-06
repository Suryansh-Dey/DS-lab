#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;


bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}


int performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': 
            if (operand2 == 0) {
                cout << "Error: Division by zero!" << endl;
                exit(1); 
            }
            return operand1 / operand2;
        case '%': return operand1 % operand2;
        default: 
            cout << "Unexpected operator encountered!" << endl;
            exit(1);
    }
}


int evaluatePostfixExpression(const string &postfix) {
    stack<int> operandStack;
    stringstream ss(postfix);
    string token;
    
    while (ss >> token) {
        
        if (isdigit(token[0])) {
            operandStack.push(stoi(token));
        }
        
        else if (isOperator(token[0])) {
            if (operandStack.size() < 2) {
                cout << "Expression is not well-formed!" << endl;
                return -1;
            }

            
            int operand2 = operandStack.top(); operandStack.pop();
            int operand1 = operandStack.top(); operandStack.pop();

            
            int result = performOperation(token[0], operand1, operand2);
            operandStack.push(result);
        } else {
            cout << "Invalid character in expression: " << token << endl;
            return -1;
        }
    }

    
    if (operandStack.size() == 1) {
        return operandStack.top(); 
    } else {
        cout << "Expression is not well-formed!" << endl;
        return -1;
    }
}

int main() {
    string postfix1;
    std::getline(std::cin, postfix1);
    cout << "Result of expression '" << postfix1 << "' is " << evaluatePostfixExpression(postfix1) << endl;
    return 0;
}