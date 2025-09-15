#include <iostream>
#include "2105064_2_stack.h"
using namespace std;

int main()
{
    int inputtype;
    cout << "Enter data type\n1. int \n2. char \n3. float \nEnter:";
    cin >> inputtype;
    Stack<int> stackint;
    Stack<char> stackchar;
    Stack<float> stackfloat;
    Stack<double> stackdouble;
    
    if (inputtype < 1 || inputtype > 3)
    {
        cout << "Wrong datatype input" << endl;
        exit(0);
    }
    cout << "0 -> Exit" << endl;
    cout << "1 -> Clear" << endl;
    cout << "2 -> Push" << endl;
    cout << "3 -> Pop" << endl;
    cout << "4 -> length" << endl;
    cout << "5 -> topValue" << endl;
    cout << "6 -> isEmpty" << endl;
    while (1)
    {
        cout<<endl;
        if (inputtype == 1)
            stackint.printstack();
        if (inputtype == 2)
            stackchar.printstack();
        if (inputtype == 3)
            stackfloat.printstack();
        int Q;
        cout<<"Enter function number:";
        cin >> Q;
        switch (Q)
        {
        case 0:
            exit(0);
            break;

        case 1:
            if (inputtype == 1)
                stackint.clear();
            if (inputtype == 2)
                stackchar.clear();
            if (inputtype == 3)
                stackfloat.clear();
            break;

        case 2:
            if (inputtype == 1)
            {
                int temp;
                cout << "Enter data:";
                cin >> temp;
                stackint.push(temp);
            }
            if (inputtype == 2)
            {
                char temp;
                cout << "Enter data:";
                cin >> temp;
                stackchar.push(temp);
            }
            if (inputtype == 3)
            {
                float temp;
                cout << "Enter data:";
                cin >> temp;
                stackfloat.push(temp);
            }
            break;

        case 3:
            if (inputtype == 1)
            {
                cout << stackint.pop() << endl;
            }

            if (inputtype == 2)
            {
                cout << stackchar.pop() << endl;
            }
            if (inputtype == 3)
            {
                cout << stackfloat.pop() << endl;
            }
            break;

        case 4:
            if (inputtype == 1)
            {
                cout << stackint.length();
            }
            if (inputtype == 2)
            {
                cout << stackchar.length();
            }
            if (inputtype == 3)
            {
                cout << stackfloat.length();
            }
            break;

        case 5:
            if (inputtype == 1)
            {
                cout << stackint.topValue();
            }
            if (inputtype == 3)
            {
                cout << stackfloat.topValue();
            }
            if (inputtype == 2)
            {
                cout << stackchar.topValue();
            }
            break;

        case 6:
            if (inputtype == 1)
            {
                if (stackint.isEmpty())
                    cout << "Stack is empty" << endl;
                // else
                //     cout << "Stack is full" << endl;
            }
            if (inputtype == 2)
            {
                if (stackchar.isEmpty())
                    cout << "Stack is empty" << endl;
                // else
                //     cout << "Stack is full" << endl;
            }
            if (inputtype == 3)
            {
                if (stackfloat.isEmpty())
                    cout << "Stack is empty" << endl;
                // else
                //     cout << "Stack is full" << endl;
            }
            break;
            
        default:
            cout << "Worng function" << endl;
            break;
        }
    }
    return 0;
}