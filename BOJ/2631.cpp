#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,arr[202],dp[202];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
    }
    dp[0]=1;
    
    for(int i=1;i<N;i++)
    {
        dp[i]=1;
        for(int j=i;j>-1;j--)
        {
            if(arr[j]<arr[i] && dp[j]>dp[i]-1)
            {
                dp[i]=dp[j]+1;
            }
        }
    }

    cout << N - *max_element(dp,dp+N);

}