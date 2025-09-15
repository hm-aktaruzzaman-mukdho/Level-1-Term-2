#include<iostream>
#include<stack>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    private:
    int vertexnumber;
    vector<int> *adjlist;
    bool *isVisited;
    int *parent;
    int *depth;

    void DFS_traversal(int startvertex)
    {
        int currvar=startvertex;
        isVisited[currvar]=true;
        for(int i=0;i<adjlist[currvar].size();i++)
        {
            if(!isVisited[adjlist[currvar].at(i)])
            {
                depth[adjlist[currvar].at(i)]=depth[currvar]+1;
                parent[adjlist[currvar].at(i)]=currvar;
                DFS_traversal(adjlist[currvar].at(i));
                
            }
            
        }
    }

    public:
    Graph(int vertexnumber)
    {
        this->vertexnumber=vertexnumber;
        adjlist = new vector<int>[vertexnumber+1];
        isVisited=new bool[vertexnumber+1];
        parent=new int[vertexnumber+1];
        depth=new int[vertexnumber+1];
        memset(isVisited,false,sizeof(bool)*(vertexnumber+1));
        memset(parent,-1,sizeof(int)*(vertexnumber+1));
        memset(depth,-1,sizeof(int)*(vertexnumber+1));
    }

    void addEdge(int u,int v)
    {
        
        adjlist[u].push_back(v);
    }

    void DFS(int startvertex)
    {
        int currver=startvertex;
        depth[currver]=0;
        DFS_traversal(currver);
    }

    int shortestpath(int vertex)
    {
        if(isVisited[vertex])
        {
            return depth[vertex];
        }
        else 
            return -1;
    }

    void printPath(int x)
    {
        if(!isVisited[x])
            return;
        if(depth[x]!=0)
            printPath(parent[x]);
        cout<<" "<<x;
    }
    // void print()
    // {
    //     cout<<endl;
    //     for(int i=1;i<=vertexnumber;i++)
    //     {
    //         cout<<depth[i]<<",";
    //     }
    // }
};

