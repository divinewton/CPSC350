#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class MinHeap{
    public:
    MinHeap(int cap);
    virtual ~MinHeap();
    void insert(T k);
    T deleteMin();
    T getMin();
    bool isEmpty();
    int getSize();
    private:
    T* m_heap;
    int m_size;
    int m_capacity;
    inline int getLeftIdx(int p);
    inline int getRightIdx(int p);
    inline int getParentIdx(int c);
    void fixHeap(int startIdx); // fix heap properties starting at a location
};

#endif

template <typename T>
MinHeap<T>::MinHeap(int cap) {
    m_capacity = cap;
    m_heap = new T[cap];
    m_size = 0;
}

template <typename T>
MinHeap<T>::~MinHeap() {
    delete[] m_heap;
}

template <typename T>
T MinHeap<T>::getMin() {
    return m_heap[0];
}

template <typename T>
bool MinHeap<T>::isEmpty() {
    return (m_size==0);
}

template <typename T>
int MinHeap<T>::getSize() {
    return m_size;
}

template <typename T>
int MinHeap<T>::getLeftIdx(int p) {
    return 2*p + 1;
}

template <typename T>
int MinHeap<T>::getRightIdx(int p) {
    return 2*p + 2;
}

template <typename T>
int MinHeap<T>::getParentIdx(int c) {
    return (c-1)/2;
}

template <typename T>
void MinHeap<T>::insert(T k) {
    // what if the array is full
    m_heap[m_size++] = k; // put it at last
    int currIdx = m_size - 1;
    while(currIdx > 0 && m_heap[currIdx] < m_heap[getParentIdx(currIdx)]) {
        // swap with parent
        T temp = m_heap[getParentIdx(currIdx)];
        m_heap[getParentIdx(currIdx)] = m_heap[currIdx];
        m_heap[currIdx] = temp;
        currIdx = getParentIdx(currIdx);
    }
}

template <typename T>
T MinHeap<T>::deleteMin() {
    // what if empty
    T ret = m_heap[0];
    if (m_size==1) {
        --m_size;
        return ret;
    }
    m_heap[0] = m_heap[--m_size];
    fixHeap(0);
    return ret;
}

template <typename T>
void MinHeap<T>::fixHeap(int startIdx) {
    int left = getLeftIdx(startIdx);
    int right = getRightIdx(startIdx);
    int smallestIdx = startIdx;
    if(left < m_size && m_heap[left] < m_heap[startIdx]) {
        smallestIdx = left;
    }
    if(right < m_size && m_heap[right] < m_heap[startIdx]) {
        smallestIdx = right;
    }
    if (smallestIdx != startIdx) { // have to swap
        T temp = m_heap[startIdx];
        m_heap[startIdx] = m_heap[smallestIdx];
        m_heap[smallestIdx] = temp;
        fixHeap(smallestIdx);
    }
}