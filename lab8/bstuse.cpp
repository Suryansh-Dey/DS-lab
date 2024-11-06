#include <iostream>
#include <string>
#include <fstream>
#include "bstdef.h"
using namespace std;

int main()
{
  bst mybst;
  int key;
  while (cin >> key)
  { mybst.insert(key); 
    cout << " Inorder Traversal of bst after Inserting " << key << endl;
    mybst.inorder(mybst.root); cout << endl;
  };
  cout << " Max element in bst " << mybst.max() << endl;
  cout << " Min element in bst " << mybst.min() << endl;
  cout << " Height of bst : " << mybst.height(mybst.root) << endl;
  cout << "Preorder Traversal of bst " << endl;
  mybst.preorder(mybst.root); cout << endl;
  cout << "Postorder Traversal of bst " << endl;
  mybst.postorder(mybst.root); cout << endl;
  cout << " find 8 in bst " << mybst.find(mybst.root, 8) << endl;
  cout << " find 40 in bst " << mybst.find(mybst.root, 40) << endl;
  treenode * p = mybst.root;
  cout << " Breadth First Search Order on bst \n";
  mybst.bfsearch(p); cout << endl;
  return 0;
}

