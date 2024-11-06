/* file queue_array_def.h  */
#pragma once
#include "treenode_def.h"
#include <iostream>
#include <string>

using namespace std;
#define MAXQUEUE 100

class queue {
  typedef treenode *item_type;

private:
  int front, rear;
  item_type info[MAXQUEUE];
  void error(string s) { cout << s << endl; };

public:
  queue() {
    front = -1;
    rear = -1;
  }

  void insert(item_type item) {
    if (rear == MAXQUEUE - 1)
      error("Queue overflow -- it is full");
    else {
      rear++;
      info[rear] = item;
    };
  }

  item_type del() {
    item_type elm;
    if (front == rear)
      error("queue underflow -it is empty");
    else {
      front++;
      elm = info[front];
    };
    return elm;
  }

  bool isempty() { return front == rear; }

  bool isfull() { return rear == MAXQUEUE - 1; }

  int length() {
    int len = 0;
    if (isempty())
      return len;
    else {
      int f = front + 1;
      while (f <= rear) {
        f++;
        len++;
      };
      return len;
    }
  }
};
