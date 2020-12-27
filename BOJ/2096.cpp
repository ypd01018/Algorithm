#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
int N,arr[3],dp[3],dp_mn[3],dp_tmp[3],dp_mn_tmp[3];
int main()
{
    cin >> N;
    cin >> dp[0] >> dp[1] >> dp[2];
    for(int i=0;i<3;i++)
    {
        dp_mn[i] = dp[i];
    }
    for(int i=1;i<N;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[j];
        }
    
        dp_tmp[0] = arr[0] + max(dp[0],dp[1]);
        dp_tmp[1]= arr[1] + max(max(dp[0],dp[1]),dp[2]);
        dp_tmp[2]= arr[2] + max(dp[1],dp[2]);   

        dp_mn_tmp[0] = arr[0] + min(dp_mn[0],dp_mn[1]);
        dp_mn_tmp[1]= arr[1] + min(min(dp_mn[0],dp_mn[1]),dp_mn[2]);
        dp_mn_tmp[2]= arr[2] + min(dp_mn[1],dp_mn[2]);   

        for(int j=0;j<3;j++)
        {
            dp[j]=dp_tmp[j];
            dp_mn[j]=dp_mn_tmp[j];
        }
    }
    int mx = max(max(dp[0],dp[1]),dp[2]);
    int mn = min(min(dp_mn[0],dp_mn[1]),dp_mn[2]);
    cout <<mx << " "<<mn;
}