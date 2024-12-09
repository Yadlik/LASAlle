#include "node.h"
#include "airport.h"
#include "slist.h"
#include <iostream>
/* Class Library File */

Node * head;

// Constructor
slist::slist() {
  head = nullptr;
}

// Destructor
slist::~slist() {
  Node * currentNode = head;
  while (currentNode != nullptr) {
    Node * deletion = currentNode;
    currentNode = currentNode->next;
    delete deletion;
  }
}

// add(value)				//Adds a new value to the end of this list.
void slist::add(Airport value) {
  Node * addNode = new Node(value);
  if (head == nullptr) {
    head = addNode;
  }
  else {
    Node * currentNode = head;
    while(currentNode->next != nullptr) {
      currentNode = currentNode->next;
    }
    currentNode->next = addNode;
  }
}

// clear()					//Removes all elements from this list.
void slist::clear() {
  Node * currentNode = head;
  while (currentNode != nullptr) {
    Node * deletion = currentNode;
    currentNode = currentNode->next;
    delete deletion;
  }
}

// equals(list)				//Returns true if the two lists contain the same elements in the same order.
bool slist::equals(slist list) {
  Node * currentNode = head;
  Node * compareNode = list.head;
  while (currentNode->next != nullptr && compareNode->next != nullptr) {
    if (!(currentNode.data.equals(compareNode.data))) {
      return false;
    }
    else {
      currentNode = currentNode->next;
      compareNode = compareNode->next;
    }
  }
  if (currentNode->next != nullptr) {
    return false;
  }
  return true;
}

//get(index)				//Returns the element at the specified index in this list.
Airport slist::get(int index) {
  Node * currentNode = head;
  bool uhoh = false;

  for (int i = 0; i < index; i++) {
    if (currentNode->next != nullptr) {
      currentNode = currentNode->next;
    }
    else {
      uhoh = true;
      break;
    }
  }
  if (!uhoh) {
    return currentNode->data;
  }
  else {
    std::cout << "Error: index invalid to retrieve a value (called get for an slist)";
    return Airport();
  }
}

//getNode(index)
Node* slist::getNode(int index) {
  Node * currentNode = head;
  for (int i = 0; i < index; ++i) {
    if (currentNode != nullptr) 
      currentNode = currentNode->next;
    }
    return currentNode;
}

//insert(index, value)		//Inserts the element into this list before the specified index.
void slist::insert(int index, Airport value) {
  Node * addNode = new Node (value);
  if (index == 0) {
    addNode->next = head;
    head = addNode;
  }
  else {
    Node * prevNode = NULL;
    Node * currentNode = head;
    for (int i = 0; i < index; i++) {
      if (currentNode != nullptr) {
        prevNode = currentNode;
        currentNode = currentNode->next;
      }
    }
    prevNode->next = addNode;
    if (currentNode == nullptr) {
      addNode->next = nullptr;
    }
    else {
      addNode->next = currentNode;
    }
  }
}

//exchg(index1, index2)		//Switches the payload data of specified indexex.
void slist::exchg(int index1, int index2) {
  bool good = true;
  if (index1 < 0 || index1 >= size() || index2 < 0 || index2 >= size()) {good = false; return;}
  if (good) {
    Node * currentNode = getNode(index1);
    Node * exchangeNode = getNode(index2);
    std::swap(currentNode->data, exchangeNode->data);
  }
}

//swap(index1,index2)		//Swaps node located at index1 with node at index2
void slist::swap(int index1, int index2) {
  bool good = true;
  if (index1 < 0 || index1 >= size() || index2 < 0 || index2 >= size()) {good = false; return;}
  if (good) {
    Node * prevNode = NULL;
    Node * currentNode = head;
    for (int i = 0; i < index1; i++) {
      prevNode = currentNode;
      currentNode = currentNode->next;
    }
    Node * prevSwap = NULL;
    Node * currentSwap = head;
    for (int i = 0; i < index2; i++) {
      prevSwap = currentSwap;
      currentSwap = currentSwap->next;
    }

    if (currentNode == currentSwap->next || currentSwap == currentNode->next) {
      currentNode->next = currentSwap->next;
      currentSwap->next = currentNode;
      if (prevNode != nullptr) {
          prevNode->next = currentSwap;
      } 
      else {
        head = currentSwap;
      }
    } 
    else {
      Node* hold = currentNode->next;
      currentNode->next = currentSwap->next;
      currentSwap->next = hold;
      if (prevNode != nullptr) {
          prevNode->next = currentSwap;
      } else {
          head = currentSwap;
      }
      if (prevSwap != nullptr) { // check if not null
          prevSwap->next = currentNode;
      } else {
          head = currentNode;
      }
    }
  }
}

// isEmpty()				//Returns true if this list contains no elements.
bool slist::isEmpty(){
    return (head == nullptr);
}

// remove(index)			//Removes the element at the specified index from this list.
void slist::remove(int index){
  if (index == 0) {
      Node * hold = head;
      head = head->next;
      delete hold;
  }

  Node * currentNode = head;
  for (int i = 0; i < index; i++) {
    if (currentNode != nullptr) {
      if (i + 1 == index) {
        Node * hold = currentNode->next->next;
        delete currentNode->next;
        currentNode->next = hold;
      }
      else {
        currentNode = currentNode->next;
      }
    }
  }
}

// set(index, value)		//Replaces the element at the specified index in this list with a new value.
void slist::set(int index, Airport value){
  Node * currentNode = head;
  for (int i = 0; i < index; i++) {
    if (currentNode != nullptr) {
      currentNode = currentNode->next;
    }
    if (i + 1 == index) {
      currentNode->next->data = value;
    }
  }
}

// size()					//Returns the number of elements in this list.
int slist::size() {
  Node * currentNode = head;
  int count = 0;
  while (currentNode != nullptr) {
    currentNode = currentNode->next;
    count++;
  }
  return count;
}

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
slist slist::subList(int start, int length){
  bool good = true;
  if (index1 < 0 || index1 >= size() || index2 < 0 || index2 >= size()) {good = false; return slist();}
  if (good) {
    slist subset;
    Node * currentNode = head;
    for (int i = 0; i < start; i++) {
      currentNode = currentNode->next;
    }
    for (int i = 0; i < length; ++i) {
      subset.add(currentNode->data);
      currentNode = currentNode->next;
    }
    return subset;
  }
}

// toString()				//Converts the list to a printable string representation.
std::string slist::toString(){
  Node * currentNode = head;
  std::string output = "";
  while (currentNode != nullptr){
    output = output + " " + currentNode->data.toString();
    currentNode = currentNode->next;
  }
  output = output + " nullptr"; 
  return output;
}
