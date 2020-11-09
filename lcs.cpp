#include<iostream>
#include<vector>
#include<cstring>
#include<utility>
using namespace std;
class lcs{
	public:
		string lcs_fun(string s1,string s2)
		{
			int i,j,n=s1.size(),m=s2.size(),ans_len=0,ans1=0,ans2=0;
			pair<int, pair<int,int> > dp[n+1][m+1];
			
			//dp[i][j] lcs when len of first is i and second is j
			
			if(n==0 || m==0)
			return "";
			//////////
			for(i=0;i<m+1;i++)
			{
				dp[0][i].first=0;
			}
			for(i=0;i<n+1;i++)
			{
				dp[i][0].first=0;
			}
			for(i=1;i<n+1;i++)
			{
				for(j=1;j<m+1;j++)
				{
					if(s1[i-1]==s2[j-1])
					{
						dp[i][j].first=dp[i-1][j-1].first+1;
						dp[i][j].second=make_pair(i-1,j-1);
					}
					else
					{
						if(dp[i-1][j]>dp[i][j-1])
						{
							dp[i][j].first=dp[i-1][j].first;
							dp[i][j].second=make_pair(i-1,j);
						}
						else
						{
							dp[i][j].first=dp[i][j-1].first;
							dp[i][j].second=make_pair(i,j-1);
						}
					}
					if(dp[i][j].first>ans_len)
					{
						ans_len=dp[i][j].first;
						ans1=i;
						ans2=j;
						
					}
				}
			}
			pair<int,int>cur=make_pair(ans1,ans2);
			pair<int,int>prev;
			string semif_ans="";
			while(cur.first!=0 && cur.second!=0)
			{
				i=cur.first;
				j=cur.second;
				prev=dp[i][j].second;
			     if(prev==make_pair(i-1,j-1))
			     {
			     	
			     	semif_ans=s1[i-1]+semif_ans;
				 }
				cur=prev;
			}
		//cout<<ans_len<<endl;
			return semif_ans;
			
		}
};
int main()
{
	string s1,s2;
	cin>>s1;
	cin>>s2;
	lcs sub;
	cout<<sub.lcs_fun(s2,s1);
	return 0;
}
