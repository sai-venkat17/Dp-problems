#include<iostream>
using namespace std;
int mod=1000000007;
int main()
{
	int r,c,i,j;
	
	cin>>r;
	cin>>c;
	int dp[r][c];
	//dp[i][j] indicates number of paths to ij from starting
	dp[0][0]=0;
	char grid[r][c];
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cin>>grid[i][j];
			dp[i][j]=0;
		}
	}
	//1 row filling
	int flags=0;
	for(i=1;i<c;i++)
	{
		if(grid[0][i]=='#')
		{
			flags=1;
		}
		if(flags==0)
		{
			dp[0][i]=1;
		}
		else
		{
			dp[0][i]=0;
		}
	}
	//1 col filling
	flags=0;
	for(i=1;i<r;i++)
	{
		if(grid[i][0]=='#')
		{
			flags=1;
		}
		if(flags==0)
		{
			dp[i][0]=1;
		}
		else
		{
			dp[i][0]=0;
		}
	}
	//other fillings
	for(i=1;i<r;i++)
	{
		for(j=1;j<c;j++)
		{
			if(grid[i][j]=='#')
			continue;
			if(grid[i-1][j]!='#')
			dp[i][j]+=(dp[i-1][j]);
			if(grid[i][j-1]!='#')
			dp[i][j]+=(dp[i][j-1]);
			if(dp[i][j]>=mod)
			dp[i][j]-=mod;
		}
	}
/*for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		cout<<dp[i][j]<<" ";
		cout<<endl;
	}*/
	cout<<dp[r-1][c-1];
	return 0;
}
