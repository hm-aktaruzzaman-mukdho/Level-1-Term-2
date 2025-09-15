#ifndef AQUEUE_H
#define AQUEUE_H

#include "Array_list.cpp"

template <typename type>
class Queue
{
protected:
    linkedlist<type> q1;
    int Front, tail, Length, queuesize;

public:
    Queue();

    Queue(int x);

    void enqueue(type data);
    type dequeue();

    int length();

    type front();

    type back();

    bool is_empty();

    void clear();

    void printqueue();


};
#include "2105064_1_a_queue.cpp"
#endif

