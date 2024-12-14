/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA4 - Genetic Palindromes
*/

#ifndef DBL_LIST_H
#define DBL_LIST_H
#include "ListNode.h"
using namespace std;

// defines DblList class, built in CPSC 350 session
// class includes public constructor and destructor, isEmpty, getSize, addFront, addBack, add, removeFront, removeBack, remove, get, contains methods
// class includes private ListNode<T>* m_front, and ListNode<T>* m_back, and int m_size values
template <typename T>
class DblList{
public:
  DblList();
  virtual ~DblList();
  bool isEmpty();
  int getSize();

  //add
  void addFront(T data);
  void addBack(T data);
  void add(int pos, T data);

  //remove
  T removeBack();
  T removeFront();
  T remove(int pos);

  //get random
  T get(int pos);
  bool contains(T data);

private:
  ListNode<T>* m_front;
  ListNode<T>* m_back;
  int m_size;

};

// constructor
template <typename T>
DblList<T>::DblList(){
  m_size = 0;
  m_front = NULL;
  m_back = NULL;
}

// destructor
template <typename T>
DblList<T>::~DblList(){
  ListNode<T>* current = m_front; // loop to delete each node
  while (current != NULL) {
    ListNode<T>* next = current->m_next;
    delete current;
    current = next;
  }
  m_size = 0;
  m_front = NULL;
  m_back = NULL;
}

// isEmpty method returns if the size is 0 or not
template <typename T>
bool DblList<T>::isEmpty(){
  return (m_size==0);
}

// getSize method returns the size
template <typename T>
int DblList<T>::getSize(){
  return m_size;
}

//addFront method checks if it is empty and adds to the front
template <typename T>
void DblList<T>::addFront(T data){
  ListNode<T>* newNode = new ListNode<T>(data);
  if(!isEmpty()){
    m_front->m_prev = newNode;
    newNode->m_next = m_front;

  } else { // if is empty
    m_back = newNode;
  }
  m_front = newNode;
  ++m_size;

}

//addBack method checks if it is empty and adds to the back
template <typename T>
void DblList<T>::addBack(T data){
  ListNode<T>* newNode = new ListNode<T>(data);
  if(!isEmpty()){
    m_back->m_next = newNode;
    newNode->m_prev = m_back;

  } else{ // if is empty
    m_front = newNode;
  }
  m_back = newNode;
  ++m_size;
}

// add method calls addFront or addBack, or adds to a certain porition in the list
template <typename T>
void DblList<T>::add(int pos, T data){
  if(isEmpty() || pos <= 0){
    addFront(data);
  } else if(pos >= m_size){
    addBack(data);
  } else{ // adding in middle
    ListNode<T>* newNode = new ListNode<T>(data);
    int cPos = 0;
    ListNode<T>* current = m_front;
    while(cPos != pos){
      current = current->m_next;
      ++cPos;
    }
    // sets all pointers to the correct spots
    current->m_prev->m_next = newNode;
    newNode->m_prev = current->m_prev;
    current->m_prev = newNode;
    newNode->m_next = current;
    ++m_size;

  }
}

// removeBack method checks if empty and removes from the back
template <typename T>
T DblList<T>::removeBack(){
  if (!isEmpty()) { // error check to ensure it is not empty
    T data;
    data = m_back->m_data;
    if(m_size == 1){
      delete m_back;
      m_front = NULL;
      m_back = NULL;
    } else{ // if multiple things in list
      ListNode<T>* currBack = m_back;
      m_back = m_back->m_prev;
      m_back->m_next = NULL;
      currBack->m_prev = NULL;
      delete currBack;
    }
  --m_size;
  return data;
  }
  return 0;
}

// removeFront method checks if empty and removes from the front
template <typename T>
T DblList<T>::removeFront(){
  if (!isEmpty()) { // error check to ensure it is not empty
    T data;
    data = m_front->m_data;
    if(m_size == 1){
      delete m_front;
      m_front = NULL;
      m_back = NULL;
    } else{ // if multiple things in list
      ListNode<T>* currFront = m_front;
      m_front = m_front->m_next;
      m_front->m_prev = NULL;
      currFront->m_next = NULL;
      delete currFront;
    }
    --m_size;
    return data;
  }
  return 0;
}

// remove method calls removeFront, removeBack, or removes from position
template <typename T>
T DblList<T>::remove(int pos){
  T data;
  if(pos <= 0){
    data = removeFront();
  } else if (pos >= m_size-1){
    data = removeBack();
  } else{ // if removing from middle
    int cPos = 0;
    ListNode<T>* current = m_front;
    while(cPos != pos){
      current = current->m_next;
      ++cPos;
    }
    // sets all pointers to the correct locations
    data = current->m_data;
    current->m_prev->m_next = current->m_next;
    current->m_next->m_prev = current->m_prev;
    current->m_next = NULL;
    current->m_prev = NULL;
    delete current;
    --m_size;
  }
  return data;
}

// get method finds a value at a position
template <typename T>
T DblList<T>::get(int pos){
  if (pos > 0 || pos < m_size) { // error handling to ensure valid location
    int cPos = 0;
    ListNode<T>* current = m_front;
    while(cPos != pos){
      current = current->m_next;
      ++cPos;
    }
    return current->m_data;
  }
  return 0;
}

// contains method returns if a value is in the list
template <typename T>
bool DblList<T>::contains(T data){
  ListNode<T>* current = m_front;
  bool found = false;
  while(current != NULL){
    if(current->m_data == data){
      found = true;
      break;
    }
    current = current->m_next;
  }
  return found;
}

#endif