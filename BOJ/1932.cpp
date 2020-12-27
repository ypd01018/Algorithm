#include<iostream>
#include<algorithm>
#include<math.h>
#define endl "\n"
using namespace std;
int n,mat[503][503],dp[503][503];
int mx = -1;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			cin >> mat[i][j];
		}
	}
	dp[0][0] = mat[0][0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			dp[i][j] += mat[i][j];
			if (j == 0) dp[i][j] += dp[i - 1][j];
			else if (j == i) dp[i][j] += dp[i - 1][j - 1];
			else dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
			mx = max(dp[i][j], mx);
		}
	}
	cout << mx;
}