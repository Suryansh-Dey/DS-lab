## DS LAB 8, AIML
### bstdef1.h
```cpp
#include "queue_array_def.h"
#include "treenode_def.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
class bst {
public:
  treenode *root;
  bst() { root = 0; }
  treenode *makenode(int val) {
    treenode *p;
    if ((p = new treenode) == NULL) {
      cerr << "run out of memory : quitting " << endl;
      exit(0);
    } else {
      p->key = val;
      p->left = NULL;
      p->right = NULL;
      p->par = NULL;
      return p;
    }
  }

  void insert(int key) {
    treenode *x = root, *y = 0;
    treenode *p;
    p = makenode(key);
    while (x != 0) {
      y = x;
      if (p->key < x->key)
        x = x->left;
      else
        x = x->right;
    }
    if (y == 0)
      root = p;
    else {
      if (p->key < y->key)
        y->left = p;
      else
        y->right = p;
      p->par = y;
    }
  }
};
```
### bstdef2.h
```cpp
#include "queue_array_def.h"
#include "treenode_def.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
class bst {
public:
  treenode *root;
  bst() { root = 0; }
  treenode *makenode(int val) {
    treenode *p;
    if ((p = new treenode) == NULL) {
      cerr << "run out of memory : quitting " << endl;
      exit(0);
    } else {
      p->key = val;
      p->left = NULL;
      p->right = NULL;
      p->par = NULL;
      return p;
    }
  }

  void insert(int key) {
    treenode *x = root, *y = 0;
    treenode *p;
    p = makenode(key);
    while (x != 0) {
      y = x;
      if (p->key < x->key)
        x = x->left;
      else
        x = x->right;
    }
    if (y == 0)
      root = p;
    else {
      if (p->key < y->key)
        y->left = p;
      else
        y->right = p;
      p->par = y;
    }
  }
  void inorder(treenode *node) {
    if (!node)
      return;
    printf("%d ", node->key);
    inorder(node->left);
    inorder(node->right);
  }
};
```
### bstdef.h
```cpp
#include "queue_array_def.h"
#include "treenode_def.h"
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
class bst {
public:
  treenode *root;
  bst() { root = 0; }
  treenode *makenode(int val) {
    treenode *p;
    if ((p = new treenode) == NULL) {
      cerr << "run out of memory : quitting " << endl;
      exit(0);
    } else {
      p->key = val;
      p->left = NULL;
      p->right = NULL;
      p->par = NULL;
      return p;
    }
  }

  void insert(int key) {
    treenode *x = root, *y = 0;
    treenode *p;
    p = makenode(key);
    while (x != 0) {
      y = x;
      if (p->key < x->key)
        x = x->left;
      else
        x = x->right;
    }
    if (y == 0)
      root = p;
    else {
      if (p->key < y->key)
        y->left = p;
      else
        y->right = p;
      p->par = y;
    }
  }
  void bfsearch(treenode *node) {
    queue q;
    q.insert(node);

    while (!q.isempty()) {
      treenode *element = q.del();
      printf("%d ", element->key);
      if (element->left)
        q.insert(element->left);
      if (element->right)
        q.insert(element->right);
    }
  }
  void preorder(treenode *node) {
    if (!node)
      return;
    printf("%d ", node->key);
    preorder(node->left);
    preorder(node->right);
  }
  void inorder(treenode *node) {
    if (!node)
      return;
    inorder(node->left);
    printf("%d ", node->key);
    inorder(node->right);
  }
  void postorder(treenode *node) {
    if (!node)
      return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->key);
  }
  int max() {
    int maxKey = INT32_MIN;
    queue q;
    q.insert(root);

    while (!q.isempty()) {
      treenode *element = q.del();
      if (element->left)
        q.insert(element->left);
      if (element->right)
        q.insert(element->right);
      maxKey = element->key > maxKey ? element->key : maxKey;
    }
    return maxKey;
  }
  int min() {
    int minKey = INT32_MAX;
    queue q;
    q.insert(root);

    while (!q.isempty()) {
      treenode *element = q.del();
      if (element->left)
        q.insert(element->left);
      if (element->right)
        q.insert(element->right);
      minKey = element->key < minKey ? element->key : minKey;
    }
    return minKey;
  }
  int height(treenode *root) { return nodeHeight(root, -1); }
  bool find(treenode *node, int target) {
    if (!node)
      return false;
    if (node->key == target)
      return true;
    return find(node->left, target) || find(node->right, target);
  }

private:
  int nodeHeight(treenode *node, int height) {
    if (!node)
      return -1;
    return std::max(nodeHeight(node->left, height),
                    nodeHeight(node->right, height)) +
           1;
  }
};
```
### postfix_eval.C
```cpp
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
```