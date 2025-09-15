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
    linkedlist()
    {
        currentposition = -1;
        Length = 0;
        struct _doubleLL *temp = new (struct _doubleLL);
        temp->next = NULL;
        temp->prev = NULL;
        head = tail = currentnode = temp;
    }

    void insert(type data)
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
            head=currentnode=newnode;
        }
        else if(currentnode->next!=NULL)
        {
            struct _doubleLL *currprev = currentnode->prev;
            newnode->next = currentnode;
            currentnode->prev = newnode;
            currprev->next = newnode;
            newnode->prev = currprev;
            currentnode = newnode;
            if (currentnode->next->next == NULL)
            {
                tail = currentnode;
            }
        }
        Length++;
    }

    void append(type data)
    {
        struct _doubleLL *newnode=new (struct _doubleLL);
        newnode->item=data;
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head->next==NULL)
        {
            newnode->next=head;
            head->prev=newnode;
            head=tail=currentnode=newnode;
            currentposition++;
        }
        else
        {
            newnode->next=tail->next;
            tail->next->prev=newnode;
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        Length++;
    }

    type remove()
    {
        struct _doubleLL *temp = currentnode;
        type x = temp->item;
        if((currentnode->next==NULL)&&(currentnode->prev==NULL))//For empty list.
        {
            return -1;
        }
        else if (currentnode->prev == NULL)//For head
        {
            currentnode = currentnode->next;
            currentnode->prev=NULL;
            head = currentnode;
        }
        else if((currentnode->prev==NULL)&&(currentnode->next->next==NULL))//if there is only one node
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

    void prev()
    {
        if (currentnode->prev != NULL)
        {
            currentnode = currentnode->prev;
            currentposition--;
        }
    }
    void next()
    {
        if (currentposition<Length-1)
        {
            currentnode = currentnode->next;
            currentposition++;
        }
    }

    void moveToStart()
    {
        currentnode = head;
        currentposition = 0;
    }

    void moveToEnd()
    {
        currentnode = tail;
        currentposition = Length - 1;
    }

    int length()
    {
        return Length;
    }
    int currPos()
    {
        return currentposition;
    }

    void moveToPos(int pos)
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
    }

    type getValue()
    {
        if (currentnode->next != NULL)
            return currentnode->item;
        return -1;
    }

    
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
//     int K, P, Q;
//     int returnval;
//     std::cout << "Enter the number of initial data:";
//     std::cin >> K;

//     linkedlist<int> list;
//     std::cout << "Enter the elements space seperated" << std::endl;
//     for (int i = 0; i < K; i++)
//     {
//         int temp;
//         std::cin >> temp;
//         list.append(temp);
//     }
//     std::cout << "0. end" << std::endl;
//     std::cout << "1. Insert()" << std::endl;
//     std::cout << "2. Remove()" << std::endl;
//     std::cout << "3. moveToStart()" << std::endl;
//     std::cout << "4. moveToEnd()" << std::endl;
//     std::cout << "5. prev()" << std::endl;
//     std::cout << "6. next()" << std::endl;
//     std::cout << "7. length()" << std::endl;
//     std::cout << "8. currPos()" << std::endl;
//     std::cout << "9. moveToPos()" << std::endl;
//     std::cout << "10. getValue()" << std::endl;
//     std::cout << "11. Append()" << std::endl;
//     std::cout << "12. Clear()" << std::endl;
//     list.printlist();
//     while (1)
//     {
//         std::cout << "Enter function number:";
//         std::cin >> Q;
//         switch (Q)
//         {
//         case 0:

//             exit(0);
//             break;

//         case 1:

//             std::cout << "Enter parameter:";
//             std::cin >> P;
//             list.insert(P);
//             list.printlist();
//             break;

//         case 2:

//             returnval = list.remove();
//             list.printlist();
//             std::cout << returnval << std::endl;
//             break;

//         case 3:

//             list.moveToStart();
//             list.printlist();
//             break;

//         case 4:

//             list.moveToEnd();
//             list.printlist();
//             break;

//         case 5:

//             list.prev();
//             list.printlist();
//             break;

//         case 6:

//             list.next();
//             list.printlist();
//             break;

//         case 7:
//             int len;
//             len = list.length();
//             list.printlist();
//             std::cout << len << std::endl;
//             break;

//         case 8:
//             int pos;
//             pos = list.currPos();
//             list.printlist();
//             std::cout << pos << std::endl;
//             break;

//         case 9:

//             std::cout << "Enter parameter:";
//             std::cin >> P;
//             list.moveToPos(P);
//             list.printlist();
//             break;

//         case 10:

//             returnval = list.getValue();
//             list.printlist();
//             std::cout << returnval << std::endl;
//             break;

//         case 11:
//             std::cout << "Enter parameter:";
//             std::cin >> P;
//             list.append(P);
//             list.printlist();
//             break;

//         case 12:
//             list.clear();
//             list.printlist();
//             break;

//         default:

//             std::cout << "Wrong Function Input" << std::endl;
//             break;
//         }
//     }

//     return 0;
// }
