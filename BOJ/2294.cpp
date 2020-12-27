#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,K,arr[102],dp[10002];
void go()
{
    queue<pair<int,int>> q; 
    for(int i=0;i<N;i++)
    {
        if(arr[i]<=K && dp[arr[i]]==INT_MAX) 
        {
            q.push({arr[i],1});
            dp[arr[i]]=1;
        }
    }
    while(!q.empty())
    {
        int total=q.front().first,n=q.front().second; q.pop();
        //cout << total << ',' << n << endl;
        for(int i=0;i<N;i++)
        {
            if(total+arr[i]>K || dp[total+arr[i]]!=INT_MAX) continue;
            dp[total+arr[i]] = n+1;
            q.push({total+arr[i],n+1});
        }
    }
}
int main()
{
    cin >> N >>K;
    for(int i=0;i<N;i++) cin >> arr[i];
    for(int i=0;i<=K;i++) dp[i]=INT_MAX;    
    go();
    //for(int i=1;i<=K;i++) cout << i << ':' << dp[i] << endl;
    if(dp[K]==INT_MAX) cout << -1;
    else cout << dp[K];
}