#include<iostream>
#include<list>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
    list<double> values;
    for(int i=0;i<20;i++)
    {
        values.push_back((double)i);
    }

    cout<<"Initial list : ";
    for(auto p=values.begin();p!=values.end();)
    {
        cout<<*p++<<" ";
    }
    cout<<endl;

    list<double> negatedvalues(20);
    transform(values.begin(),values.end(),negatedvalues.begin(),negate<double>());

    
    cout<<"Negated list : ";
    for(auto value:negatedvalues)
        cout<<value<<" ";
    cout<<endl;

    cout<<"Original list : ";
    for(auto value:values)
        cout<<value<<" ";
    cout<<endl;
}

// // Use a unary function object.
// #include <iostream>
// #include <list>
// #include <functional>
// #include <algorithm>
// using namespace std;
// int main() {
//     list<double> vals;
//     int i;
//     // put values into list
//     for (i = 1; i < 10; i++)  vals.push_back((double)i);
//     cout << "Original contents of vals:\n";
//     list<double>::iterator p = vals.begin();
//     while (p != vals.end())     {
//         cout << *p << " ";
//         p++;
//     }
//     cout << endl;

// // use the negate function object
//     p = transform(vals.begin(), vals.end(), vals.begin(), 
//                              negate<double>()); // call function object
//     cout << "Negated contents of vals:\n";
//     p = vals.begin();
//     while (p != vals.end())
//     {
//         cout << *p << " ";
//         p++;
//     }
//     return 0;
// }