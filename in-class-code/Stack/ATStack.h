#ifndef ATSTACK_H
#define ATSTACK_H

#include <cstdlib>
using namespace std;

template <typename T> // each type you specify will create a copy of the code with that type T
class ATStack{
    public:
        ATStack();
        ATStack(int iSize);
        virtual ~ATStack();
        void push(T c);
        T pop();
        T peek();
        bool isEmpty();
        bool isFull(); // doesn't make sense if we resize
        int size();
    private:
        T* stackArray; //array
        int count; //current size
        int top; // index of top
        int max;
};

template<typename T>
ATStack<T>::ATStack() { //O(1) - constant
    count = 0;
    max = 0;
    stackArray = NULL;
    top = -1;
}

template<typename T>
ATStack<T>::ATStack(int iSize) { //O(1)
    count = 0;
    max = iSize; 
    top = -1;
    stackArray = new T[max];
}

template<typename T>
ATStack<T>::~ATStack() { //O(1)
    if (stackArray != NULL) {
        delete[] stackArray;
    }
}

template<typename T>
int ATStack<T>::size() { //O(1)
    return count;
}

template<typename T>
bool ATStack<T>::isEmpty() { //O(1)
    return (count == 0);
}

template<typename T>
bool ATStack<T>::isFull() { //O(1)
    return (count == max);
}

template<typename T>
T ATStack<T>::peek() { //O(1)
    return stackArray[top];
}

template<typename T>
T ATStack<T>::pop() { // what if the stack is empty? // O(1)
    --count;
    return stackArray[top--];
}

template<typename T>
void ATStack<T>::push(T c) { // what if full? // O(n) - now it's linear instead of constant, not as efficient
    if (isFull()) {
        T* temp = new T[2*max];
        for (int i = 0; i < max; ++i) {
            temp[i] = stackArray[i];
        }
        max *= 2;
        delete[] stackArray;
        stackArray = temp;
    }
    ++count;
    stackArray[++top] = c;
}


#endif