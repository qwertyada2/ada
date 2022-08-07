#include<iostream>
using namespace std;
int min(int a,int b)
{
        if(a<b)
                return a;
        return b;
}
int main()
{
        int v;
        cout<<"Enter the number of vertices:-";
        cin>>v;
        int c[v][v],d[v][v],i,j,k;
        cout<<"Enter the cost matrix:-";
        for(i=0;i<v;i++)
                for(j=0;j<v;j++)
                {
                        cin>>c[i][j];
                        d[i][j]=c[i][j];
                }
        for(k=0;k<v;k++)
                for(j=0;j<v;j++)
                        for(i=0;i<v;i++)
                                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        cout<<"Distance matrix is\n";
        for(i=0;i<v;i++)
        {
                for(j=0;j<v;j++)
                        cout<<d[i][j]<<"\t";
                cout<<"\n";
        }
        return 0;
}



