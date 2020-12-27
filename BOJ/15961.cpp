#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,d,k,c,arr[3'000'002],mx=0,n_num[3002],cnt;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> d >> k >> c;
    for(int i=0;i<N;++i) cin >> arr[i];
    for(int i=0;i<k;++i)
    {
        if(!n_num[arr[i]]) ++cnt;
        ++n_num[arr[i]];
    }
    if(n_num[c]==0) mx = cnt+1;
    else mx = cnt;
    for(int i=0;i<N-1;++i)
    {
        int start = i, end = i+k;
        if(end>=N) end -= N;
        if(!(--n_num[arr[start]])) --cnt;
        if(!(n_num[arr[end]]++)) ++cnt;
        if(!n_num[c]) mx = max(cnt+1,mx);
        else mx = max(cnt,mx);
    }
    cout << mx;
    
}