#include <iostream>

template <typename type>
class linkedlist
{
protected:
    struct _doubleLL
    {
        type data;
        _doubleLL *next;
        _doubleLL *prev;
    };

    _doubleLL *head;
    _doubleLL *tail;
    _doubleLL *currentnode;
    int currentposition, Length;

public:
    linkedlist()
    {
        head = tail = currentnode = NULL;
        currentposition = -1;
        Length = 0;
    }

    void insert(type data)
    {
        _doubleLL *newnode = new (_doubleLL);
        newnode->next = newnode->prev = NULL;
        newnode->data = data;

        if (currentnode == head)
        {
            newnode->next = head;
            if (head == NULL)
            {
                head = tail = currentnode = newnode;
                currentposition++;
            }
            else
            {
                head->prev = newnode;
            }
        }
        else
        {
            newnode->next = currentnode;
            newnode->prev = currentnode->prev;
            currentnode->prev->next = newnode;
            currentnode->prev = newnode;
            currentnode = newnode;
        }
        Length++;
    }

    type remove()
    {
        if (currentnode != NULL)
        {
            _doubleLL *tempnode = currentnode;
            type data = currentnode->data;
            if (currentnode == head && currentnode != tail)
            {
                head = head->next;
                head->prev = NULL;
                currentnode=head;
            }
            else if (currentnode == tail && currentnode != head)
            {
                tail = tail->prev;
                tail->next = NULL;
                currentnode = tail;
                currentposition--;
            }
            else if (currentnode == head && currentnode == tail)
            {
                head = tail = currentnode = NULL;
                currentposition = -1;
            }
            else
            {
                currentnode->next->prev = currentnode->prev;
                currentnode->prev->next = currentnode->next;
            }
            Length--;
            return data;
        }
        else
            return (type)NULL;
    }
    void append(type data)
    {

        _doubleLL *newnode = new (_doubleLL);
        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = NULL;
        if (tail == NULL)
        {
            head = tail = currentnode = newnode;
            currentposition = 0;
        }
        else
        {
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
        }
        Length++;
    }

    void moveToStart()
    {
        if (Length > 0)
            currentposition = 0;
        currentnode = head;
    }

    void moveToEnd()
    {
        currentnode = tail;
        currentposition = Length - 1;
    }

    void moveToPos(int n)
    {
        currentposition = 0;
        currentnode = head;
        while (currentposition = n - 1)
        {
            currentnode = currentnode->next;
            currentposition++;
        }
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
        if (currentnode->next != NULL)
        {
            currentnode = currentnode->next;
            currentposition++;
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

    type getValue()
    {
        if (currentnode != NULL)
            return currentnode->data;
        else
            return (type)NULL;
    }

    void clear()
    {
        moveToEnd();
        while (Length)
        {
            remove();
        }
    }

    void printlist()
    {
        _doubleLL *temp = head;
        std::cout << "<";
        while (temp != NULL)
        {
            if (temp == currentnode)
                std::cout << "|";
            if (temp != currentnode && temp != head)
                std::cout << ",";
            std::cout << temp->data;
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