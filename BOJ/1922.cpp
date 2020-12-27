#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1200
using namespace std;
int n,m,a,b,c,parent[1200],cnt;
vector<pair<int,pair<int,int>>> v;
void init()
{
    for(int i=0;i<=n;i++)
    parent[i]=i;
}
int find(int a)
{
    if(parent[a]==a) return a;
    else return parent[a] = find(parent[a]);
}
void uni(int a, int b)
{
    int root_a = find(a);
    int root_b = find(b);
    parent[root_a] = root_b;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    init();
    for(int i=0;i<m;i++)
    {
        cin >> a >> b >> c;
        v.push_back({c,{a,b}});
    }

    sort(v.begin(),v.end());

    int tot=0;
    for(int i=0;i<v.size();i++)
    {
        int a_,b_;  tie(a_,b_) = v[i].second;
        if(find(a_)!=find(b_))
        {
            tot += v[i].first;
            uni(a_,b_);
            ++cnt;
        }
        
        if(cnt==n-1)
        {
            cout << tot;
            break;
            
        }
    }
}