#include "bstdef2.h"
#include <iostream>
using namespace std;

int main() {
  bst mybst;
  int key;
  while (cin >> key) {
    mybst.insert(key);
    cout << " Inorder Traversal of bst after Inserting " << key << endl;
    mybst.inorder(mybst.root);
    cout << endl;
  };
  return 0;
}
