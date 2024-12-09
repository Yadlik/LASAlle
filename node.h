#ifndef NODE_H
#define NODE_H

#include "airport.h"

class Node{
  public:
    Airport data;
    Node* next;

    Node(Airport value) {
      data = value;
      next = nullptr;
    }
};

#endif
