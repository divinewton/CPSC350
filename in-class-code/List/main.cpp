#include "DblList.h"
#include <iostream>
using namespace std;

int main() {
    DblList<char> charList;
    charList.addFront('e');
    charList.addBack('r');
    charList.addBack('i');
    charList.addFront('k');
    charList.add(2, 'j');
    charList.remove(3);

    while (!charList.isEmpty()) {
        cout << charList.removeFront() << endl;
    }

    return 0;
}