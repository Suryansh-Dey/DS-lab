#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class oprprop {
public:
    char op;
    int precedence;
    char assoc;
};

vector<oprprop> binops;

int find(char ch) {
    for (int i = 0; i < binops.size(); i++) {
        if (binops[i].op == ch) {
            return i;
        }
    }
    return -1;  // Not found
}

bool isOperator(char ch) {
    return find(ch) != -1;
}

int precedence(char ch) {
    int index = find(ch);
    if (index != -1)
        return binops[index].precedence;
    return -1;
}

char associativity(char ch) {
    int index = find(ch);
    if (index != -1)
        return binops[index].assoc;
    return 'L';  // Default to left associativity
}

string infixToPostfix(string infix) {
    stack<char> opStack;
    string postfix = "";
    
    for (int i = 0; i < infix.length(); i++) {
        char token = infix[i];

        if (isdigit(token)) {  // If the token is an operand, add it to the output
            postfix += token;
            postfix += " ";
        } 
        else if (isOperator(token)) {  // Token is an operator
            while (!opStack.empty() && isOperator(opStack.top())) {
                char topOp = opStack.top();
                if ((associativity(token) == 'L' && precedence(token) <= precedence(topOp)) ||
                    (associativity(token) == 'R' && precedence(token) < precedence(topOp))) {
                    postfix += topOp;
                    postfix += " ";
                    opStack.pop();
                } else {
                    break;
                }
            }
            opStack.push(token);
        } 
        else if (token == '(') {
            opStack.push(token);
        } 
        else if (token == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                postfix += " ";
                opStack.pop();
            }
            if (!opStack.empty() && opStack.top() == '(') {
                opStack.pop();
            }
        }
    }

    while (!opStack.empty()) {
        postfix += opStack.top();
        postfix += " ";
        opStack.pop();
    }

    return postfix;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <operator-attrs.txt>" << endl;
        return 1;
    }

    ifstream opfile(argv[1]);
    if (!opfile.is_open()) {
        cerr << "Error: Unable to open file " << argv[1] << endl;
        return 1;
    }

    oprprop temp;
    while (opfile >> temp.op >> temp.precedence >> temp.assoc) {
        binops.push_back(temp);
    }

    opfile.close();

    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);

    cout << "Infix expression is: " << infix << endl;
    cout << "Postfix expression is: " << postfix << endl;

    return 0;
}