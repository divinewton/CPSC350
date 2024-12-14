#ifndef CQUEUE_H
#define CQUEUE_H

#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class CQueue{
    public:
    CQueue();
    CQueue(int s);
    virtual ~CQueue();
    void add(T data);
    T remove();
    T peek();
    int size();
    bool isEmpty();
    bool isFull();

    private:
    int m_count;
    int m_front;
    int m_back;
    int m_max;
    T* m_arr;
};

    template <typename T>
    CQueue<T>::CQueue(){
        m_max = 0;
        m_count = 0;
        m_front = 0;
        m_back = -1;
        m_arr = NULL;
    }

    template <typename T>
    CQueue<T>::CQueue(int s) {
        m_max = s;
        m_count = 0;
        m_front = 0;
        m_back = -1;
        m_arr = new T[m_max];
    }

    template <typename T>
    CQueue<T>::~CQueue() {
        delete[] m_arr;
    }

    template <typename T>
    void CQueue<T>::add(T data) {
        if(!isFull()) { // there is space somewhere
            if (m_back == m_max -1) {
                m_back = -1;
            }
            m_arr[++m_back] = data;
            ++m_count;
        } else { // truly full
            T* temp = new T[2*m_max];
            int tc = 0;
            while(!isEmpty()) {
                temp[tc++] == remove();
            }
            delete[] m_arr;
            m_arr = temp;
            m_max *= 2;
            m_front = 0;
            m_back = m_count;
            m_arr[++m_back] = data;
            ++m_count;
        }
    }

    template <typename T>
    T CQueue<T>::remove() { // remove from front
        T ret = m_arr[m_front];
        ++m_front;
        --m_count;
        if (m_front == m_max) {
            m_front = 0;
        }
        return ret;
    }

    template <typename T>
    T CQueue<T>::peek() { // look at front
        return m_arr[m_front];
    }

    template <typename T>
    int CQueue<T>::size() {
        return m_count;
    }

    template <typename T>
    bool CQueue<T>::isEmpty() {
        return (m_count == 0);
    }

    template <typename T>
    bool CQueue<T>::isFull() {
        return (m_count == m_max);
    }

#endif