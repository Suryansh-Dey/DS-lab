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
