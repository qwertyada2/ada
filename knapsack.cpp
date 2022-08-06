#include<iostream>
#include<stdlib.h>
using namespace std;
int max( int a,int b)
{
    if(a>b)
    return a;
    else
    return b;

}
int main()
{
    int n,m,i,j,w;
    cout<<"Enter the number of weights";
    cin>>n;
    cout<<"Enter the maximum size of bag";
    cin>>m;
    int p[n+1],wt[n+1],k[n+1][m+1];
    p[0]=0;wt[0]=0;
    cout<<"Enter the profits";
    for(i=1;i<=n;i++)
    cin>>p[i];
    cout<<"Enter the weights";
    for(i=1;i<=n;i++)
    cin>>wt[i];
    for(i=0;i<=n;i++)
         for(w=0;w<=m;w++)
        {
             if(i==0 || w==0)
                k[i][w]=0;
            else if(wt[i]<=w)
                k[i][w]=max(k[i-1][w],k[i-1][w-wt[i]]+p[i]);
            else
                 k[i][w]=k[i-1][w];
        }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
            cout<<k[i][j]<<"\t";
        cout<<"\n";
    }
    cout<<"the items that need to be picked are";
    i=n;j=m;
    while(i>0 && j>0)
    {
        if(k[i][j]==k[i-1][j])
        i--;
        else
        {
            cout<<i<<" ";
            j=j-p[i];
            i--;
        }
    }
    return 0;
}