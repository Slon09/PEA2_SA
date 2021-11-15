#ifndef STACK_H
#define STACK_H

#include "Node.h"

class Stack
{
    public:
        Stack();
        virtual ~Stack();
        int top();
        void push(int v);
        void pop();
        bool isEmpty();

    private:
        Node* n;
};

#endif // STACK_H
