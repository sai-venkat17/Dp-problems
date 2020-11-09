#include<iostream>
using namespace std;
int main()
{
	int i,j,n;
	cin>>n;
	double p[n],dp[n+1][n+1],pt;
	//dp[i][j] probability of having j heads when considered are i coins
	
	for(i=0;i<n;i++)
	cin>>p[i];
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<n+1;j++)
		dp[i][j]=0;
	}
	dp[0][0]=1;
	//col 1 filling
	for(i=1;i<n+1;i++)
	{
		pt=1-p[i-1];
		dp[i][0]=dp[i-1][0]*pt;
	}
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<i+1;j++)
		{
			dp[i][j]=dp[i-1][j-1]*p[i-1]+dp[i-1][j]*((float)1-p[i-1]);
		}
	}
	double ans=0;
	for(i=0;i<n+1;i++)
	{
		if(i<=n-i)
		continue;
		else
		ans+=dp[n][i];
	}
	printf("%.99f\n",ans);
	return 0;
}
