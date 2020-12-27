#include<bits/stdc++.h>
#define endl "\n"
#define MAX 100'010
using namespace std;
int n,m,flag,a,b,c,parent[100'010],idx,visited[MAX];
long long node[MAX];
pair<int,pair<int,int>> arr[100'010];
vector<pair<int,int>> graph[MAX];
void init()
{
    memset(visited,0,sizeof(visited));
    memset(node,0,sizeof(node));    

    for(int i=0;i<MAX;i++)
    {
        parent[i]=i;
        graph[i].clear();
    }
}
int find(int a)
{
    if(parent[a]==a) return a;
    else return parent[a] = find(parent[a]);
}
void uni(int a, int b)
{
    int root_a = find(a);
    int root_b = find(b);
    parent[root_a] = parent[root_b];
}

void dfs(int x, long long d)
{
    visited[x]=1;
    node[x]=d;
    for(auto nxt : graph[x])
    {
        if(visited[nxt.first]==1) continue;
        dfs(nxt.first,d+(long long)nxt.second);
    }
}

void ans()
{
    // for(int i=1;i<=n;i++)
    // {
    //     cout << node[i] << ' ';
    // }
    // cout << endl;
    for(int i=0;i<idx;i++)
    {
        int a,b; tie(a,b)=arr[i].second;
        if(!arr[i].first)
        {
            uni(a,b);
        }
        else
        {
            if(find(a)==find(b))
            {
                cout << node[b]-node[a];
            }
            else
            {
                cout << "UNKNOWN";
            }
            cout << endl;
        }
        
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1)
    {
        init();
        cin >> n >> m;
        if(!n&&!m) break;

        idx=0;
        for(int i=0;i<m;i++)
        {
            char cmd; cin >> cmd >> a >> b;
            if(cmd == '!') 
            {
                flag =0;
                cin >>c;
                graph[a].push_back({b,c});
                graph[b].push_back({a,-c});
            }
            else flag =1;

            arr[idx] = {flag,{a,b}};
            idx++;       
       }
       for(int i=1;i<=n;i++)
       {
           if(!visited[i]) dfs(find(i),0);
       }
        ans();
        
    }
}