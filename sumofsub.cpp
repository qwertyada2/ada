#include<iostream>
using namespace std;
int w[100],m,x[100];
void sumofsub(int s,int k,int r)
{
    int f=0;
    x[k]=1;
    static int b=1;
    if(s+w[k]==m)
    {
        cout<<"\n subset "<<b++<<"\n";
        for(int i=1;i<=k;i++)
            if(x[i]==1)
            cout<<w[i]<<"\t";

    }
    else if(s+w[k]+w[k+1]<=m)
        sumofsub(s+w[k],k+1,r-w[k]);
    if((s+r-w[k]>=m)&&(s+w[k+1]<=m))
        {
            x[k]=0;
            sumofsub(s,k+1,r-w[k]);
        }
    
}
int main()
{
    int n,s=0;
    cout<<"Enter the number of weights";
    cin>>n;
    cout<<"Enter the maximum weight";
    cin>>m;
    cout<<"Enter the weights";
    for(int i=1;i<=n;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
        s=s+w[i];
    sumofsub(0,1,s);
    return 0;
}
