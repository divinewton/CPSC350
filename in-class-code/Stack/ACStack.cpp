#include "ACStack.h"
#include <cstdlib>
using namespace std;

ACStack::ACStack() { //O(1) - constant
    count = 0;
    max = 0;
    stackArray = NULL;
    top = -1;
}

ACStack::ACStack(int iSize) { //O(1)
    count = 0;
    max = iSize; 
    top = -1;
    stackArray = new char[max];
}

ACStack::~ACStack() { //O(1)
    if (stackArray != NULL) {
        delete[] stackArray;
    }
}

int ACStack::size() { //O(1)
    return count;
}

bool ACStack::isEmpty() { //O(1)
    return (count == 0);
}

bool ACStack::isFull() { //O(1)
    return (count == max);
}

char ACStack::peek() { //O(1)
    return stackArray[top];
}

char ACStack::pop() { // what if the stack is empty? // O(1)
    --count;
    return stackArray[top--];
}

void ACStack::push(char c) { // what if full? // O(n) - now it's linear instead of constant, not as efficient
    if (isFull()) {
        char* temp = new char[2*max];
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