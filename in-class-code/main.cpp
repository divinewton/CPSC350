#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

int main(){
  Person p("Erik");
  cout << p.getName() << endl;
  Person* q = new Person("Elizabeth");
  cout << q->getName() << endl;
  delete q;
  int* x = new int[4];
  x[0] = 16;
  x[1] = 24;
  x[2] = 56;
  x[3] = 90;
  cout << *(x+1) << endl;
  cout << sizeof(*x) << endl;
  double* y;
  cout << sizeof(x) << endl;
  cout << sizeof(y) << endl;
  cout << sizeof(q) << endl;
  return 0;
}