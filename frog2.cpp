
#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;
class frog2{
	public:
		int min_cost(vector<int>&stones,int k)
		{
			int n=stones.size(),dp[n],i,j,ans;
			if(n==1)
			return 0;
			//dp[i] min cost to go to ith stone
			dp[0]=0;
			for(i=1;i<n;i++)
			{
				ans=INT_MAX;
				for(j=i-1;j>=i-k;j--)
				{
					if(j<0)
					break;
					ans=min(ans,dp[j]+abs(stones[j]-stones[i]));
				}
				dp[i]=ans;
			}
			return dp[n-1];
		}
};
int main()
{
	int n,k,i,temp;
	vector<int>stones;
	cin>>n;
	cin>>k;
	for(i=0;i<n;i++)
	{
		cin>>temp;
		stones.push_back(temp);
	}
	frog2 frog;
	cout<<frog.min_cost(stones,k);
	return 0;
}
