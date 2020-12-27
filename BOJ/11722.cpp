#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,arr[1002],dp[1002],mx=1;
int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
        dp[i]=1;
    }
    for(int i=1;i<N;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j]>arr[i]) 
            {
                dp[i]=max(dp[i],dp[j]+1);
                mx=max(dp[i],mx);
            }
        }
    }
    cout << mx;

    
}