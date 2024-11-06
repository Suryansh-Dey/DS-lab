/* file bintree.h */
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
typedef string item_type;

class tree_item {
public:
  item_type data;
  tree_item *left;
  tree_item *right;
};

typedef tree_item *tree_ptr;

class bintree {
public:
  tree_ptr root; // root of the binary tree

  tree_ptr makenode(item_type item) {
    tree_ptr p;
    if ((p = new tree_item) == NULL) {
      cerr << "run out of memory : quitting " << endl;
      exit(0);
    } else {
      p->data = item;
      p->left = NULL;
      p->right = NULL;
      return p;
    }
  }

public:
  bintree() { root = 0; }

  tree_ptr &head() { return root; }

  bool empty() { return root == 0; }

  void insertl(tree_ptr &t, item_type item)
  // insert an item as left subtree of t
  {
    tree_ptr p;
    p = makenode(item);
    if (p == NULL)
      cerr << "push not possible : no memory " << endl;
    else if (this->empty())
      root = p;
    else if (t != 0)
      t->left = p;
  }

  void insertl(tree_ptr &t, tree_ptr u)
  // insert a given subtree u as a left subtree of t
  {
    tree_ptr p;
    if (this->empty())
      root = u;
    else if (t != 0)
      t->left = u;
  }

  void insertr(tree_ptr &t, item_type item)
  // insert an item as right subtree of  tree t
  {
    tree_ptr p;
    p = makenode(item);
    if (p == NULL)
      cerr << "push not possible : no memory " << endl;
    else if (this->empty())
      root = p;
    else if (t != 0)
      t->right = p;
  }

  void insertr(tree_ptr &t, tree_ptr u)
  // insert a given subtree u as right subtree of t
  {
    tree_ptr p;
    if (this->empty())
      root = u;
    else if (t != 0)
      t->right = u;
  }

  void postorder(tree_ptr p) {
    if (p == 0)
      return;
    postorder(p->left);
    postorder(p->right);
    cout << p->data << "  ";
  }
};
