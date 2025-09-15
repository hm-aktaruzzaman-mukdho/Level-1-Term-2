
#include "2105064_1_ll_queue.h"


template <typename type> 
    void Queue<type>::enqueue(type data)
    {
        queue.append(data);
        
    }
    template <typename type> 
    type Queue<type>::dequeue()
    {
        queue.moveToStart();
        return queue.remove();
    }
    template <typename type> 
    int Queue<type>::length()
    {
        return queue.length();
    }
    template <typename type> 
    type Queue<type>::front()
    {
        queue.moveToStart();
        return queue.getValue();
    }
    template <typename type> 
    type Queue<type>::back()
    {
        queue.moveToEnd();
        return queue.getValue();
    }
    template <typename type> 
    bool Queue<type>::is_empty()
    {
        if(queue.length()==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    template <typename type> 
    void Queue<type>::clear()
    {
        
        queue.moveToStart();
        int l=queue.length();
        for(int i=0;i<l;i++)
        {
            queue.remove();
        }
    }
    template <typename type> 
    void Queue<type>::printqueue()
    {
        queue.moveToStart();
        int l=queue.length();
        std::cout<<"<";
        for(int i=0;i<l;i++)
        {
            std::cout<<queue.getValue();
            if(i<(l-1))
                std::cout<<",";
            queue.next();
        }
        std::cout<<">"<<std::endl;
    }
