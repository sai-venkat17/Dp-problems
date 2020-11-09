#include<iostream>
#include<vector>
using namespace std;
int other(int a)
{
	return (a==1)?0:1;
}
int main()
{
	int n,k,i,j,flags;
	cin>>n;
	cin>>k;
	vector<int> a;
	for(i=0;i<n;i++)
	{
		cin>>j;
		a.push_back(j);
	}
	int dp[k+1][2];
	//dp[i][j] who wins if i stones remains and its j turn
	dp[0][1]=0;
	dp[0][0]=1;
	//if 0 stone remains and chance is j's then other will win
	for(i=1;i<k+1;i++)
	{
		flags=0;
		for(j=0;j<n;j++)
		{
			
			if(i-a[j]<0)
			{
				dp[i][0]=1;
				flags=1;
				break;
			}
			if(dp[i-a[j]][1]==0)
			{
				dp[i][0]=0;
				flags=1;
				break;
			}
		
		}
		if(flags==0)
		dp[i][0]=1;
		
		flags=0;
		for(j=0;j<n;j++)
		{
			
			if(i-a[j]<0)
			{
				dp[i][1]=0;
				flags=1;
				break;
			}
			if(dp[i-a[j]][1]==0)
			{
				dp[i][1]=1;
				flags=1;
				break;
			}
		
		}
		if(flags==0)
		dp[i][1]=0;
		
		
	}
	if(dp[k][0]==0)
	cout<<"First";
	else
	cout<<"Second";
	return 0;
}
