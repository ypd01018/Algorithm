#include<bits/stdc++.h>
#define endl "\n"
#define MAX 100010
using namespace std;
vector<int> v[MAX];
int depth[MAX];
int parent[21][MAX];
bool visited[MAX];
int n,m;
queue<int> q;

void BFS()
{
    depth[1]=0;
    visited[1]=1;
    q.push(1);
    while(!q.empty())
    {
        int target = q.front(); q.pop();
        for(int i=0;i<v[target].size();i++)
        {
            if(!visited[v[target][i]])
            {
                visited[v[target][i]]=1;
                depth[v[target][i]] = depth[target]+1;
                parent[0][v[target][i]] = target;
                q.push(v[target][i]);
            }
        }
    }
}
void fast_ans()
{
    for(int i=1;i<21;i++)
    {
        for(int j=1;j<=n;j++)
        {
            parent[i][j] = parent[i-1][parent[i-1][j]];
            cout << "parent["<<i<<"]["<<j<<"]="<<"parent["<<i-1<<"]["<<parent[i-1][j]<<"]"<<endl;
        }
    }
}
int find_ancestor(int a,int b)
{
    if(depth[a] < depth[b]) swap(a,b);
    int diff = depth[a] - depth[b];
    for(int i=0;diff;i++)
    {
        if( diff & 1) a = parent[i][a];
        diff >>=1; 
    }
    if(a==b) return a;
    for(int i=20;i>=0;i--)
    {
        if(parent[i][a]!=parent[i][b])
        {
            a = parent[i][a];
            b = parent[i][b];
        }
    }
    return parent[0][a];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    BFS();
    fast_ans();
    cin >> m;
    for(int i=0;i<m;i++)
    {
        int a ,b;
        cin >> a >> b;
        cout << find_ancestor(a,b)<<endl;
    }
}

