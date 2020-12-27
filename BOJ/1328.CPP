#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const ll mod = 1'000'000'007;
ll N,L,R,dp[101][101][101];
ll go(int num,int lft,int rght)
{
    if((num==rght && lft==1)||(num==lft && rght ==1)) return 1;
    if(!num || !lft || !rght) return 0;
    ll &ret = dp[num][lft][rght];
    if(ret!=-1) return ret;
    ret = 0;
    ret = ((go(num-1,lft,rght)*(num-2))+go(num-1,lft-1,rght)+go(num-1,lft,rght-1))%mod;
    return ret;
}
int main()
{   
    memset(dp,-1,sizeof(dp));
    cin >> N >> L >> R;
    cout << go(N,L,R)%mod;  
}