#include<iostream>
//#include "BFSmap.cpp"
#include "DFSmap.cpp"

int main()
{
    FILE *fp1=freopen("in.txt","r",stdin);
    FILE *fp2=freopen("out.txt","w",stdout);
    int vertex,edge,u,v,s,d;
    cin>>vertex>>edge;
    Graph<int> g(vertex);
    for(int i=0;i<edge;i++)
    {
        cin>>u>>v;
        g.addEdge(u,v);
    }
    cin>>s>>d;
    g.DFS(s);
    cout<<g.shortestpath(d)<<endl;
    g.printPath(d);
    fclose(fp1);
    fclose(fp2);
    return 0;
}