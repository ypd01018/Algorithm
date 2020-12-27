#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<int> v[35000];
int indegree[35000];
int n,m,a,b;
queue<int> q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>n>>m;
    
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        indegree[b]++;
    }

    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0) q.push(i);
    }
    while(!q.empty())
    {
        int node = q.front(); q.pop();
        cout << node << " ";
        for(int i=0;i<v[node].size();i++)
        {
            indegree[v[node][i]]--;
            if(indegree[v[node][i]]==0) q.push(v[node][i]);
        }
    }
}