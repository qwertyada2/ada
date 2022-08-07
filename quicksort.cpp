#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
int partition (int a[],int f,int l) {
int pivot=a[f];int i=f;int j=l,t;
while(i<j) {do 
{i++;}while(a[i]<=pivot);
do {j--;}while(a[j]>pivot);
if(i<j) 
{t=a[i];
a[i]=a[j];
a[j]=t;}}
t=a[f];
a[f]=a[j];
a[j]=t;return j;}
void quicksort(int a[],int f,int l) {
if(f<l) {int j=partition(a,f,l);
quicksort(a,f,j);
quicksort(a,j+1,l);
}
}
int main() {
int i,j,n=10000;
for(i=1;i<=100;i++)
{int a[n];for(j=0;j<n;j++)
a[j]=rand()%1000;
clock_t start=clock();
quicksort(a,0,n);clock_t end=clock();double t=(double)(end-start)/CLOCKS_PER_SEC;
cout<<n<<"\t"<<t<<"\n";
n=n+10000;}
return 0;
}
