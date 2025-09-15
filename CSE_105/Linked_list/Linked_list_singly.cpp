#include <iostream>


template <class type>
class linkedlist
{
    struct _SingleLL
    {
        type item;
        struct _SingleLL *next;
    };

    struct _SingleLL *head;
    struct _SingleLL *tail;
    struct _SingleLL *currentnode;
    int currentposition;
    int Length;

public:
    linkedlist()
    {
        head = tail = currentnode = NULL;
        currentposition = -1;
        Length = 0;
    }

    int insert(type data)
    {
        /*Add a case for enlongating the tail*/
        struct _SingleLL *newnode = new (struct _SingleLL);
        newnode->item = data;
        newnode->next = NULL;
        if ((head == currentnode))
        {
            newnode->next = head;
            head = currentnode = newnode;
            if (currentposition == -1)
            {
                currentposition = 0;
                tail = newnode;
            }
        }
        else
        {
            struct _SingleLL *tempnode = head;
            while (tempnode->next != currentnode)
            {
                tempnode = tempnode->next;
            }
            tempnode->next = newnode;
            newnode->next = currentnode;
            currentnode = newnode;
        }
        Length++;
        return -1;
    }
    void append(type data)
    {
        struct _SingleLL *newnode = new (struct _SingleLL);
        newnode->next = NULL;
        newnode->item = data;
        if (head == NULL)
        {
            head = currentnode = tail = newnode;
            currentposition = 0;
        }
        tail->next = newnode;
        tail = newnode;
        Length++;
    }
    type remove()
    {
        if (currentnode != NULL)
        {
            type temp;
            struct _SingleLL *tempnode;
            tempnode = currentnode;
            temp = currentnode->item;

            if (currentnode == head)
            {
                tempnode = head;
                head = head->next;
                currentnode = head;
                if (head == NULL)
                {
                    tail = head;
                }
            }
            else
            {
                struct _SingleLL *prevnode;
                prevnode = head;
                while (prevnode->next != currentnode)
                {
                    prevnode = prevnode->next;
                }
                prevnode->next = currentnode->next;
                if (currentnode->next == NULL)
                {
                    currentnode = tail = prevnode;
                    currentposition--;
                }
            }
            Length--;
            delete tempnode;
            return temp;
        }
        else
            return (type)NULL;
    }
    void moveToStart()
    {
        currentnode = head;
        if (Length > 0)
            currentposition = 0;
    }
    void moveToEnd()
    {
        currentnode = tail;
        currentposition = Length - 1;
    }
    void prev()
    {
        if (currentnode != head)
        {
            struct _SingleLL *tempnode = head;
            int i = 0;
            while (tempnode->next != currentnode)
            {
                tempnode = tempnode->next;
                i++;
            }
            currentnode = tempnode;
            currentposition = i;
        }
    }
    void next()
    {
        if (currentnode != tail)
        {
            currentnode = currentnode->next;
            currentposition++;
        }
    }
    void clear()
    {
        moveToEnd();
        for (int i = 0; i < Length; i++)
        {
            remove();
        }
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
        if (head != NULL)
        {
            currentnode = head;
            currentposition = 0;
            while (currentposition != pos)
            {
                currentposition++;
                currentnode = currentnode->next;
            }
        }
    }
    type getValue()
    {
        if(currentnode!=NULL)
            return currentnode->item;
        else
            return (type)NULL;
    }

    void printlist()
    {
        struct _SingleLL *temp = head;
        std::cout << "<";
        while (temp != NULL)
        {
            if (temp == currentnode)
                std::cout << "|";
            if (temp != currentnode && temp != head)
                std::cout << ",";
            std::cout << temp->item;
            temp = temp->next;
        }
        std::cout << ">" << std::endl;
    }
};
int main()
{
    int K, P, Q;
    int returnval;
    std::cout << "Enter the number of initial data:";
    std::cin >> K;

    linkedlist<int> list;
    std::cout << "Enter the elements space seperated" << std::endl;
    for (int i = 0; i < K; i++)
    {
        int temp;
        std::cin >> temp;
        list.append(temp);
    }
    std::cout << "0. end" << std::endl;
    std::cout << "1. Insert()" << std::endl;
    std::cout << "2. Remove()" << std::endl;
    std::cout << "3. moveToStart()" << std::endl;
    std::cout << "4. moveToEnd()" << std::endl;
    std::cout << "5. prev()" << std::endl;
    std::cout << "6. next()" << std::endl;
    std::cout << "7. length()" << std::endl;
    std::cout << "8. currPos()" << std::endl;
    std::cout << "9. moveToPos()" << std::endl;
    std::cout << "10. getValue()" << std::endl;
    std::cout << "11. Append()" << std::endl;
    std::cout << "12. Clear()" << std::endl;
    list.printlist();
    while (1)
    {
        std::cout << "Enter function number:";
        std::cin >> Q;
        switch (Q)
        {
        case 0:

            exit(0);
            break;

        case 1:

            std::cout << "Enter parameter:";
            std::cin >> P;
            list.insert(P);
            list.printlist();
            break;

        case 2:

            returnval = list.remove();
            list.printlist();
            std::cout << returnval << std::endl;
            break;

        case 3:

            list.moveToStart();
            list.printlist();
            break;

        case 4:

            list.moveToEnd();
            list.printlist();
            break;

        case 5:

            list.prev();
            list.printlist();
            break;

        case 6:

            list.next();
            list.printlist();
            break;

        case 7:
            int len;
            len = list.length();
            list.printlist();
            std::cout << len << std::endl;
            break;

        case 8:
            int pos;
            pos = list.currPos();
            list.printlist();
            std::cout << pos << std::endl;
            break;

        case 9:

            std::cout << "Enter parameter:";
            std::cin >> P;
            list.moveToPos(P);
            list.printlist();
            break;

        case 10:

            returnval = list.getValue();
            list.printlist();
            std::cout << returnval << std::endl;
            break;

        case 11:
            std::cout << "Enter parameter:";
            std::cin >> P;
            list.append(P);
            list.printlist();
            break;

        case 12:
            list.clear();
            list.printlist();
            break;

        default:

            std::cout << "Wrong Function Input" << std::endl;
            break;
        }
    }

    return 0;
}