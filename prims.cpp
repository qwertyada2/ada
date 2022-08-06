#include<iostream>
using namespace std;
int main()
{
    int v,sum=0;
    cout<<"Enter number of vertices:-";
    cin>>v;
    int G[v][v],no_of_edges=0,x,y,minn,selected[v];
    cout<<"Enter the adjacency matrix:-";
    for(int i=1;i<=v;i++)
        for(int j=1;j<=v;j++)
            cin>>G[i][j];
    for(int i=1;i<=v;i++)
        selected[i]=0;
    selected[1]=1;
    while(no_of_edges<v-1)
    {
        minn=999;
        x=0; y=0;
        for(int i=1;i<=v;i++)
        {
            if(selected[i]==1)
            {
                for(int j=1;j<=v;j++)
                {
                    if(selected[j]!=1 && G[i][j]!=0)
                    {
                        if(minn>G[i][j])
                        {
                            minn=G[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        sum+=minn;
        selected[y]=1;
        cout<<x<<" - "<<y<<" - "<<G[x][y]<<"\n";
        no_of_edges++;
    }    
    cout<<"Minimum cost is "<<sum;
    return 0;
}