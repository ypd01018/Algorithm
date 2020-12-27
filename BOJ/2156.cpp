#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
long long n,arr[10'003],dp[10'003];
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i];
    }
    dp[1] = arr[1];
    dp[2] = arr[1]+arr[2];
    for(int i=3;i<=n;i++)
    {
        dp[i] = max(dp[i-3] + arr[i] + arr[i-1],dp[i-2]+arr[i]);
        dp[i] = max(dp[i],dp[i-1]);

    }
    cout << *max_element(dp,dp+n+1);
}