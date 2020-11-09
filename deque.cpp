#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,i,j,k,L,R;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long dp[n][n][2];
	//dp[i][j][k] if ip starts with i index and ends at j index and turn is k's then what is x-y value
	//*base*//
	for(i=0;i<n;i++)
	{
		dp[i][i][0]=a[i];
		dp[i][i][1]=-1*a[i];
	}
	//*recuruence*//
	for(i=1;i<=n-1;i++)
	{
		for(j=0;j<=n-i-1;j++)
		{
			L=j;
			R=j+i;
			dp[L][R][0]=max(a[L]+dp[L+1][R][1],a[R]+dp[L][R-1][1]);
			dp[L][R][1]=min(dp[L+1][R][0]-a[L],dp[L][R-1][0]-a[R]);
		}
	}
	
	cout<<dp[0][n-1][0];
	return 0;
}


