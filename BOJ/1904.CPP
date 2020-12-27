#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,dp[1'000'010],mod=15746;
int main()
{
    cin >> N;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(int i=3;i<=N;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
        dp[i]%=15746;
    }
    cout << dp[N];

}