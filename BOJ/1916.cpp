#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,dis[1002],s,e;
vector<pair<int,int>> node[1002];
priority_queue<pair<int,int>> pq;
int main()
{
    cin >> N >> M;
    for(int i=1;i<=N;i++) dis[i]=1e9;
    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        node[a].push_back({-1*c,b});
    }
    cin >> s >> e;
    for(int i=0;i<node[s].size();i++) pq.push(node[s][i]);

    while(!pq.empty())
    {
        int to = pq.top().second, d = pq.top().first; pq.pop();
        if(dis[to]!=1e9) continue;
        dis[to]=-1*d;
        for(int i=0;i<node[to].size();i++) 
        {
            int new_dis = d+node[to][i].first;
            int new_to = node[to][i].second;
            pq.push({new_dis,new_to});
        }
    }
    cout << dis[e];
}