#include<iostream>
#include<vector>
using namespace std;
int n,m;
bool vis[100001];
vector<int> edges[100001];
int dfs(int start,int dp[])
{
	vis[start]=true;
	for(int i:edges[start])
	{
		if(vis[i]==false)
	    dp[i]=dfs(i,dp);
		dp[start]=max(dp[start],dp[i]+1);	
	}
	return dp[start];
	
};
int main()
{
	int i,j,a,b,ans=0;
	
	cin>>n;
	cin>>m;
	int dp[n+1];     // dp[i] gives longest path starting from that vertex
	for(i=0;i<m;i++)
	{
		cin>>a;
		cin>>b;
		edges[a].push_back(b);
	}
	for(i=0;i<n+1;i++)
	{
		vis[i]=false;
		dp[i]=0;
	}
	
	
	for(i=1;i<n+1;i++)
	{
		if(vis[i]==true)
		ans=max(ans,dp[i]);
		else
		{
		
		dp[i]=dfs(i,dp);
		ans=max(ans,dp[i]);
	}
	}
	cout<<ans;
	return 0;
}
