#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,arr[12],node_zip[12],node[12],visit[12],mn=INT_MAX,visited[12];
vector<int> v[12];
queue<int> q;
void BFS()
{
    while(!q.empty())
    {
        int s_node = q.front(); q.pop();
        for(int i=0;i<v[s_node].size();i++)
        {
            int e_node=v[s_node][i];
            if(!visit[e_node] && node[e_node]==node[s_node])
            {
                visit[e_node]=1;
                q.push({e_node});
            }
        }
    }
}
void check()
{
    memset(visit,0,sizeof(visit));
    int zero=0, one=0;
    for(int i=1;i<=N;i++)
    {
        // cout << node[i] << ' ';
        if(node[i]) one++;
        else zero++;
    }
    // cout << endl;

    if(!one||!zero) return;

    for(int i=1;i<=N;i++)
        if(node[i]==0) 
        {
            q.push(i); 
            visit[i]=1;
            break; 
        }
    BFS();

    for(int i=1;i<=N;i++)
        if(node[i]==1) 
        {
            visit[i]=1;
            q.push(i); break; 
        }
    BFS();

    for(int i=1;i<=N;i++)
        if(!visit[i]) return;
    zero = one =0;

    for(int i=1;i<=N;i++)
    {
        if(node[i]) one+=arr[i];
        else zero+=arr[i];
    }
    mn = min(mn,(int)abs((zero-one)));
    

}
void DFS(int a)
{
    for(int i=a;i<=N;i++)
    {
        if(visited[i]) continue;
        visited[i]=1;
        node[i]=1;
        check();
        DFS(a+1);
        visited[i]=0;
        node[i]=0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> arr[i];
    for(int i=1;i<=N;i++)
    {
        int a;
        cin >> a;
        for(int j=0;j<a;j++)
        {
            int b; cin >> b;
            v[i].push_back(b);
        }
    }
    DFS(1);
    if(mn==INT_MAX) cout << -1;
    else cout << mn;

}