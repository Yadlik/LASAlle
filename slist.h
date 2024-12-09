// Header file for single linked list class library
#include <string>
#include "airport.h"
#include "node.h"

#ifndef SLIST_H
#define SLIST_H

class slist {
  public:
    void add(Airport value);                 // add(value)				      //Adds a new value to the end of this list.
    void clear();                            // clear()					        //Removes all elements from this list.
    bool equals(slist list);                 // equals(list)				    //Returns true if the two lists contain the same elements in the same order.
    Airport get(int index);                  //get(index)				        //Returns the element at the specified index in this list.
    Node * getNode(int index);
    void insert(int index, Airport value);   //insert(index, value)		  //Inserts the element into this list before the specified index.
    void exchg(int index1, int index2);      //exchg(index1, index2)		//Switches the payload data of specified indexex.
    void swap(int index1, int index2);       //swap(index1,index2)		  //Swaps node located at index1 with node at index2
    bool isEmpty();                          // isEmpty()				        //Returns true if this list contains no elements.
    // this one is weird \/
    //void mapAll();// mapAll(fn)				//Calls the specified function on each element of the linkedlist in ascending index order.
    void remove(int index);                  // remove(index)			      //Removes the element at the specified index from this list.
    void set(int index, Airport value);      // set(index, value)		    //Replaces the element at the specified index in this list with a new value.
    int size();                              // size()					        //Returns the number of elements in this list.
    slist subList(int start, int length);    // subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
    std::string toString();                  // toString()				      //Converts the list to a printable string representation.
};

#endif
