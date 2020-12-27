#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int dp[100'002],n;
int main()
{
    cin >> n;

    for(int i=0;i<=100'000;i++) 
    {
        dp[i]=i;    
    }
    
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j*j<=i;j++)
        {
            dp[i] = min(dp[i],dp[i-j*j]+1);
        } 
    }
    cout << dp[n];
}