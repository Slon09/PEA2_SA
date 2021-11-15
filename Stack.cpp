#include "Stack.h"

Stack::Stack()
{
    n = nullptr;
}

Stack::~Stack()
{
    while(n) pop();
}

void Stack::pop(){
    if(n){
        Node *e = n;
        n = n->next;
        delete e;
    }
}

void Stack::push(int v){
    Node *e = new Node;
    e->index = v;
    e->next = n;
    n=e;
}

int Stack::top(){
    return n->index;
}
bool Stack::isEmpty(){
    return !n;
}
