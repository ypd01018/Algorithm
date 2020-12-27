#include<bits/stdc++.h>
#define endl "\n"
#define MAX 100010
using namespace std;
vector<int> v[MAX];
int depth[MAX];
int parent[MAX];
bool visited[MAX];
int n,m;
queue<int> q;
void find_ancestor(int a,int b)
{
    int min_depth,min_node,max_node;
    if(depth[a] < depth[b])
    {
        min_depth = depth[a];    
        min_node = a;
        max_node = b;
    }
    else
    {
        min_depth = depth[b];
        min_node = b;
        max_node = a;
    }
    int diff = abs(depth[a]-depth[b]);
    for(int i=0;i<diff;i++)
    {
        max_node = parent[max_node];
    }

    while(max_node!=min_node)
    {
        max_node = parent[max_node];
        min_node = parent[min_node];
    }
    cout << max_node<<endl;
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
                parent[v[target][i]] = target;
                q.push(v[target][i]);
            }
        }
    }

    cin >> m;
    for(int i=0;i<m;i++)
    {
        int a ,b;
        cin >> a >> b;
        find_ancestor(a,b);
    }




}