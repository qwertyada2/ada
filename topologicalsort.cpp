#include<iostream>
using namespace std;
int main()
{
     int v;
    cout<<"Enter number of vertices:-";
     cin>>v;
    int G[v][v],i,j,k,indegree[v],flag[v],n=0;
    cout<<"Enter the adjacency matrix:-";
    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
             cin>>G[i][j];
    for(i=0;i<v;i++)
        indegree[i]=0, flag[i]=0;
    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
             indegree[i]=indegree[i]+G[j][i];
    cout<<"Topological sort is\n";
    while(n<v)
    {
        for(i=0;i<v;i++)
        {
             if(indegree[i]==0 && flag[i]==0)
             {       
                cout<<i+1<<" ";
                flag[i]=1;
             }
             for(j=0;j<v;j++)
             {
               if(G[j][i]==1)
                 indegree[i]--;
		    }
        }
        n++;
    } return 0;
}
