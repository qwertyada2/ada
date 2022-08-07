#include<iostream>
using namespace std;
int G[9][9],selected[9],n,cost_opt=0,cost_apt=0;
int least_apt(int ver)
{
	int kmin=999,min_vertex=999;
	for(int i=1;i<=n;i++)
		if(G[ver][i]<kmin && selected[i]==0)
		{
			kmin=G[ver][i];
			min_vertex=i;
		}
	if(kmin!=999)
		cost_apt+=kmin;
	return min_vertex;
}
int least_opt(int ver)
{
	int kmin=999,minn=999,min_vertex=999;
	for(int i=1;i<=n;i++)
		if(G[ver][i]<minn && selected[i]==0)
		{
			minn=G[ver][i]+G[i][1];
			kmin=G[ver][i];
			min_vertex=i;
		}
	if(kmin!=999)
		cost_opt+=kmin;
	return min_vertex;
}
void mincost_apt(int ver)
{
	selected[ver]=1;
	cout<<ver<<"\t";
	int ncity=least_apt(ver);
	if(ncity==999)
	{
		cost_apt+=G[ver][1];
		cout<<"1\n";
	}
	else
		mincost_apt(ncity);
}
void mincost_opt(int ver)
{
	selected[ver]=1;
	cout<<ver<<"\t";
	int ncity=least_opt(ver);
	if(ncity==999)
	{
		cost_opt+=G[ver][1];
		cout<<"1\n";
	}
	else
		mincost_opt(ncity);
}
int main()
{
	int ver;
	cout<<"Enter number of vertices:-";
	cin>>n;
	cout<<"Enter cost matrix:-";
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>G[i][j];
	for(int i=1;i<=n;i++)
		selected[i]=0;
	cout<<"Path from approximate solution is\n";
	mincost_apt(1);
	cout<<"Cost from approximate solution is "<<cost_apt<<"\n";
	for(int i=1;i<=n;i++)
		selected[i]=0;
	cout<<"Path from optimal solution is\n";
	mincost_opt(1);
	cout<<"Cost from optimal solution is "<<cost_opt<<"\n";
	cout<<"Error is "<<(float)cost_apt/cost_opt;
	return 0;
}