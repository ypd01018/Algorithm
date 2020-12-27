#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 500*1000+1
int N,M,S,D;
struct edge
{
    int from, to, cost, shortest_path;
}E[10001];
struct info
{
    int node, dist, edge_idx;
    bool operator < (const info & ref) const
    {
        return dist > ref.dist;
    }
};
vector<info> adj[501], rev_adj[501];
int dist[501];
int main()
{
    while(1)
    {
        cin >> N >> M;
        if(N==0&&M==0) break;
        cin >> S >> D;
        for(int i=0;i<N;i++)
        {
            dist[i] = INF;
            adj[i].clear();
            rev_adj[i].clear();
        }
        for(int i=0;i<M;i++)
        {
            cin >> E[i].from >> E[i].to>>E[i].cost;
            adj[E[i].from].push_back({E[i].to,E[i].cost,i});
            E[i].shortest_path = 0;
        }

        priority_queue <info> pque;
        dist[S] = 0;
        pque.push({S,0,-1});
        while(!pque.empty())
        {
            info cur = pque.top();pque.pop();
            if(cur.dist != dist[cur.node]) continue;
            for(info e : adj[cur.node])
            {
                if(dist[e.node] > cur.dist + e.dist)
                {
                    dist[e.node] = cur.dist + e.dist;
                    rev_adj[e.node].clear();
                    rev_adj[e.node].push_back({cur.node,e.dist,e.edge_idx});
                    pque.push({e.node,dist[e.node],e.edge_idx});
                }
                else if(dist[e.node] == cur.dist + e.dist)
                {
                    rev_adj[e.node].push_back({cur.node,e.dist,e.edge_idx});
                    pque.push({e.node,dist[e.node],e.edge_idx});
                }
            }
        }
        int ans = -1;
        if(dist[D]!=INF)
        {
            queue <int> que;
            que.push(D);
            while(!que.empty())
            {
                int node = que.front();que.pop();
                for(info e : rev_adj[node])
                {
                    E[e.edge_idx].shortest_path = 1;
                    que.push(e.node);
                }
            }

            for(int i=0;i<N;i++)
            {
                adj[i].clear();
                dist[i] = INF;
            }

            for(int i=0;i<M;i++)
            {
                if(E[i].shortest_path == 0)
                    adj[E[i].from].push_back({E[i].to,E[i].cost,i});
            }
            dist[S] = 0;
            pque.push({S,0,-1});
            while(!pque.empty())
            {
                info cur = pque.top();pque.pop();
                if(cur.node == D)
                {
                    ans = cur.dist;
                    break;
                }
                if(dist[cur.node] != cur.dist) continue;
                for(info e : adj[cur.node])
                {
                    if(dist[e.node] > cur.dist + e.dist)
                    {
                        dist[e.node] = cur.dist + e.dist;
                        pque.push({e.node,dist[e.node],e.edge_idx});
                    }
                }
            }
        }
        cout << ans << "\n";
    }

}