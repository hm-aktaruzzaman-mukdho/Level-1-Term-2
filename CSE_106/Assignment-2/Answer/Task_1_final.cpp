#include <iostream>
#include <string>
#include <cstring>
#include "Stack.cpp"

using namespace std;

int main()
{
    int inputtype;
    cout << "Enter data type\n1. int \n2. char \nfloat \nEnter:";
    cin >> inputtype;
    int X, K;
    cin >> X >> K;
    Stack<int> stackint(X);
    Stack<char> stackchar(X);
    Stack<float> stackfloat(X);
    Stack<double> stackdouble(X);
    if (inputtype == 1)
    {
        for (int i = 0; i < K; i++)
        {
            int value;
            cin>>value;
            stackint.push(value);
        }
    }
    else if (inputtype == 2)
    {
        for (int i = 0; i < K; i++)
        {
            char value;
            cin>>value;
            stackchar.push(value);
        }
    }
    else if (inputtype == 3)
    {
        for (int i = 0; i < K; i++)
        {
            float value;
            cin>>value;
            stackfloat.push(value);
        }
    }
    else
    {
        cout << "Data type is not supported" << endl;
        exit(0);
    }
    while (1)
    {
        cout << "0 -> Exit" << endl;
        cout << "1 -> Clear" << endl;
        cout << "2 -> Push" << endl;
        cout << "3 -> Pop" << endl;
        cout << "4 -> length" << endl;
        cout << "5 -> topValue" << endl;
        cout << "6 -> isEmpty" << endl;
        if (inputtype == 1)
            stackint.printstack();
        if (inputtype == 2)
            stackchar.printstack();
        if (inputtype == 3)
            stackfloat.printstack();
        int Q;
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
                cout << stackint.pop();
            }

            if (inputtype == 2)
            {
                cout << stackchar.pop();
            }
            if (inputtype == 3)
            {
                cout << stackfloat.pop();
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
                else
                    cout << "Stack is full" << endl;
            }
            if (inputtype == 2)
            {
                if (stackchar.isEmpty())
                    cout << "Stack is empty" << endl;
                else
                    cout << "Stack is full" << endl;
            }
            if (inputtype == 3)
            {
                if (stackfloat.isEmpty())
                    cout << "Stack is empty" << endl;
                else
                    cout << "Stack is full" << endl;
            }
        default:
            cout << "Worng function" << endl;
            break;
        }
    }
    return 0;
}