#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
long long N,dp[100];
int main()
{
    cin >> N;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    for(int i=4;i<92;i++)
    {
        dp[i]++;
        for(int j=1;j<i-1;j++)
        {
            dp[i] += dp[j];            
        }
        
    }
    cout << dp[N];
}