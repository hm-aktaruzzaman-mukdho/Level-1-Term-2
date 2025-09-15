#include<iostream>
#include<stack>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
    private:
    int vertexnumber;
    //vector<int> *adjlist;
    map<T,vector<T>> adjlist;
    map<T,bool> isVisited;
    map<T,T> parent;
    map<T,int> depth;

    void DFS_traversal(T startvertex)
    {
        T currvar=startvertex;
        isVisited[currvar]=true;
        for(T var:adjlist[currvar])
        {
            if(!isVisited[var])
            {
                depth[var]=depth[currvar]+1;
                parent[var]=currvar;
                DFS_traversal(var);
                
            }
            
        }
    }

    public:
    Graph(int vertexnumber)
    {
        
    }

    void addEdge(T u,T v)
    {
        
        adjlist[u].push_back(v);
    }

    void DFS(T startvertex)
    {
        T currver=startvertex;
        depth[currver]=0;
        DFS_traversal(currver);
    }

    int shortestpath(T vertex)
    {
        if(isVisited[vertex])
        {
            return depth[vertex];
        }
        else 
            return -1;
    }

    void printPath(T x)
    {
        if(!isVisited[x])
            return;
        if(depth[x]!=0)
            printPath(parent[x]);
        cout<<" "<<x;
    }
};

