#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,arr[1002],dp[1002];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    dp[1]=arr[1];
    for(int i=2;i<=n;i++)
    {
        dp[i]=arr[i];
        for(int j=1;j<=i/2;j++)
        {
            dp[i]=max(dp[i],dp[j]+dp[i-j]);       
        }
    }
    cout << dp[n];
}