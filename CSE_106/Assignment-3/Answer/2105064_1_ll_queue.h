#ifndef LLQUEUE_H
#define LLQUEUE_H

#include "Linked_list_double.cpp"
template <typename type>
class Queue
{
protected:
    linkedlist<type> queue;

public:
    void enqueue(type data);
    type dequeue();
    int length();
    type front();
    type back();
    bool is_empty();

    void clear();
    void printqueue();
};

#include "2105064_1_ll_queue.cpp"
#endif