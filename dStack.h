#ifndef DSTACK_H
#define DSTACK_H

#include <iostream>
#include <stdio.h>
#include "node.h"

using namespace std;

template <class t>
class dStack{

private:
  node<t>* top;
public:
  dStack();
  void add(t element);
  void removeElement(t &element);
  void print();
};

template<class t>
dStack<t>::dStack(){
  top = NULL;
}

template <class t>
void dStack<t>::add(t element){
  node<t>* newNode = new node<t>(element);
  if(!newNode){
    cout << "out of me memory" << endl;
    return;
  }
  newNode->setNext(top);
  top = newNode;
}

template <class t>
void dStack<t>::removeElement(t &element){
  node<t>* p;
  if(!top){
    cout << "stack is empty" << endl;
    return;
  }
  p = top->getnext();
  delete top;
  top = p;
}

template <class t>
void dStack<t>::print(){
  if(!top){
    cout << "stack is empty" << endl;
    return;
  }
  cout << endl << endl;
  node<t>* p = top;
  while (p) {
    cout << p->getInfo() << endl;
    p = p->getnext();
  }
}
#endif