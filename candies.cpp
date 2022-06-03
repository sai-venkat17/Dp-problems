#include<iostream>
#include<vector>
using namespace std;
int mod=1000000007;
int main()
{
	int i,j,n,k,temp,c;
	vector<int>a;
	cin>>n;
	
	cin>>k;
	for(i=0;i<n;i++)
	{
		cin>>temp;
		a.push_back(temp);
	}
	long long dp[n][k+1];
	for(i=0;i<n;i++)
	{
		for(j=0;j<k+1;j++)
		dp[i][j]=0;
	}
	
	//dp[i][j] indicates number of ways of sharing when we have childs upto i index and reamaining candies are j
	//number of candies are 0 only one way
	for(i=0;i<k+1;i++)
	{
		if(k-i>a[0])
		continue;
		dp[0][i]=1;
	}
	
	//number of childrens are only one or upto 0th index
	int u;
	for(i=1;i<n;i++)
	{
		for(j=1;j<k+1;j++)
		{
			dp[i-1][j]+=dp[i-1][j-1];
			if(dp[i-1][j]>=mod)
			dp[i-1][j]-=mod;
		}
		for(j=0;j<k+1;j++)
		{
		u=j+min(k-j,a[i]);
		dp[i][j]+=dp[i-1][u];
		if(dp[i][j]>=mod)
		dp[i][j]-=mod;	
			
			
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<k+1;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<dp[n-1][0];
	return 0;
}
