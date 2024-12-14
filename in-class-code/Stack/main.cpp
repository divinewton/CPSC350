#include "ATStack.h"
#include <iostream>
using namespace std;

int main() {
    ATStack<char> myStack(3);
    myStack.push('e');
    myStack.push('r');
    myStack.push('i');
    myStack.push('k');

    cout << myStack.size() << endl;
    cout << myStack.peek() << endl;

    while(!myStack.isEmpty()) {
        cout << myStack.pop() << endl;
    }

    ATStack<double> myStack2(3);
    myStack2.push(1.0);
    myStack2.push(2.0);
    myStack2.push(7.0);

    ATStack<long> myStack3(3);
    myStack3.push(240000);

    ATStack<string> myStack4(3);
    myStack4.push("erik");

    return 0;
}