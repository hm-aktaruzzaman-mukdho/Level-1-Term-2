#include<iostream>
using namespace std;

class A{
    int x;
    int y;
    public:
    A(int x,int y)
    {
        this->x=x;
        this->y=y;
    }

    void display()
    {
        cout<<"Value : "<<x<<", "<<y<<endl;
    }
};

int main()
{
    //int *array=new int[4]{1,2,3,4};
    int array[4]{1,2,3,4};
    for(int value:array)
    {
        cout<<value<<endl;
    }

    return 0;
}