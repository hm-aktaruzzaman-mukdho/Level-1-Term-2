#include <iostream>
#include <cstdlib>
// using namespace std;

template <typename type>
class linkedlist
{
protected:
    int head, Length, maxlength, currentposition;
    type *Headpointer;

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
    linkedlist(int X)
    {
        maxlength = X;
        Headpointer = new type[X];
        head = currentposition = -1;
        Length = 0;
    }

    linkedlist()
    {
        maxlength = 10;
        Headpointer = new type[maxlength];
        head = currentposition = -1;
        Length = 0;
    }


    void insert(type data)
    {
        if (Length >= maxlength)
        {
            maxlength = maxlength * 2;
            Headpointer = (type *)realloc(Headpointer, sizeof(type) * maxlength);
        }
        if (head == -1)//Inserting in the empty list
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
    }

    void append(type data)
    {
        if (Length >= maxlength)
        {
            maxlength = maxlength * 2;
            Headpointer = (type *)realloc(Headpointer, sizeof(type) * maxlength);
        }
        Headpointer[Length] = data;
        if (currentposition == -1)//For the first element.
            head = currentposition = 0;
        Length++;
    }

    type remove()
    {
        if (currentposition >= 0)
        {
            int temp = Headpointer[currentposition];
            shiftbackward();
            if(currentposition==Length-1)
                currentposition--;//When removing the last element currentposition is reduced.
            Length--;
            if (currentposition == -1)
                head = -1;
            return temp;
        }
        else
            return -1;
    }


    void moveToStart()
    {
        currentposition = head;
    }

    int moveToEnd()
    {
        currentposition = Length - 1;
        return -1;
    }

    void prev()
    {
        if (currentposition != head)
            currentposition--;
        
    }

    void next()
    {
        if (currentposition < Length - 1)
            currentposition++;
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
        //if (pos < Length&&pos>=head)
            currentposition = pos;
    }

    type getValue()
    {
        //if (Length != 0)
            return *(Headpointer + currentposition);
        // else
        //     return (type)NULL;
    }

    void printlist()
    {
        std::cout << "<";
        for (int i = 0; i < Length; i++)
        {
            if (i == currentposition)
            {
                std::cout << "|";
            }
            else
            {
                if (i != 0)
                    std::cout << ",";
            }
            std::cout << *(Headpointer + i) << " ";
        }
        std::cout << ">" << std::endl;
    }

    void clear()
    {
        head = currentposition = -1;
        Length = 0;
    }

    //Extra function for circulae queue.
    void setmaxlength(int x)
    {
        maxlength=x;
        Headpointer=(type*)realloc(Headpointer,sizeof(type)*maxlength);
    }

    void changeval(type data)
    {
        Headpointer[currentposition] = data;
        //you need to find a way to modify list length or the findamental
        //implementation of moveToPos and getValue won't work. 

    }

    void circulargrow(int &Front,int &tail)
    {
        int temp=maxlength;
        int j=0;
        maxlength=maxlength*2;
        type *tempptr=Headpointer;
        Headpointer= new type[maxlength];
        for(int i=Front;i<temp;i++)
        {
            Headpointer[j]=tempptr[i];
            j++;
        }
        for(int i=0;i<=tail;i++)
        {
            Headpointer[j]=tempptr[i];
            j++;
        }
        Front=0;
        tail=temp-1;

        delete[] tempptr;
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