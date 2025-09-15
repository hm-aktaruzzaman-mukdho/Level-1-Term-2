#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

// template<typename T>
class Graph
{
private:
    int verticesnumber;
    bool *isVisited;
    vector<int> *adjacencylist;
    int *parent;
    int *depth;

public:
    Graph(int verticesnumber)
    {
        this->verticesnumber = verticesnumber;
        adjacencylist = new vector<int>[verticesnumber + 1];
        parent = new int[verticesnumber + 1];
        depth = new int[verticesnumber + 1];
    }

    void addEdge(int u, int v)
    {
        adjacencylist[u].push_back(v);
        // adjacencylist[v].push_back(u);
    }

    void BFS(int startVertex)
    {
        int currvertex;
        isVisited = new bool[verticesnumber + 1];
        // for (int i = 0; i <= verticesnumber; i++)
        // {
        //     isVisited[i] = false;
        // }
        queue<int> q;
        memset(isVisited, false, sizeof(bool) * (verticesnumber + 1));
        memset(parent, -1, sizeof(int) * (verticesnumber + 1));
        memset(depth, -1, sizeof(int) * (verticesnumber + 1));

        q.push(startVertex);
        isVisited[startVertex] = true;
        depth[startVertex] = 0;
        while (!q.empty())
        {
            currvertex = q.front();
            q.pop();
            for (int i = 0; i < adjacencylist[currvertex].size(); i++)
            {
                if (!this->isVisited[adjacencylist[currvertex].at(i)])
                {
                    isVisited[adjacencylist[currvertex].at(i)] = true;
                    depth[adjacencylist[currvertex].at(i)] = depth[currvertex] + 1;
                    parent[adjacencylist[currvertex].at(i)] = currvertex;
                    q.push(adjacencylist[currvertex].at(i));
                }
            }
        }
    }

    int shortestpath(int vertex)
    {
        if (isVisited[vertex])
        {
            return depth[vertex];
        }
        else
            return -1;
    }

    void printPath(int x)
    {
        if (!isVisited[x])
            return;
        if (depth[x] != 0)
            printPath(parent[x]);
        cout << " " << x;
    }
};