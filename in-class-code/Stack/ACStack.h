#ifndef ACSTACK_H
#define ACSTACK_H

class ACStack{
    public:
        ACStack();
        ACStack(int iSize);
        virtual ~ACStack();
        void push(char c);
        char pop();
        char peek();
        bool isEmpty();
        bool isFull(); // doesn't make sense if we resize
        int size();
    private:
        char* stackArray; //array
        int count; //current size
        int top; // index of top
        int max;
};

#endif