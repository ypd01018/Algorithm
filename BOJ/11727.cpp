#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int mod = 10007;
int n,dp[1003];
int main()
{
    dp[1]=1;
    dp[2]=3;
    cin >> n;
    for(int i=3;i<=n;i++)
    {
        dp[i]=(2*dp[i-2]+dp[i-1])%mod;
        
    }
    cout << dp[n];
}