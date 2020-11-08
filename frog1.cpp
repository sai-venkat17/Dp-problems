//problem link
// https://atcoder.jp/contests/dp/tasks/dp_a
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int solve(vector<int>&stones)
{
	int n,i,j;
	n=stones.size();
	if(n==0)
	return 0;
	int dp[n];
	dp[0]=0;
	dp[1]=abs(stones[0]-stones[1]);
	for(i=2;i<n;i++)
	{
		dp[i]=min(dp[i-1]+abs(stones[i-1]-stones[i]),dp[i-2]+abs(stones[i-2]-stones[i]));
	}
	return dp[n-1];
};
int main()
{
	int n,i,j,temp;
	vector<int>stones;
	cin>>n;
	int dp[n];
	for(i=0;i<n;i++)
	{
		cin>>temp;
		stones.push_back(temp);
	}
	cout<<solve(stones);
	return 0;
}
