// program to evaluate a postfix expression
// uses the stack defined in standard template library

#include "binarytree.h"
#include "bstdef.h"
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <stack> // defined in stl
#include <string>
using namespace std;

bool isnum(string s) {
  for (int j = 0; j < s.size(); j++)
    if (!isdigit(s[j]))
      return false;
  return true;
}
bool isOperator(string s) {
  return s == "+" || s == "-" || s == "/" || s == "*";
}

int s2i(string s) {
  int num = 0;
  int digit = 0;
  for (int j = 0; j < s.size(); j++) {
    switch (s[j]) {
    case ('0'):
      digit = 0;
      break;
    case ('1'):
      digit = 1;
      break;
    case ('2'):
      digit = 2;
      break;
    case ('3'):
      digit = 3;
      break;
    case ('4'):
      digit = 4;
      break;
    case ('5'):
      digit = 5;
      break;
    case ('6'):
      digit = 6;
      break;
    case ('7'):
      digit = 7;
      break;
    case ('8'):
      digit = 8;
      break;
    case ('9'):
      digit = 9;
      break;
    }; // end of switch
    num = num * 10 + digit;
  }; // end of for
  return num;
}

int main() {
  stack<bintree> subtrees;
  
  string s;
  int num;
  stack<int> st;
  int p1, p2;
  int res = 0;
  string exp = " ";
  while (cin >> s) {
    exp = exp + " " + s;
    if (isnum(s)) {
      num = s2i(s);
      st.push(num);
    } else {
      p1 = st.top();
      st.pop();
      p2 = st.top();
      st.pop();
      if (s == "*")
        res = p2 * p1;
      else if (s == "/")
        res = p2 / p1;
      else if (s == "+")
        res = p2 + p1;
      else if (s == "-")
        res = p2 - p1;
      else {
        cout << " unknown operator " << endl;
        return -1;
      }
      st.push(res);
    };

    bintree tempTree;
    tempTree.root = tempTree.makenode(s);
    if(isOperator(s)){
      tempTree.insertr(tempTree.root, subtrees.top().root);
      subtrees.pop();
      tempTree.insertl(tempTree.root, subtrees.top().root);
      subtrees.pop();
    }
    subtrees.push(tempTree);

  }; // end of while
  if (!st.empty())
    cout << "result of expression " << exp << " is : " << res << endl;
  else {
    cout << "expression is not well formed \n";
    return 2;
  };

  bintree tree = subtrees.top();
  cout << "postorder traversal is ";
  tree.postorder(tree.root);
  return 0;
}
