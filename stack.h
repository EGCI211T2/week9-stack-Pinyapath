#ifndef stack_h
#define stack_h
#include "node.h"

class Stack {
    NodePtr top;
    int size;
public:
    void push(char);
    char pop();
    Stack();
    ~Stack();
    bool isEmpty(){ return size==0; }
};

Stack::Stack(){
    top = NULL;
    size = 0;
}

void Stack::push(char x){
    NodePtr new_node = new NODE(x);
    if(new_node){
        new_node->set_next(top);   // fixed here
        top = new_node;
        size++;
    }
    else{
        cout << "Not enough memory" << endl;
    }
}

char Stack::pop(){
    if(size > 0){
        NodePtr t = top;
        char value;

        value = t->get_value();
        top = top->get_next();   // fixed here

        delete t;
        size--;
        return value;
    }
    else{
        cout << "Empty Stack" << endl;
        return 0;
    }
}

Stack::~Stack(){
    cout << "Clearing all nodes" << endl;
    while(size > 0) pop();
}

#endif
