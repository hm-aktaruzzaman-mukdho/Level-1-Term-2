#include<iostream>
#include<algorithm>

using namespace std;

// class Train
// {
// public:
//     int starttime;
//     int endtime;
    
//     bool operator<(const Train &t) const
//     {
//         return starttime<t.starttime;
//     }
// };


int main()
{
    FILE *fp1 = freopen("Task-2_io/in3.txt", "r", stdin);
    //FILE *fp2 = freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    int arrival[n],departure[n];
    for (int i = 0; i < n; i++)
    {
        cin >> train[i].starttime >> train[i].endtime;
    }

    sort(train,train+n);

    for(int i=0;i<n;i++)
    {

    }

    int maxcount = 0;



    cout << maxcount << endl;

    fclose(fp1);
    //fclose(fp2);
    return 0;
}