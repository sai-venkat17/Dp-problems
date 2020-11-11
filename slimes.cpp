#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;
long long mem[405][405];
long long psum(int i,int j,long long b[])
{
	if(i==0)
	return b[j];
	return b[j]-b[i-1];
};

long long min_cost(long long a[],long long b[],int start,int end)
{
	if(start==end)
	{mem[start][end]=0;
	return 0;}
	else if(end-start==1)
	{mem[start][end]=a[start]+a[end];
	return a[start]+a[end];}
	long long ans=INFINITY;
	for(int i=start;i<end;i++)
	{
		if(mem[start][i]==-1)
		mem[start][i]=min_cost(a,b,start,i);
		if(mem[i+1][end]==-1)
		mem[i+1][end]=min_cost(a,b,i+1,end);
		
		ans=min(ans,mem[start][i]+mem[i+1][end]+psum(start,end,b));
	}
	return ans;
};
int main()
{
int n,i,j,l,r;
cin>>n;
long long a[n];
long long b[n];
for(i=0;i<n;i++)
{
	cin>>a[i];
	if(i==0)
	b[i]=a[i];
	else
	b[i]=a[i]+b[i-1];
}

for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	mem[i][j]=-1;
}
cout<<min_cost(a,b,0,n-1);
	return 0;
}
