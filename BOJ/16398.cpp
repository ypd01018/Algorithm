#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int  N,root[1002];
vector<pair<int,pair<int,int>>> v;
int find(int a)
{
    if(root[a]==a) return a;
    else return root[a] = find(root[a]);
}
void uni(int a, int b)
{
    a = find(a);
    b = find(b);
    root[b] = a;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=0;i<=N;i++) root[i]=i;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            int a; cin >> a;
            if(i==j) continue;
            v.push_back({a,{i,j}});
            v.push_back({a,{j,i}});
        }
    }
    sort(v.begin(),v.end());
    ll ans = 0 , cnt = 0;
    for(int i=0;i<v.size();i++)
    {
        int a = v[i].second.first, b = v[i].second.second,d = v[i].first;
        if(find(a)==find(b)) continue;
        ans+=(ll)d;
        uni(a,b);
        cnt++;
        if(cnt==N-1) break;
    }
    cout << ans ;
}