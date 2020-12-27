#include<iostream>
#include<algorithm>
#include<math.h>
#define endl "\n"
#include<string>
using namespace std;
int n, m,dp[1500][1500],len,mx=0;
void test()
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string tmp; cin >> tmp;
		for (int j = 0; j < m; j++)
		{
			dp[i][j]=tmp[j]-'0';
			mx = max(mx, dp[i][j]);
			if (dp[i][j] == 1 && i!=0 && j!=0)
			{
				if (dp[i - 1][j - 1] == 0 || dp[i-1][j]==0 || dp[i][j-1]==0) continue;
				dp[i][j] = 1+min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]);
                mx = max(mx, dp[i][j]);
			}
			//test();
		}
	}

	cout << mx*mx;
}