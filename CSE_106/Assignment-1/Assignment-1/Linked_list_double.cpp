#include<iostream>
using namespace std;

template<typename type>
class linkedlist
{
protected:
    // structure for linked list node
    struct _doubleLL
    {
        type item;
        struct _doubleLL *next;
        struct _doubleLL *prev;
    };
    // End of structure

    struct _doubleLL *head;
    struct _doubleLL *tail;
    struct _doubleLL *currentnode;

    int currentposition;
    int Length;

public:
    void init(int X)
    {
        currentposition = -1;
        Length = 0;
        struct _doubleLL *temp = new (struct _doubleLL);
        temp->next = NULL;
        temp->prev = NULL;
        head = tail = currentnode = temp;
    }

    int insert(type data)
    {
        struct _doubleLL *newnode = new (struct _doubleLL);
        newnode->item = data;
        newnode->next = NULL;
        newnode->prev = NULL;

        if (head->next == NULL)
        {
            newnode->next = head;
            head->prev = newnode;
            head = tail = currentnode = newnode;
            currentposition++;
        }
        else if(currentposition==0)
        {
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
            currentnode=head;
        }
        else if(currentnode->next!=NULL)
        {
            struct _doubleLL *temp = currentnode->prev;
            newnode->next = temp->next;
            newnode->next->prev = newnode;
            temp->next = newnode;
            newnode->prev = temp;
            currentnode = newnode;
            if (currentnode->next->next == NULL)
            {
                tail = currentnode;
            }
        }
        Length++;
        return -1;
    }

    type remove()
    {
        struct _doubleLL *temp = currentnode;
        type x = temp->item;
        if((currentnode->next==NULL)&&(currentnode->prev==NULL))
        {
            return -1;
        }
        else if (currentnode->prev == NULL)
        {
            currentnode = currentnode->next;
            currentnode->prev=NULL;
            head = currentnode;
        }
        else if((currentnode->prev==NULL)&&(currentnode->next->next==NULL))
        {
            currentnode = currentnode->next;
            currentnode->prev=NULL;
            head = tail = currentnode;
            currentposition=-1;
        }
        else
        {
            currentnode = currentnode->next;
            currentnode->prev = temp->prev;
            temp->prev->next = currentnode;
            if (currentnode->next == NULL)
            {
                currentnode = currentnode->prev;
                tail = currentnode;
                currentposition--;
            }
        }
        Length--;
        delete temp;
        return x;
    }

    int prev()
    {
        if (currentnode->prev != NULL)
        {
            currentnode = currentnode->prev;
            currentposition--;
        }
        // else
        // cout << "Already at the first position" << endl;
        //Extra code used for debugging
        return -1;
    }
    int next()
    {
        if (currentposition<Length-1)
        {
            currentnode = currentnode->next;
            currentposition++;
        }
        /*else
        {
            cout << "Already at the end of the array" << endl;
        }*/
        //Extra code used for debugging

        return -1;
    }
    int moveToStart()
    {
        currentnode = head;
        currentposition = 0;

        return -1;
    }

    int moveToEnd()
    {
        currentnode = tail;
        currentposition = Length - 1;

        return -1;
    }

    int length()
    {
        return Length;
    }
    int currPos()
    {
        return currentposition;
    }

    int moveToPos(int pos)
    {
        if (pos < Length)
        {
            currentnode = head;
            currentposition = 0;
            while (currentposition < pos)
            {
                currentnode = currentnode->next;
                currentposition++;
            }
        }
        return -1;
    }

    type getValue()
    {
        if (currentnode->next != NULL)
            return currentnode->item;
        return -1;
    }

    /*Push and pop function is not a part of desired
    ADT implementation.void insert() function should
    replicate all the functionality of push*/


    /*void push(int data)
    {
        struct _doubleLL *newnode = new (struct _doubleLL);
        newnode->item = data;
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL)
        {
            head = newnode;
            currentnode = newnode;
            tail = newnode;
            currentposition = 1;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        Length++;
    }*/

    /*int pop()
    {
        struct _doubleLL *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        int x = temp->item;
        delete temp;
        Length--;
        if (currentposition > Length)
        {
            currentposition = Length;
        }
        return x;
    }*/

    void printlist()
    {
        struct _doubleLL *temp = head;
        int printpos = 0;
        cout << "<";
        while (temp->next != NULL)
        {
            if (printpos == currentposition)
            {
                cout << "|";
            }
            else
            {
                if (printpos != 0)
                    cout << ",";
            }
            printpos++;
            cout << temp->item<<" ";
            temp = temp->next;
        }
        cout << ">" << endl;
    }
};

// int main()
// {
//     linkedlist<int> list;
//     list.init(6);

//     list.insert(76);
//     list.printlist();
//     list.insert(64);
//     list.printlist();
//     list.insert(67);
//     list.printlist();
//     list.insert(74);
//     list.printlist();
//     list.insert(22);
//     list.printlist();
//     list.moveToPos(1);
//     list.insert(77);
//     list.printlist();
//     list.moveToEnd();
//     list.insert(93);
//     list.printlist();
//     cout<<list.length()<<endl;
//     cout<<list.currPos();

//     return 0;
// }
