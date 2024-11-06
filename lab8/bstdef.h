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
