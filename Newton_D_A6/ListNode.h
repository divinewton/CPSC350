/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA6 - Spanning the Gamut (Kruskal’s Algorithm)
*/

#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <cstdlib>
#include <iostream>
using namespace std;

// defines ListNode class, built in CPSC 350 session
// class includes public constructor and destructor, and is a friend class with DblList
// class includes private T m_data, ListNode<T>* m_next, and ListNode<T>* m_prev
template <typename T>
class ListNode{
public:
  ListNode(T data);
  virtual ~ListNode();

  template <typename S>
  friend class DblList;

  template <typename R>
  friend class PQueue;
private:
  T m_data;
  ListNode<T>* m_next;
  ListNode<T>* m_prev;

};

// constructor
template <typename T>
ListNode<T>::ListNode(T data){
  m_next = NULL;
  m_prev = NULL;
  m_data = data;
}

// destructor
template <typename T>
ListNode<T>::~ListNode(){
  m_next = NULL;
  m_prev = NULL;
}


#endif
