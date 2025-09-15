#include <iostream>
#include <string>
using namespace std;

class Train
{
public:
    int starttime;
    int endtime;
    bool doesoverlap(const Train &t) const
    {
        // if (t.starttime > this->starttime && t.starttime < this->endtime)
        // {
        //     return true;
        // }

        if(t.endtime > this->starttime && t.endtime < this->endtime)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    FILE *fp1 = freopen("Task-2_io/in.txt", "r", stdin);
    //FILE *fp2 = freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    Train *train = new Train[n];
    for (int i = 0; i < n; i++)
    {
        cin >> train[i].starttime >> train[i].endtime;
    }

    int maxcount = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = 0; j < n; j++)
        {
            if (train[j].doesoverlap(train[i]))
            {
                count++;
            }
        }
        if (count >= maxcount)
        {
            maxcount = count;
        }
    }
    cout << maxcount << endl;

    fclose(fp1);
    //fclose(fp2);
    return 0;
}