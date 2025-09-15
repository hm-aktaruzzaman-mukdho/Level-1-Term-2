#include <iostream>
#include <cstdlib>

// Importing Linked list implementation

#include "Linked_list_double.cpp"
// #include "arr.cpp"

using namespace std;

int main()
{
    int K, X, P, Q;

    linkedlist<int> list;

    int returnval;
    // Type of return val variable depends of the list datatype.

    // scanf("%d %d", &K, &X);
    cin >> K >> X;
    if (K > X)
    {
        cout << "Error input" << endl;
        return -1;
    }

    list.init(X);
    for (int i = 0; i < K; i++)
    {
        int temp;
        /*if (i == (K - 1))
        {
            scanf("%d", &temp);
        }
        else
        {
            scanf("%d ", &temp);
        }*/
        cin >> temp;
        list.moveToEnd();
        list.insert(temp);
        list.moveToEnd();
        int lastval = list.remove();
        list.insert(lastval);
    }
    list.printlist();
    cout << "0. end" << endl;
    cout << "1. Insert()" << endl;
    cout << "2. Remove()" << endl;
    cout << "3. moveToStart()" << endl;
    cout << "4. moveToEnd()" << endl;
    cout << "5. prev()" << endl;
    cout << "6. next()" << endl;
    cout << "7. length()" << endl;
    cout << "8. currPos()" << endl;
    cout << "9. moveToPos()" << endl;
    cout << "10. getValue()" << endl;
    while (1)
    {
        cout << "Enter function number:";
        cin >> Q;
        switch (Q)
        {
        case 0:

            exit(0);
            break;

        case 1:

            cout << "Enter parameter:";
            cin >> P;
            returnval = list.insert(P);
            list.printlist();
            cout << returnval << endl;
            break;

        case 2:

            returnval = list.remove();
            list.printlist();
            cout << returnval << endl;
            break;

        case 3:

            returnval = list.moveToStart();
            list.printlist();
            cout << returnval << endl;
            break;

        case 4:

            returnval = list.moveToEnd();
            list.printlist();
            cout << returnval << endl;
            break;

        case 5:

            returnval = list.prev();
            list.printlist();
            cout << returnval << endl;
            break;

        case 6:

            returnval = list.next();
            list.printlist();
            cout << returnval << endl;
            break;

        case 7:

            returnval = list.length();
            list.printlist();
            cout << returnval << endl;
            break;

        case 8:

            returnval = list.currPos();
            list.printlist();
            cout << returnval << endl;
            break;

        case 9:

            cout << "Enter parameter:";
            cin >> P;
            returnval = list.moveToPos(P);
            list.printlist();
            cout << returnval << endl;
            break;

        case 10:

            returnval = list.getValue();
            list.printlist();
            cout << returnval << endl;
            break;

        default:

            cout << "Wrong Function Input" << endl;
            break;
        }
    }

    return 0;
}