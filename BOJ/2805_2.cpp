#include<bits/stdc++.h>
#define endl "\n"
#define ll long long 
using namespace std;
const int limit = 1'000'000'000;
ll N,M,tree[1'000'003],ans,mx;
void binary(int s, int e,ll pre_mid)
{
    ll mid = (s+e)/2;
    if(mid == pre_mid) return;
    ll total = 0;
    for(ll i=0;i<N;i++)
    {
        ll len=mid-tree[i];
        if(mid-tree[i]>=0) continue;
        total += (-1*len);
    }
    if(total >= M) 
    {
        mx = max(mid,mx);
        binary(mid+1,e,mid);
    }
    else  binary(s,mid-1,mid);
    
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        cin >> tree[i];
    }
    binary(0,limit,limit);
    cout << mx;

}