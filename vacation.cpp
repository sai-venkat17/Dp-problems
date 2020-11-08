//link https://atcoder.jp/contests/dp/tasks/dp_c
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class vacation{
	public:
		int maxhappy(vector<vector<int> >& nums)
		{
			int i,j,k,n=nums.size(),dp[n][3],cur_ans=0;
			if(n==1)
			return max(nums[0][0],max(nums[0][1],nums[0][2]));
			//dp[i][j] max happy upto i where last choosen is j
			dp[0][0]=nums[0][0];
			dp[0][1]=nums[0][1];
			dp[0][2]=nums[0][2];
			for(i=1;i<n;i++)
			{
				for(j=0;j<3;j++)
				{
					cur_ans=0;
					for(k=0;k<3;k++)
					{
						
						if(k==j)
						continue;
						cur_ans=max(dp[i-1][k],cur_ans);
					}
					dp[i][j]=cur_ans+nums[i][j];
				}
			}
			return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
		}
};
int main()
{
	int i,j,n,temp;
	vector<int>temp2;
	temp2.push_back(0);
	temp2.push_back(0);
	temp2.push_back(0);
	vector<vector<int> >nums;
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>temp2[j];
			
		}
	nums.push_back(temp2);	
	}
	vacation taro;
	cout<<taro.maxhappy(nums);
	return 0;
}
