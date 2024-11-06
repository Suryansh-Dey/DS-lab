#pragma once
class treenode {
public:
  int key;
  treenode *par;
  treenode *left;
  treenode *right;
  treenode() {
    key = -1;
    left = right = par = 0;
  }
};
