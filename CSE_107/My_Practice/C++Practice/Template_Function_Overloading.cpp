#include <iostream>
using namespace std;


template <typename T,typename E>
void func(T x, E y)
{
    cout<< "Inside func(T x, E y)"<<x<<" "<<y<<endl;
}


template <typename T>
void func(T x, T y)
{
    cout << "Inside func(T x, T y)---"<<x<<" "<<y<<endl;
}



int main()
{
    func(10,20);
    func(50,70);


    return 0;
}