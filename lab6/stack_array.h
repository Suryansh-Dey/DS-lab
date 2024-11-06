#include <string>
using namespace std;
const int MAXSTACK = 10;
typedef string item_type; // change string to other data type

class stack
{
private:                 // 2 data members, an array and an index
  item_type s[MAXSTACK]; // stack whose elements are of item_type
  short top;             //
public:
  stack() // constructor
  {
    top = -1;
    for (int i = 0; i <= MAXSTACK - 1; i++)
      s[i] = ""; // constructor
  }

  void push(item_type item)
  {
    if (full())
      cerr << "Stack overflow -- it is full" << endl;
    else
    {
      top = top + 1;
      s[top] = item;
    }
  }

  item_type pop() {
    if(empty()){
      cerr << "Stack underflow\n";
    }
    top--;
    return s[top+1];
  }
  item_type peek() {
    return s[top];
  }
  bool empty() {
    return top==-1;
  }
  bool full() {
    return top==MAXSTACK;
  }
};
