using namespace std;
#include <iostream>
#include "stack_array.h"
int main()
{
    item_type item;
    stack s; // creating an empty stack
    while (cin >> item)
    {
        s.push(item);
        cout << "Item inserted is " << s.peek() << endl;
        if (s.full())
            break;
    };
    if (s.full())
        cout << " stack is full \n"
             << endl;
    else
        cout << " stack is not full \n"
             << endl;
    while (!s.empty())
        cout << " Item at tos is : " << s.peek()
             << " Deleted element : " << s.pop() << endl;
    if (s.empty())
        cout << " stack is empty \n"
             << endl;
    else
        cout << " stack is not empty \n"
             << endl;
    return 0;
}