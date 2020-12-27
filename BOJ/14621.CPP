#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,sex[1002],root[1002];
vector<pair<int,pair<int,int>>> v;
void init()
{
    for(int i=1;i<=N;i++) root[i]=i;
}
int find(int a)
{
    if(a==root[a]) return a;
    else return root[a]=find(root[a]);
}
void uni(int a, int b)
{
    a=find(a);
    b=find(b);
    root[b]=a;
}
int main()
{
    cin >> N >> M;
    init();
    for(int i=1;i<=N;i++)
    {
        char input; cin >> input;
        if(input=='M') sex[i]=1;
    }

    for(int i=0;i<M;i++)
    {
        int a,b,c; cin >> a >> b >> c;
        if(sex[a]==sex[b]) continue;
        v.push_back({c,{a,b}});
    }

    sort(v.begin(),v.end());


    int tot=0,cnt=0;
    for(int i=0;i<v.size();i++)
    {
        int a = v[i].second.first, b=v[i].second.second,c=v[i].first;
        if(find(a)==find(b)) continue;
        tot += c;
        uni(a,b);
        //cout << a << ',' << b << ':'<< c<<  endl;
        if(++cnt==N-1) break;
    }
    if(!tot || cnt!=N-1) cout << -1;   
    else cout << tot;

}