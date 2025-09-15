#include <iostream>
#include "Priority_Queue.cpp"

using namespace std;

int main()
{
    Priority_Queue<int> pq;

    FILE *fp1=freopen("in1.txt","r",stdin);
    FILE *fp2=freopen("output1.txt","w",stdout);
    while(1)
    {
        int command,index,key;
        //std::cout<<"Enter command:";
        std::cin>>command;

        switch(command)
        {
            case 1:
                cin>>key;
                pq.Insert(key);
                //pq.Print();
                break;

            case 2:
                pq.FindMax();
                //pq.Print();
                break;

            case 3:
                pq.ExtractMax();
                //pq.Print();
                break;

            case 4:
                cin>>index>>key;
                pq.IncreaseKey(index,key);
                //pq.Print();
                break;

            case 5:
                cin>>index>>key;
                pq.DecreaseKey(index,key);
                //pq.Print();
                break;

            case 6:
                pq.Print();
                break;

            case 7:
                pq.SortQueue();
                pq.Print();
                fclose(fp1);
                fclose(fp2);
                exit(0);
                break;

            default:
                //cout<<"Error input!";
                break;

        }
    }
    return 0;
}