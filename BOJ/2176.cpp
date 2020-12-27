#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, M, dp[1002], n_node[1002],d[1002],visit[1002];
vector<pair<int, int>> node[1002];
priority_queue<pair<int,int>> pq;
int DFS(int a, int from)
{    
    if(a==2) return 0;
    int target_d = INT_MAX;
    for(int i=0;i<node[a].size();i++)
    {
        int b = node[a][i].first, dis = node[a][i].second;
        if(visit[b]) continue;
        visit[b] = 1;
        target_d = min(DFS(b,a)+dis,target_d);
        visit[b] = 0;
    }
    dp[a] = target_d;
    return target_d;
}
void DFS2(int a)
{
    for(int i=0;i<node[a].size();i++)
    {
        int b = node[a][i].first;
        if(dp[b]<dp[a]) n_node[b] += n_node[a];
    }
    for(int i=0;i<node[a].size();i++){
        int b = node[a][i].first;
        if(dp[b]<dp[a]) DFS2(b);
    }
}
int main()
{
    cin >> N >> M;
    for(int i=2;i<=N;i++) d[i] = INT_MAX;
    for (int i = 1; i <= N; i++)
        dp[i] = INT_MAX;

    dp[2] = 0;
    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        node[A].push_back({B, C});
        node[B].push_back({A, C});
    }
    visit[1] = 1;
    DFS(1, 0);
    n_node[1] = 1;
    DFS2(1);
    cout << n_node[2];
    // for(int i=1;i<=N;i++) cout << "i:" << i << " " << dp[i] << endl;
}