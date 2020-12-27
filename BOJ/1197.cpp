#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int v,e,parent[15010],depth[15010];
vector<pair<int,pair<int,int>>> vec;

void init()
{
    for(int i=1;i<=v;i++)
    {
        parent[i]=i;
    }
}
int find(int a)
{
    if(parent[a]==a) return a;
    else return parent[a] = find(parent[a]);
}
void uni(int a, int b)
{
    a = parent[a];
    b = parent[b];

    if(a == b) return;

    if(depth[a] < depth[b]) parent[a]=b;
    else parent[b]=a;

    if(depth[a]==depth[b]) depth[a]++;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> v >> e;
    init();
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        vec.push_back({c,{a,b}});
    }
    
    sort(vec.begin(),vec.end());
    
    int tot=0,cnt=0;

    for(int i=0;i<vec.size();i++)
    {
        int a_,b_;  tie(a_,b_) = vec[i].second;
        if(find(a_)!=find(b_))
        {
            tot += vec[i].first;
            uni(a_,b_);
            ++cnt;
        }
        
        if(cnt==v-1)
        {
            cout << tot;
            break;
            
        }
    }
}