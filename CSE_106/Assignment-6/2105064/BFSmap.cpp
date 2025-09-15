#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

template<typename K>
class Graph
{
private:
    int verticesnumber;
    map<K,vector<K>> adjacencylist;
    map<K,bool> isVisited;//automatically initialized with false.
    map<K,int> depth;
    map<K,K> parent;
public:
    Graph(int verticesnumber)
    {
        this->verticesnumber = verticesnumber;
    }

    void addEdge(int u, int v)
    {
        adjacencylist[u].push_back(v);
        // adjacencylist[v].push_back(u);
    }

    void BFS(int startVertex)
    {
        int currvertex;
        queue<K> q;
        q.push(startVertex);
        isVisited[startVertex] = true;
        depth[startVertex] = 0;
        while (!q.empty())
        {
            currvertex = q.front();
            q.pop();
            for (K x:adjacencylist[currvertex])
            {
                if (!isVisited[x])
                {
                    isVisited[x] = true;
                    depth[x] = depth[currvertex] + 1;
                    parent[x] = currvertex;
                    q.push(x);
                }
            }
        }
    }

    int shortestpath(K vertex)
    {
        if (isVisited[vertex])
        {
            return depth[vertex];
        }
        else
            return -1;
    }

    void printPath(K x)
    {
        if (!isVisited[x])
            return;
        if (depth[x] != 0)
            printPath(parent[x]);
        cout << " " << x;
    }
};