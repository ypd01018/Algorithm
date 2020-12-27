#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,v,visited1[1010],visited2[1010];
vector<int> edge[1010];
priority_queue<int> pq;
queue<int> q;
stack<int> stk;
void dfs(int a)
{
    cout << a << ' ';
    //visited1[a]=1;
    for(int i=0;i<edge[a].size();i++)
    {
        if(visited1[edge[a][i]]) continue;
        visited1[edge[a][i]]=1;
        dfs(edge[a][i]);
        
    }
}
void bfs()
{
    cout << v << ' ';
    while(!q.empty())
    {
        int val = q.front(); q.pop();
        cout << val << ' ';
        for(int i=0;i<edge[val].size();i++)
        {
            int end = edge[val][i];
            if(!visited2[end])
            {
                q.push(end);
                visited2[end]=1;
            }
        }
    }
}
int main()
{
    cin >> n >> m >> v;
    for(int i=0;i<m;i++)
    {
        int start,end; cin >> start >> end;
        edge[start].push_back(end);
        edge[end].push_back(start);
    }

    for(int i=1;i<=n;i++)
    {
        sort(edge[i].begin(),edge[i].end());
    }

    for(int i=0;i<edge[v].size();i++)
    {
        q.push(edge[v][i]);
        visited2[edge[v][i]]=1;
    }


    visited1[v]=visited2[v]=1;
    visited1[v]=1;
    dfs(v);
    cout << endl;
    bfs();



}