/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA6 - Spanning the Gamut (Kruskal’s Algorithm)
*/

#ifndef PQUEUE_H
#define PQUEUE_H

#include "DblList.h"
#include <cstdlib>
#include <iostream>
using namespace std;

// defines PQueue class, built in CPSC 350 session
// class includes public constructor and destructor, add, remove, peek, size, and isEmpty methods
// class includes private m_list and isMinQ variables
template <typename T>
class PQueue{
public:
  PQueue(bool isMin);
  virtual ~PQueue();
  void add(T data);
  T remove();
  T peek();
  int size();
  bool isEmpty();

private:
  DblList<T>* m_list;
  bool isMinQ; //which way sorted?

};

// constructor
template <typename T>
PQueue<T>::PQueue(bool isMin){
  isMinQ = isMin;
  m_list = new DblList<T>();
}

// destructor
template <typename T>
PQueue<T>::~PQueue(){
  delete m_list;
}

// add method adds data to the priority queue
template <typename T>
void PQueue<T>::add(T data){
  if(isEmpty()){
    m_list->addFront(data);
  } else{
    ListNode<T>* newNode = new ListNode<T>(data);
    int currIndex = 0;
    ListNode<T>* currNode = m_list->m_front;
    while(currNode != NULL && currNode->m_data < data){
      currNode = currNode->m_next;
      ++currIndex;
    }
    m_list->add(currIndex, data); //easy, but 2x slower
    //smart thing is patch in
  }
}

// remove method removes from the top or bottom
template <typename T>
T PQueue<T>::remove(){
  if(isMinQ){
    return m_list->removeFront();
  } else{
    return m_list->removeBack();
  }
}

// peek method returns the first or last value
template <typename T>
T PQueue<T>::peek(){
  if(isMinQ){
    return m_list->get(0);
  }else{
    return m_list->get(size()-1);
  }
}

// size method returns the size of the queue
template <typename T>
int PQueue<T>::size(){
  return m_list->getSize();
}

// isEmpty method returns a bool representing if the queue is empty or not
template <typename T>
bool PQueue<T>::isEmpty(){
  return m_list->isEmpty();
}

#endif
