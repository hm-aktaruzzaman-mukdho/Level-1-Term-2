#include <iostream>
#include <string>
#include <cstring>
#include "Stack.cpp"

using namespace std;

int main()
{
    string inputtype;
    cout<<"Enter data type(int,char,float is supported):";
    cin >> inputtype;
    int X, K;
    cin >> X >> K;
    Stack<int> stackint(X);
    Stack<char> stackchar(X);
    Stack<float> stackfloat(X);
    Stack<double> stackdouble(X);
    if (inputtype=="int")
    {
        for (int i = 0; i < K; i++)
        {
            int value;
            cin>>value;
            stackint.push(value);
        }
    }
    else if (inputtype == "char")
    {
        for (int i = 0; i < K; i++)
        {
            char value;
            cin>>value;
            stackchar.push(value);
        }
    }
    else if (inputtype == "float")
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

        cout<<endl<<endl;
        cout << "0 -> Exit" << endl;
        cout << "1 -> Clear" << endl;
        cout << "2 -> Push" << endl;
        cout << "3 -> Pop" << endl;
        cout << "4 -> length" << endl;
        cout << "5 -> topValue" << endl;
        cout << "6 -> isEmpty" << endl;
    while (1)
    {
        if (inputtype == "int")
                stackint.printstack();
        if (inputtype == "char")
                stackchar.printstack();
        if (inputtype == "float")
                stackfloat.printstack();
        int Q;
        cin >> Q;
        switch (Q)
        {
        case 0:
            exit(0);
            break;

        case 1:
            if (inputtype == "int")
                stackint.clear();
            if (inputtype == "char")
                stackchar.clear();
            if (inputtype == "float")
                stackfloat.clear();
            break;

        case 2:
            if (inputtype == "int")
            {
                int temp;
                cout<<"Enter data:";
                cin >> temp;
                stackint.push(temp);
            }
            if (inputtype == "char")
            {
                char temp;
                cout<<"Enter data:";
                cin >> temp;
                stackchar.push(temp);
            }
            if (inputtype == "float")
            {
                float temp;
                cout<<"Enter data:";
                cin >> temp;
                stackfloat.push(temp);
            }
            break;

        case 3:
            if (inputtype == "int")
            {
                cout << stackint.pop()<<endl;
            }
            if (inputtype == "float")
            {
                cout << stackfloat.pop()<<endl;
            }
            if (inputtype == "char")
            {
                cout << stackchar.pop()<<endl;
            }
            break;

        case 4:
            if (inputtype == "int")
            {
                cout << stackint.length()<<endl;
            }
            if (inputtype == "char")
            {
                cout << stackchar.length()<<endl;
            }
            if (inputtype == "float")
            {
                cout << stackfloat.length()<<endl;
            }
            break;

        case 5:
            if (inputtype == "int")
            {
                cout << stackint.topValue()<<endl;
            }
            if (inputtype == "float")
            {
                cout << stackfloat.topValue()<<endl;
            }
            if (inputtype == "char")
            {
                cout << stackchar.topValue()<<endl;
            }
            break;
        case 6:
            if (inputtype == "int")
            {
                if(stackint.isEmpty())
                    cout<<"Stack is empty"<<endl;
                else
                    cout<<"Stack is full"<<endl;
            }
            if (inputtype == "char")
            {
                if(stackchar.isEmpty())
                    cout<<"Stack is empty"<<endl;
                else
                    cout<<"Stack is full"<<endl;
            }
            if (inputtype == "float")
            {
                if(stackfloat.isEmpty())
                    cout<<"Stack is empty"<<endl;
                else
                    cout<<"Stack is full"<<endl;
            }
            break;
        default:
            cout << "Worng function" << endl;
            break;
        }
    }
    return 0;
}