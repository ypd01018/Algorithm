#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,root[1002];
vector<pair<int,pair<int,int>>> v;
void init()
{
    for(int i=1;i<=N;i++) root[i]=i;
}
int find(int a)
{
    if(root[a]==a) return a;
    else return root[a]=find(root[a]); 
}
void uni(int a,int b)
{
    a = find(a);
    b = find(b);
    root[b] = a;
}
int main()
{
    cin >> N >> M;
    init();
    for(int i=0;i<M;i++)
    {
        int a,b,c; cin >> a >> b >> c;
        v.push_back({c,{a,b}});
        v.push_back({c,{b,a}});
    }
    sort(v.begin(),v.end());
    int tot=0,cnt=0;
    for(int i=0;i<v.size();i++)
    {
        int c = v[i].first, a=v[i].second.first, b=v[i].second.second;
        if(find(a)!=find(b))
        {
            tot+=c;
            uni(a,b);
            cnt++;
        }
        if(cnt==N-1) break;
    }
    cout << tot;
}