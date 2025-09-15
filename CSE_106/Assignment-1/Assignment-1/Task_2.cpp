#include <iostream>
#include <cstdlib>

#include "Linked_list_double.cpp"
// #include "arr.cpp"

using namespace std;



template<class T>
class newlist : public linkedlist<T>
{
public:
    int append(T data)
    {
        int pos=this->currPos();
        this->moveToEnd();
        this->insert(data);
        this->moveToEnd();
        T lastval=this->remove();
        this->insert(lastval);
        if (pos == -1)
        {
            this->moveToPos(0);
        }
        else
        {
            this->moveToPos(pos);
        }
        return -1;
    }
    int clear()
    {
        this->moveToEnd();
        while (this->length() != 0)
        {
            this->remove();
        }
        return -1;
    }
    T search(T val)
    {
        this->moveToStart();
        int position = -1;
        for (int i = 0; i < this->length(); i++)
        {
            if (val == this->getValue())
            {
                return this->currPos();
            }
            this->next();
        }
        return position;
    }

};

int main()
{

    int K, X, P, Q;

    newlist<int> list;

    int returnval;
    // Type of return val variable depends of the list datatype.

    scanf("%d %d", &K, &X);
    if (K > X)
    {
        cout << "Error input" << endl;
        return -1;
    }

    list.init(X);
    for (int i = 0; i < K; i++)
    {
        int temp;
        if (i == (K - 1))
        {
            scanf("%d", &temp);
        }
        else
        {
            scanf("%d ", &temp);
        }
        // list.moveToEnd();
        // list.next();
        // list.insert(temp);
        list.append(temp);
    }

    list.printlist();
    while (1)
    {
        cin >> Q;
        switch (Q)
        {
        case 0:
            exit(0);
            break;

        case 1:
            returnval = list.clear();
            list.printlist();
            cout << returnval << endl;
            break;

        case 2:
            cout << "Enter parameter:";
            cin >> P;
            returnval = list.append(P);
            list.printlist();
            cout << returnval << endl;
            break;
        case 3:
            cout << "Enter parameter:";
            cin >> P;
            returnval = list.search(P);
            list.printlist();
            cout << returnval << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}
