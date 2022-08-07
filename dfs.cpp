#include<iostream>
using namespace std;
int v,G[9][9],visited[9],q[9],front=-1,rear=-1;
int dfs(int ver)
{
    visited[ver]=1;
    for(int i=1;i<=v;i++)
        if(visited[i]==0 && G[ver][i]!=0)
            dfs(i);
    for(int i=1;i<=v;i++)
        if(visited[i]==0)
            return 0;
    return 1;
}
int main()
{   
    int i,j,ver,f;
    cout<<"Enter number of vertices:-";
    cin>>v;
    cout<<"Enter adjacency matrix:-";
    for(i=1;i<=v;i++)
        for(j=1;j<=v;j++)
            cin>>G[i][j];
    for(i=1;i<=v;i++)
        visited[i]=0;
    cout<<"Enter the vertex to begin:-";
    cin>>ver;
    f=dfs(ver); 
    if(f==1)
        cout<<"Graph is connected";
    else
        cout<<"Graph is not connected";
    return 0;
}