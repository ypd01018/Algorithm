#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,visit[10002],mx,s,e,start_node,end_node;
vector<pair<int,int>> v[10002];
bool BFS(int w)
{
    queue<int> q;
    q.push(start_node);
    while(!q.empty())
    {
        int from = q.front(); q.pop();
        for(int i=0;i<v[from].size();i++)
        {
            int to = v[from][i].first, weight = v[from][i].second;
            if(visit[to] || weight<w) continue;
            visit[to]=1;
            q.push(to);
            if(to==end_node) return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<M;i++)
    {
        int a,b,c; cin >> a >> b >>c;
        v[a].push_back({b,c}); v[b].push_back({a,c});
        e=max(e,c);
    }
    cin >> start_node >> end_node;
    while(s<=e)
    {
        memset(visit,0,sizeof(visit)); visit[start_node] = 1;
        int mid = (s+e)/2;
        if(BFS(mid)) s = mid +1;
        else e = mid-1;
    }
    cout << e ;
}