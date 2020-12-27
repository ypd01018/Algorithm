#include<bits/stdc++.h>
#define endl "\n"
#define mod 1000000000
using namespace std;
int n;
long long dp[102][11];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i=1;i<=9;i++) dp[1][i]=1;

    for(int i=2;i<=n;i++)
    {
        dp[i][0]=dp[i-1][1];
        for(int j=1;j<9;j++)
        {
            dp[i][j]=(dp[i-1][j-1] + dp[i-1][j+1])%mod;
        }
        
        dp[i][9]=dp[i-1][8]%mod;
    }
    long long tot=0;
    for(int i=0;i<=9;i++)
    tot += dp[n][i];
    cout << tot%mod;
}