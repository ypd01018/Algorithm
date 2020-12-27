#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,visit[100010],depth[100010],n_depth[100010];
vector<int> node[100010];
queue<int> q;
int main()
{
    cin >> N; 
    for(int i=0;i<N-1;i++)
    {
        int a,b; cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    depth[1]=1; n_depth[1]++;
    q.push(1); visit[1]=1;
    while(!q.empty())
    {
        int parent_node=q.front(); q.pop();
        for(int i=0;i<node[parent_node].size();i++)
        {
            int child_node = node[parent_node][i];
            if(visit[child_node]) continue;
            visit[child_node]=1;
            depth[child_node] = depth[parent_node]+1;
            n_depth[depth[child_node]]++;
            q.push(child_node);
        }
    }
    int check_n=1; bool flag=true;
    for(int i=0;i<N;i++)
    {
        int a; cin >> a;
        if(depth[a]!=check_n) flag = false;
        if((--n_depth[check_n])==0) check_n++;
    }
    if(flag) cout << 1;
    else cout << 0;
}