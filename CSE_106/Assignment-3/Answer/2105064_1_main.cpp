#include <iostream>

#include "2105064_1_ll_queue.h"
//#include "2105064_1_a_queue.h"

using namespace std;

int main()
{
    int inputtype;
    Queue<int> queueint;
    Queue<char> queuechar;
    Queue<float> queuefloat;
    cout << "Enter data type:\n1. int \n2. char \n3. float \nEnter:";
    cin >> inputtype;
    if (inputtype > 3 || inputtype < 1)
    {
        cout << "Data type is not supported yet!!" << endl;
    }
    else
    {
        cout << "0 -> Exit" << endl;
        cout << "1 -> enqueue" << endl;
        cout << "2 -> dequeue" << endl;
        cout << "3 -> length" << endl;
        cout << "4 -> front" << endl;
        cout << "5 -> back" << endl;
        cout << "6 -> is_empty" << endl;
        cout << "7 -> clear" << endl;
        while (1)
        {
            cout << endl;
            if (inputtype == 1)
                queueint.printqueue();
            if (inputtype == 2)
                queuechar.printqueue();
            if (inputtype == 3)
                queuefloat.printqueue();
            int Q;
            cout << "Enter function number:";
            cin >> Q;
            switch (Q)
            {
            case 0:
                exit(0);
                break;

            case 1:
                if (inputtype == 1)
                {
                    int temp;
                    cout << "Enter data:";
                    cin >> temp;
                    queueint.enqueue(temp);
                }
                if (inputtype == 2)
                {
                    char temp;
                    cout << "Enter data:";
                    cin >> temp;
                    queuechar.enqueue(temp);
                }
                if (inputtype == 3)
                {
                    float temp;
                    cout << "Enter data:";
                    cin >> temp;
                    queuefloat.enqueue(temp);
                }
                break;

            case 2:
                if (inputtype == 1)
                {
                    cout << queueint.dequeue();
                }
                if (inputtype == 2)
                {
                    cout << queuechar.dequeue();
                }
                if (inputtype == 3)
                {
                    cout << queuefloat.dequeue();
                }
                break;

            case 3:
                if (inputtype == 1)
                {
                    cout << queueint.length();
                }
                if (inputtype == 2)
                {
                    cout << queuechar.length();
                }
                if (inputtype == 3)
                {
                    cout << queuefloat.length();
                }
                break;

            case 4:
                if (inputtype == 1)
                {
                    cout << queueint.front();
                }
                if (inputtype == 3)
                {
                    cout << queuefloat.front();
                }
                if (inputtype == 2)
                {
                    cout << queuechar.front();
                }
                break;

            case 5:
                if (inputtype == 1)
                {
                    cout << queueint.back();
                }
                if (inputtype == 3)
                {
                    cout << queuefloat.back();
                }
                if (inputtype == 2)
                {
                    cout << queuechar.back();
                }
                break;
            case 6:
                if (inputtype == 1)
                {
                    if (queueint.is_empty())
                        cout << "Queue is empty" << endl;
                    // else
                    //     cout << "Stack is full" << endl;
                }
                if (inputtype == 2)
                {
                    if (queuechar.is_empty())
                        cout << "Queue is empty" << endl;
                    // else
                    //     cout << "Stack is full" << endl;
                }
                if (inputtype == 3)
                {
                    if (queuefloat.is_empty())
                        cout << "Queue is empty" << endl;
                    // else
                    //     cout << "Stack is full" << endl;
                }
                break;
            case 7:
                if (inputtype == 1)
                    queueint.clear();
                if (inputtype == 2)
                    queuechar.clear();
                if (inputtype == 3)
                    queuefloat.clear();
                break;
                
            default:
                cout << "Worng function" << endl;
                break;
            }
        }
    }
    return 0;
}