#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
int N;
long long dp[100];
int main()
{
    dp[0]=1; dp[1]=1;
    cin >> N;
    for(int i=2;i<=N;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout << dp[N-1];
}