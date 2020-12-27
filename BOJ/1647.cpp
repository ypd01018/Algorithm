#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,root[100'010];
vector<pair<int,pair<int,int>>> v;
void init()
{
    for(int i=1;i<=N;i++)
    {
        root[i]=i;
    }
}
int find(int a)
{
    if(a==root[a]) return a;
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    init();
    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v.push_back({c,{a,b}});
    }

    sort(v.begin(),v.end());

    int tot=0,cnt=0,mx=-1;

    for(int i=0;i<v.size();i++)
    {
        pair<int,int> ab; ab=v[i].second;
        if(find(ab.first) != find(ab.second))
        {
            tot += v[i].first;
            mx = max(v[i].first,mx);
            uni(ab.first,ab.second);
            ++cnt;
        }

        if(cnt == N-1)
        {
            break;
        }
    }

    cout << tot-mx;

}