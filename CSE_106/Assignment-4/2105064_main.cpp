#include<iostream>
#include<cstring>
#include "2105064_BST.cpp"
using namespace std;

int main()
{
    FILE *fptr=fopen("in.txt","r");
    char str[20];
    BST<int> tree;
    while(!feof(fptr))
    {
        fgets(str,20,fptr);
        char ch;
        char s1[20];
        int x;
        
        sscanf(str,"%c%s",&ch,s1);
        if(ch=='I')
        {
            tree.Insert(stoi(s1));
            tree.printsubtree();
        }
        if(ch=='F')
        {
            tree.Find(stoi(s1));
        }
        if(ch=='D')
        {
            tree.Delete(stoi(s1));
            tree.printsubtree();
        }
        if(ch=='T')
        {
            if(strcmp(s1,"In")==0)
            {
                tree.InorderTraverse();
            }
            else if(strcmp(s1,"Pre")==0)
            {
                tree.PreorderTraverse();
            }
            else if(strcmp(s1,"Post")==0)
            {
                tree.PostorderTraverse();
            }
        }
    }

    return 0;
}

