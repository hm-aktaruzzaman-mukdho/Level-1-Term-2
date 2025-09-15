#include<iostream>
#include<cstdlib>
using namespace std;

template<class T>
class Stack{
    T *arrayofelements;
    int currentindex;
    int sizeofstack;

    Stack(int sizeofstack)
    {
        this->sizeofstack=sizeofstack;
        arrayofelements=new T[sizeofstack];
    }
};