using namespace std;
#include <iostream>
#include <string>
#include "stack_array.h"

typedef string item_type;

string match(string s)
{
    string ret = " ";
    if (s == "(")
        ret = ")";
    if (s == ")")
        ret = "(";
    if (s == "{")
        ret = "}";
    if (s == "}")
        ret = "{";
    if (s == "[")
        ret = "]";
    if (s == "]")
        ret = "[";
    return ret;
};

int main()
{
    item_type item;
    stack s;
    std::string expression;
    std::cout << "Enter the expression: ";

    bool balanced = true;
    int unbalancedCount = 0;

    for (char &c : expression)
    {
        if (c == '(' || c == '{' || c == '[')
        {
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (s.empty())
            {
                std::cout << "Unmatched closing parenthesis: " << c << "\n";
                balanced = false;
                unbalancedCount++;
            }
            else
            {
                std::string top = s.pop();
                if (match(top) != std::string(1, c))
                {
                    std::cout << "parenthesis " << c << " does not match with stack-top " << top << "\n";
                    balanced = false;
                    unbalancedCount++;
                }
                else
                {
                    std::cout << "parenthesis " << c << " matches with stack-top " << top << "\n";
                }
            }
        }
    }

    if (!s.empty())
    {
        balanced = false;
        while (!s.empty())
        {
            std::string top = s.pop();
            std::cout << "Unbalanced opening parenthesis: " << top << "\n";
            unbalancedCount++;
        }
    }

    if (balanced)
    {
        std::cout << "Input processing is over; Expression has balanced parentheses\n";
    }
    else
    {
        std::cout << "Number of unbalanced parentheses in expression: " << unbalancedCount << "\n";
    }
    return 0;
}
