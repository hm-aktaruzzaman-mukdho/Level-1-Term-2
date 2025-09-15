#include <iostream>
#include "2105064_2_stack.h"


template <typename type>
Stack<type>::Stack()
{
    size = 0;
}
template <typename type>
void Stack<type>::clear()
{
    q_main.clear(); // Holds the stack
    q_temp.clear(); // Temporary stores the items during push.
}
template <typename type>
void Stack<type>::push(type item)
{
    q_temp.enqueue(item);

    while (!q_main.is_empty())
    {
        q_temp.enqueue(q_main.dequeue());
    }

    while (!q_temp.is_empty())
    {
        q_main.enqueue(q_temp.dequeue());
    }
}
template <typename type>
type Stack<type>::pop()
{
    return q_main.dequeue();
}
template <typename type>
int Stack<type>::length()
{
    return size;
}
template <typename type>
type Stack<type>::topValue()
{
    return q_main.front();
}
template <typename type>
bool Stack<type>::isEmpty()
{
    return q_main.is_empty();
}
template <typename type>
void Stack<type>::printstack()
{
    // Needs some modification.
    int l = q_main.length();
    type *arr = new type[l];

    for (int i = 0; i < l; i++)
    {
        arr[i] = q_main.front();
        q_temp.enqueue(q_main.dequeue());
    }

    std::cout << "<";
    for (int i = l - 1; i >= 0; i--)
    {
        std::cout << arr[i];
        if (i != 0)
            std::cout << ",";
    }
    std::cout << ">" << std::endl;

    delete[] arr;

    while (!q_temp.is_empty())
    {
        q_main.enqueue(q_temp.dequeue());
    }
}
