#include "CQueue.h"
#include <iostream>
using namespace std;

int main() {
    CQueue<char> cq(4);
    cq.add('e');
    cq.add('r');
    cq.add('i');
    cq.add('k');
    cout << cq.isFull() << endl;
    while (!cq.isFull()) {
        cout << cq.remove() << endl;
    }

    cq.add('e');
    cq.add('r');
    cq.add('i');
    cq.add('k');
    cq.remove();
    cq.add('l');
    cq.add('i');
    cout << cq.isFull() << endl;
    while (!cq.isEmpty()) {
        cout << cq.remove() << endl;
    }

    return 0;
}