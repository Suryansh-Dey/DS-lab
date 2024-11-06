#include "bstdef1.h"
#include <iostream>
using namespace std;

int main() {
  bst mybst;
  int key;
  while (cin >> key) {
    mybst.insert(key);
    cout << " Inserting " << key << " in bst \n";
  };
  return 0;
}
