#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class knapsack1{
	public:
		long long maxvalue(vector<int>&weights,vector<int>&values,int cap)
		{
			int n=weights.size(),i,j;
			long long dp[n+1][cap+1];
			//dp[i][j] is max value by considering i items are seen and capacity of knapsack is j
			
			for(i=0;i<n+1;i++)
			{
				for(j=0;j<cap+1;j++)
				{
					if(i==0 || j==0)
					dp[i][j]=0;
					else
					{
						if(weights[i-1]<=j)
						{
							dp[i][j]=max(values[i-1]+dp[i-1][j-weights[i-1]],dp[i-1][j]);
						}
						else
						{
							dp[i][j]=dp[i-1][j];
						}
					}
				}
			}
			return dp[n][cap];
		}
		private:
			long long max(long long a,long long b)
			{
				return (a>b)?a:b;
			}
		
		
};
int main()
{
	int n,i,j,temp,cap;
	vector<int> weights,values;
	cin>>n;
	cin>>cap;
	for(i=0;i<n;i++)
{
	cin>>temp;
	weights.push_back(temp);
	cin>>temp;
	values.push_back(temp);
}
knapsack1 taro;
cout<<taro.maxvalue(weights,values,cap);
	return 0;
}
