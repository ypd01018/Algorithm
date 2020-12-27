#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
ll dp[14][2003],T,N,M;
void go()
{
    for(int i=1;i<N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            for(int k=0;(k+j*2)<=M;k++)
            {
                dp[i+1][k+j*2] += dp[i][j];
            }
        }
    }

    ll ans=0;
    for(int i=1;i<=M;i++) ans+=dp[N][i];
    cout << ans << endl;
}
void sol()
{
    cin >> N >> M;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=M;i++) dp[1][i]=1;
    go();
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> T;   
    for(int i=0;i<T;i++) 
    {   
        sol();
    }
}