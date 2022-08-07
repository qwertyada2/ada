#include<iostream>
using namespace std;
int v;
int select_min_vertex(bool selected[],int value[])
{
        int minn=999,vertex;
        for(int i=0;i<v;i++)
        {
                if(selected[i]==false && value[i]<=minn)
                {
                        minn=value[i];
                        vertex=i;
                }
        }
        return vertex;
}
int main()
{
        cout<<"Enter number of vertices:-";
        cin>>v;
        int i,j,u,G[v][v],value[v];
        bool selected[v];
        cout<<"Enter the adjacency matrix:-";
        for(i=0;i<v;i++)
                for(j=0;j<v;j++)
                        cin>>G[i][j];
        for(i=0;i<v;i++)
                selected[i]=false,value[i]=999;
        value[0]=0;
        //selected[0]=true;
        for(i=0;i<v-1;i++)
        {
                u=select_min_vertex(selected,value);
                selected[u]=true;
                for(j=0;j<v;j++)
                        if(selected[j]==false && G[u][j] && value[u]!=999 && value[u]+G[u][j]<value[j])
                                value[j]=value[u]+G[u][j];
        }
        cout<<"Vertex \tDistance from source\n";
        for(i=0;i<v;i++)
                cout<<i<<"\t"<<value[i]<<"\n";
        return 0;}

