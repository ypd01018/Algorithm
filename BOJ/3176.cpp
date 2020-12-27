#include<bits/stdc++.h>
#define endl "\n"
#define MAX 100010
using namespace std;
vector<int> v[MAX],v2[MAX];
int depth[MAX];
int parent[21][MAX];
int n,m,mn[21][MAX],mx[21][MAX];
queue<int> q;
void BFS()
{
    depth[1]=0;
    q.push(1);
    parent[0][1]=1;
    while(!q.empty())
    {
        int target = q.front(); q.pop();
        for(int i=0;i<v[target].size();i++)
        {
            int nnode=v[target][i];
            int len = v2[target][i];

            if(depth[nnode]==-1)
            {
                depth[v[target][i]] = depth[target]+1;
                parent[0][v[target][i]] = target;
                mx[0][nnode]=len;
                mn[0][nnode]=len;
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
            mx[i][j]= max(mx[i-1][j],mx[i-1][parent[i-1][j]]);
            mn[i][j]= min(mn[i-1][j],mn[i-1][parent[i-1][j]]);
        }
    }
}
void find_ancestor(int a,int b)
{
    int ans_min = 1000002, ans_max = -1;
    
    if(depth[a] < depth[b]) swap(a,b);
    int diff = depth[a] - depth[b];
    for(int i=0;diff;i++)
    {
        if( diff & 1) 
        {
            ans_min = min(ans_min,mn[i][a]);
            ans_max = max(ans_max,mx[i][a]);
            a = parent[i][a];
        }
        diff >>=1; 
    }

    for(int i=20;i>=0 && a!=b;i--) 
    {
        if(a!=b && parent[i][a]!=parent[i][b])
        {
            a = parent[i][a];
            b = parent[i][b];
            ans_min = min(mn[i][b],mn[i][a]);
            ans_max = max(mx[i][b],mx[i][a]);
        }
    }

    if(a!=b)
    {
        ans_min = min(mn[0][b],mn[0][a]);
        ans_max = max(mx[0][b],mx[0][a]);
    }
    
    cout << ans_min <<" "<< ans_max << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<=n;i++)
    {
        v[i].clear();
        v2[i].clear();
        depth[i]=-1;
        for(int j=0;j<=21;j++)
        {
            mn[j][i]=1000001;
        }
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back(b);
        v2[a].push_back(c);
        v[b].push_back(a);
        v2[b].push_back(c);
    }
    BFS();
    fast_ans();
    cin >> m;
    for(int i=0;i<m;i++)
    {
        int a ,b;
        cin >> a >> b;
        find_ancestor(a,b);
    }
}