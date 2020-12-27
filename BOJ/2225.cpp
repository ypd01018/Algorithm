#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int mod = 1'000'000'000;
int N,K,dp[202][202];
int main()
{
    cin >> N >> K;
    for(int i=0;i<=N;i++) dp[1][i]=1;

    for(int i=1;i<K;i++)
    {
        for(int j=0;j<=N;j++)
        {
            for(int k=0;(k+j)<=N;k++)
            {
                dp[i+1][k+j] += dp[i][j];
                dp[i+1][k+j] %= mod;
            }
        }
    }
    cout << dp[K][N];
}