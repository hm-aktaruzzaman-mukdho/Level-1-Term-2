#ifndef STACK_H
#define STACK_H

#include "2105064_1_a_queue.cpp"
// #include "2105064_1_ll_queue.cpp"
template <typename type>
class Stack
{
private:
    Queue<type> q_main,q_temp;
    int size;
public:
    Stack();
    void clear();
    void push(type item);
    type pop();
    int length();
    type topValue();
    bool isEmpty();
    void printstack(); 
};
#include "2105064_2_stack.cpp"
#endif