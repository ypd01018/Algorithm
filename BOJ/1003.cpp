#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int T,dp[42][2];
int main()
{
    cin >> T;
    dp[0][0] = 1;
    dp[1][1] = 1;
    for(int i=2;i<42;i++)
    {
        for(int j=0;j<2;j++)
        dp[i][j]=dp[i-1][j] + dp[i-2][j];
    } 

    for(int i=0;i<T;i++)
    {
        int tmp; cin >> tmp;
        cout << dp[tmp][0] << " " << dp[tmp][1] << endl;
    }
}