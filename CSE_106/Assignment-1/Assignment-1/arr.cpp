#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class linkedlist
{
protected:
    int head, Length, maxlength, initmaxlen;
    int currentposition;
    int *Headpointer;

    void shiftforward()
    {
        for (int i = Length - 1; i >= (currentposition); i--)
        {
            Headpointer[i + 1] = Headpointer[i];
        }
    }

    void shiftbackward()
    {
        for (int i = currentposition; i < Length - 1; i++)
        {
            Headpointer[i] = Headpointer[i + 1];
        }
    }

public:
    void init(int X)
    {
        maxlength = initmaxlen = X;
        Headpointer = new int[X];
        head = -1;
        currentposition = -1;
        Length = 0;
    }

    int insert(int data)
    {
        if (Length >= maxlength)
        {
            maxlength += initmaxlen;
            Headpointer = (int *)realloc(Headpointer, sizeof(int) * maxlength);
        }
        if (head == -1)
        {
            head = currentposition = 0;
            Headpointer[currentposition] = data;
        }
        else if (currentposition < Length)
        {
            shiftforward();
            Headpointer[currentposition] = data;
        }
        else if (currentposition == Length)
        {
            Headpointer[currentposition] = data;
        }
        Length++;

        return -1;
    }

    int remove()
    {
        if (currentposition >= 0)
        {
            int temp = Headpointer[currentposition];
            shiftbackward();
            currentposition--;
            Length--;
            if(currentposition==-1)
                head=-1;
            return temp;
        }
        else
            return -1;
    }

    int moveToStart()
    {
        currentposition = head;
        return -1;
    }

    int moveToEnd()
    {
        currentposition = Length - 1;
        return -1;
    }

    int prev()
    {
        if (currentposition == head)
            return -1;
        currentposition--;
        return -1;
    }

    int next()
    {
        if (currentposition < Length - 1)
            currentposition++;
        return -1;
    }

    int length()
    {
        // cout << "Maxlength" << maxlength << endl;
        return Length;
    }

    int currPos()
    {
        return currentposition;
    }

    int moveToPos(int pos)
    {
        if (pos < Length)
            currentposition = pos;
        return -1;
    }

    int getValue()
    {
        return *(Headpointer + currentposition);
    }

    /*int push(int value)
    {
        *(Headpointer + Length) = value;
        Length++;
        if (head == 0)
        {
            head = 1;
            currentposition = 1;
        }

        return -1;
    }*/

    void printlist()
    {
        cout << "<";
        for (int i = 0; i < Length; i++)
        {
            if (i == currentposition)
            {
                cout << "|";
            }
            else
            {
                if (i != 0)
                    cout << ",";
            }
            cout << *(Headpointer + i) << " ";
        }
        cout << ">" << endl;
    }
};

// int main()
// {
//     linkedlist list;

//     list.init(2);
//     list.printlist();
//     cout << list.currPos()<<endl;
//     list.moveToEnd();
//     cout << list.currPos()<<endl;
//     list.next();
//     cout << list.currPos()<<endl;
//     list.moveToEnd();
//     cout << list.currPos()<<endl;
//     list.insert(8);
//     list.printlist();
//     cout << list.currPos()<<endl;
//     list.moveToEnd();
//     cout << list.currPos()<<endl;
//     int lastval = list.remove();
//     cout<<lastval<<endl;
//     cout << list.currPos()<<endl;
//     list.insert(lastval);
//     cout << list.currPos()<<endl;
//     list.printlist();

    //     list.insert(5);
    //     list.printlist();
    //     list.moveToStart();
    //     list.insert(34);
    //     list.printlist();
    //     list.length();
    //     list.moveToEnd();
    //     list.insert(76);
    //     list.length();
    //     list.printlist();
    //     list.moveToEnd();
    //     list.next();
    //     list.insert(22);
    //     list.printlist();
    //     list.insert(67);
    //     list.length();
    //     list.printlist();
    //     list.moveToEnd();
    //     list.next();
    //     list.insert(69);
    //     list.printlist();
    //     list.moveToPos(2);
    //     list.printlist();
    //     list.remove();
    //     list.printlist();
    //     list.moveToEnd();
    //     list.remove();
    //     list.printlist();
    //     list.next();
    //     list.printlist();

//    return 0;
//}