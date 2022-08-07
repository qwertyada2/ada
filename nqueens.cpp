#include<iostream>
#include<math.h>
using namespace std;
int a[10],count=1;
int place(int pos)
{
    for(int i=1;i<pos;i++)
        if(a[i]==a[pos] || (abs(a[i]-a[pos])==abs(i-pos)))
            return 0;
    return 1;
}
void print_sol(int n)
{
    cout<<"\nSolution "<<count++<<"\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==j)
                cout<<"Q\t";
            else
                cout<<"*\t";
        }
        cout<<"\n";
    }
}
void queen(int n)
{
    int k=1;
    a[k]=0;
     if(n==0 || n==2 || n==3)
        cout<<"No Solution";
    while(k!=0)
    {   
        do
        {
            a[k]++;
        }while(a[k]<=n && !place(k));
        if(a[k]<=n)
        {
            if(k==n)
                print_sol(n);
            else
            {
                k++;
                a[k]=0;
            }
        }
        else
            k--;
    }
}
int main()
{
    int n;
    cout<<"Enter number of queens:-";
    cin>>n;
    queen(n);
    return 0;
}