#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,K,cost[10'002],parent[10'002];
long long ans;
void init()
{
    for(int i=0;i<=N;i++) parent[i]=i;
}
int find(int a)
{
    if(parent[a]==a) return a;
    else return parent[a]=find(parent[a]);
}
void uni(int a,int b)
{
    a=find(a);
    b=find(b);
    if(cost[b]<cost[a]) parent[a]=b;
    else parent[b]=a;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M >> K;
    init();
    for(int i=1;i<=N;i++) cin>>cost[i];
    for(int i=0;i<M;i++)
    {
        int a,b; cin >>a >> b;
        uni(a,b);
    }

    for(int i=1;i<=N;i++)
    {
        if(find(0)==find(i))continue;
        ans += cost[find(i)];
        uni(0,i);
        
    }

    if(ans>K) cout <<"Oh no";
    else cout << ans;


}