// Demonstrate count().
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
    vector<bool> v;
    unsigned int i;
    for (i = 0; i < 10; i++)
    {
        if (rand() % 2)
            v.push_back(true);
        else
            v.push_back(false);
    }
    cout << "Sequence:\n";
    for (i = 0; i < v.size(); i++)
        cout << boolalpha << v[i] << " ";
    cout << endl;
    i = count(v.begin(), v.end(), true);
    cout << i << " elements are true.\n";
    return 0;
}