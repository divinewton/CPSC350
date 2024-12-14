/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA3 - Do You See What I See?
*/

#ifndef MONOSTACK_H
#define MONOSTACK_H
#include <cstdlib>
using namespace std;

// defines MonoStack class
// class includes public constructor and destructor, push, pop, peek, isEmpty, isFull, size methods
// class includes private stackArray, count, top, max, o
template <typename T>
class MonoStack{
public:
  MonoStack();
  MonoStack(int iSize, char o);
  virtual ~MonoStack();
  void push(T c);
  T pop();
  T peek();
  bool isEmpty();
  bool isFull();
  int size();
private:
  T* stackArr; //array
  int count; //current size
  int top; //index of top
  int max;
  char o; // increasing or decreasing indicator

};

// MonoStack constructor 
template<typename T>
MonoStack<T>::MonoStack(){
  o = 'd';
  count = 0;
  max = 0;
  stackArr = NULL;
  top = -1;
}

// MonoStack overloaded constructor 
// takes in size and type
template<typename T>
MonoStack<T>::MonoStack(int iSize, char oIn){
  o = oIn;
  count = 0;
  max = iSize;
  top = -1;
  stackArr = new T[max];
}

// MonoStack destructor
template<typename T>
MonoStack<T>::~MonoStack(){
  if(stackArr != NULL){
    delete[] stackArr;
  }
}

// push method takes in data and adds it to the stack
// performs different based on increasing or decreasing selection
template<typename T>
void MonoStack<T>::push(T c){
    if(isFull()){ // if it is full, resizes
        T* temp = new T[2*max];
        for(int i = 0; i < max; ++i){
        temp[i] = stackArr[i];
      }
    max *= 2;
    delete[] stackArr;
    stackArr = temp;
    ++count;
    stackArr[++top] = c;
    }
    if (o == 'i') { // Increasing
        if (peek() > c) {
          ++count;
          stackArr[++top] = c;
        }
    } else if (o == 'd') { // Decreasing
        if (peek() < c) {
          ++count;
          stackArr[++top] = c;
        }
    }
}

// pop method removes and returns top value
template<typename T>
T MonoStack<T>::pop(){
    if (!isEmpty()) {
        --count;
        return stackArr[top--];
    } else {
        return 0;
    }
}

// peek method returns top value
template<typename T>
T MonoStack<T>::peek(){
  return stackArr[top];
}

// isEmpty returns a bool true or false is empty
template<typename T>
bool MonoStack<T>::isEmpty(){
  return (count == 0);
}

// isFull returns a bool true or false is full
template<typename T>
bool MonoStack<T>::isFull(){
  return (count == max);
}

// size method returns the current count of the stack
template<typename T>
int MonoStack<T>::size(){
  return count;
}

#endif