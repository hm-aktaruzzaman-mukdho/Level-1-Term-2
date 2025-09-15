#include <iostream>
#include "2105064_1_a_queue.h"

template <typename type>
Queue<type>::Queue()
{
    Front = tail = -1;
    Length = 0;
    queuesize = 10;
    q1.setmaxlength(queuesize);
}

template <typename type>
Queue<type>::Queue(int x)
{
    Front = tail = -1;
    Length = 0;
    queuesize = x;
    q1.setmaxlength(queuesize);
}
template <typename type>
void Queue<type>::enqueue(type data)
{
    if (Length == queuesize)
    {
        queuesize = queuesize * 2;
        q1.circulargrow(Front, tail);
    }
    if (Front == -1 && tail == -1)
    {
        Front = tail = 0;
        q1.moveToPos(Front);
        q1.changeval(data);
    }
    else
    {
        tail = (tail + 1) % queuesize;
        q1.moveToPos(tail);
        q1.changeval(data);
    }

    Length++;
}
template <typename type>
type Queue<type>::dequeue()
{
    if (Length != 0)
    {
        q1.moveToPos(Front);
        type temp = q1.getValue();
        Front = (Front + 1) % queuesize;
        Length--;
        if (Length == 0)
            Front = tail = -1;
        return temp;
    }
    else
        return (type)NULL;
}
template <typename type>
int Queue<type>::length()
{
    return Length;
}
template <typename type>
type Queue<type>::front()
{
    if (Length > 0)
    {
        q1.moveToPos(Front);
        return q1.getValue();
    }
    else
        return (type)NULL;
}
template <typename type>
type Queue<type>::back()
{
    if (Length > 0)
    {
        q1.moveToPos(tail);
        return q1.getValue();
    }
    else
        return (type)NULL;
}
template <typename type>
bool Queue<type>::is_empty()
{
    if (Length > 0)
        return false;
    else
        return true;
}
template <typename type>
void Queue<type>::clear()
{
    Front = tail = -1;
}
template <typename type>
void Queue<type>::printqueue()
{
    std::cout << "<";
    if (Front <= tail && Length > 0)
    {
        for (int i = Front; i <= tail; i++)
        {
            q1.moveToPos(i);
            std::cout << q1.getValue();
            if (i != tail)
                std::cout << ",";
        }
    }
    if (Front > tail && Length > 0)
    {
        // while(1)
        {
            for (int i = Front; i < queuesize; i++)
            {
                q1.moveToPos(i);
                std::cout << q1.getValue() << ",";
            }
            for (int i = Front; i < queuesize; i++)
            {
                q1.moveToPos(i);
                std::cout << q1.getValue();
                if (i != tail)
                    std::cout << ",";
            }
        }
    }
    // int i=Front;
    // while(1)
    // {
    //     q1.moveToPos(i);
    //     std::cout<<q1.getValue();
    //     if(i!=tail)
    //     {
    //         std::cout<<",";
    //     }
    //     if(i==tail)
    //         break;
    //     i++;
    // }
    std::cout << ">" << std::endl;
}
