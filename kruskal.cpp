#include<iostream>
using namespace std;
int parent[9];
int find(int i)
{
    while(parent[i])
         i=parent[i];
    return i;
}
int uni(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}
int main()
{
    int V;
    cout<<"Enter the number of vertices:-";
    cin>>V;
    int G[V][V],i,j,minn,ne=0,u,v,a,b,sum=0;
    cout<<"Enter the adjacency matrix:-";
    for(i=1;i<=V;i++)
        for(j=1;j<=V;j++)
        {    cin>>G[i][j];
             if(G[i][j]==0)
                G[i][j]=999;
        }
    while(ne<V-1)
    {
        for(i=1,minn=999;i<=V;i++)
            for(j=1;j<=V;j++)
                if(minn > G[i][j])
                {
                    minn=G[i][j];
                    a=u=i;
                    b=v=j;
                }
        u=find(u);
        v=find(v);
        if(uni(u,v))
        {
            cout<<"\n"<<a<<" - "<<b<<" : "<<minn<<"\n";
            ne++;
            sum=sum+minn;
        }
        G[a][b]=G[b][a]=999;
    }
    cout<<"Minimum cost is "<<sum;
    return 0;
}