#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,cnt;
int visited[600];
vector<int> v[600];
queue<int> q;
int main()
{
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int start,end;
        cin >> start >> end;
        v[start].push_back(end);
        v[end].push_back(start);
    }
    visited[1]=1;
    for(int i=0;i<v[1].size();i++)
    {
        cnt++;
        q.push(v[1][i]);
        visited[v[1][i]]=1;
    }
    while(!q.empty())
    {
        int target = q.front(); q.pop();
        //if(visited[target]) continue;
        for(int i=0;i<v[target].size();i++)
        {
            if(visited[v[target][i]]) continue;
            cnt++;
            visited[v[target][i]]=1;
        }
    }
    cout << cnt;
}