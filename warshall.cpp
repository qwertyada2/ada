#include<iostream>
using namespace std;
int main()
{
        int v;
        cout<<"Enter the number of vertices:-";
        cin>>v;
        int c[v][v],i,j,k;
        cout<<"Enter the adjacency matrix:-";
        for(i=0;i<v;i++)
                for(j=0;j<v;j++)
                {
                        cin>>c[i][j];
                }
        for(k=0;k<v;k++)
                for(j=0;j<v;j++)
                        for(i=0;i<v;i++)
                                if(c[i][j] || c[i][k] && c[k][j]) c[i][j]=1;
        cout<<"Transitive closure matrix is\n";
        for(i=0;i<v;i++)
        {
                for(j=0;j<v;j++)
                        cout<<c[i][j]<<"\t";
                cout<<"\n";
        }
        return 0;
}




