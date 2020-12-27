#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int T;
long long dp[103];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    dp[1]=dp[2]=dp[3]=1;
    for(int i=4;i<101;i++)
    {
        dp[i]=dp[i-2]+dp[i-3];
    }
    cin >> T;
    for(int i=0;i<T;i++)
    {
        int input;
        cin >> input;
        cout << dp[input] << endl;
    }
}