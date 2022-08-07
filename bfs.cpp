#include<iostream>
using namespace std;
int v,G[9][9],selected[9],q[9],front=0,rear=-1;
void bfs(int ver)
{
    int t;
    selected[ver]=1;
    q[++rear]=ver;
    cout<<ver<<" ";
    if(front<=rear)
    {
        t=q[front++];
        for(int i=1;i<=v;i++)
            if(G[t][i]==1 && selected[i]==0)
            {
                q[++rear]=i;
                selected[i]=1;
                cout<<i<<" ";
            }
    }
}
int main()
{
    int i,j,ver;
    cout<<"Enter number of vertices:-";
    cin>>v;
    cout<<"Enter adjacency matrix:-";
    for(i=1;i<=v;i++)
        for(j=1;j<=v;j++)
            cin>>G[i][j];
    for(i=1;i<=v;i++)
        selected[i]=0;
    cout<<"Enter the vertex to begin:-";
    cin>>ver;
    bfs(ver);
    return 0;
}