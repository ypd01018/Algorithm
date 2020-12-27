#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,a,b,visited[3002],rotate_true[3002],node_dis[3002];
vector<int> node[3002];
vector<int> v;
queue<int> q;
bool flag = false;
void make_rotate(int start)
{
    bool start_flag = false;
    for(int i=0;i<v.size();i++)
    {
        int node_num = v[i];
        if(node_num==start) start_flag = true;
        if(start_flag)
        {
            rotate_true[node_num]=1;
        }
    }
}
void DFS(int pre,int a)
{
    if(flag) return;

    v.push_back(a);
    for(int i=0;i<node[a].size();i++)
    {
        int nxt = node[a][i];
        if(nxt!=pre && visited[nxt])
        {
            make_rotate(nxt);
            flag = true;
            return;
        }
        if(visited[nxt]) continue;
        visited[nxt]=1;
        DFS(a,nxt);
        visited[nxt]=0;
    }
    v.pop_back();
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a >> b;
        node[a].push_back(b); node[b].push_back(a);
    }
    visited[1]=1;
    DFS(0,1);
    queue<pair<int,int> > q;
    memset(visited,0,sizeof(visited));
    for(int i=1;i<=N;i++)
    {
        if(!rotate_true[i]) continue;
        q.push(make_pair(i,0));
        visited[i]=1;
        break;
    }
    while(!q.empty())
    {
        int n_num = q.front().first,dis = q.front().second; q.pop();
        node_dis[n_num] = dis;
        for(int i=0;i<node[n_num].size();i++)
        {
            int nxt_num = node[n_num][i],nxt_dis = dis;
            if(visited[nxt_num]) continue;
            if(!rotate_true[nxt_num]) nxt_dis++;
            visited[nxt_num]=1;
            q.push({nxt_num,nxt_dis});
        }
    }

    for(int i=1;i<=N;i++) cout << node_dis[i] << ' ';
}