#include <iostream>
#include <cstdlib>
using namespace std;

template <typename type>
class Stack
{
private:
    type *Headpointer;
    int top;
    int stacksize;

public:
    Stack(int X)
    {
        stacksize = X;
        Headpointer = new type[stacksize];
        top = -1;
    }

    Stack()
    {
        stacksize = 10;
        Headpointer = new type[stacksize];
        top = -1;
    }

    void clear()
    {
        top = -1;
    }

    void push(type item)
    {
        if (stacksize == (top +1))
        {
            stacksize = stacksize + stacksize;
            type *tempptr = (type *)realloc(Headpointer, sizeof(type) * stacksize);
            if (tempptr != NULL)
            {
                Headpointer = tempptr;
            }
            else
                stacksize = stacksize / 2;
        }
        if (top < stacksize)
        {
            top++;
            Headpointer[top] = item;
        }
        else
            cout << "Stack is full and cannot allocate more memory" << endl;
        // cout << stacksize << endl;
    }

    type pop()
    {
        if (top >= 0)
        {
            type temp = Headpointer[top];
            top--;
            return temp;
        }
        else
        {
            cout << "Stack is empty" << endl;
            return (type)NULL;
        }
    }

    int length()
    {
        int Length = 0;
        if (top >= 0)
        {
            Length = top + 1;
        }
        return Length;
    }

    type topValue()
    {
        if (top >= 0)
        {
            return Headpointer[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return (type)NULL;
        }
    }

    bool isEmpty()
    {
        if (top == (-1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void printstack()
    {
        cout << "<";
        for (int i = 0; i <= top; i++)
        {
            cout << " " << Headpointer[i] << " ";
        }
        cout << ">"<<endl;
    }

    ~Stack()
    {
        delete[] Headpointer;
    }
};

// int main()
// {
//     Stack<int> stack(2);
//     stack.push(4);
//     stack.push(3);
//     stack.push(9);
//     stack.push(4);
//     stack.push(3);
//     stack.push(9);
//     stack.printstack();
//     cout<<stack.length();
//     cout<<stack.topValue();
//     return 0;
// }
