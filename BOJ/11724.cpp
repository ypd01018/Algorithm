#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,cnt;
int visited[1010];
vector<int> v[1010];
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
    for(int i=1;i<=n;i++)
    {
        if(visited[i]!=0) continue; 
        cnt++;
        q.push(i);
        visited[i]=1;
        while(!q.empty())
        {
            int target = q.front(); q.pop();
            for(int i=0;i<v[target].size();i++)
            {
                if(!visited[v[target][i]]) 
                {
                    q.push(v[target][i]);
                    visited[v[target][i]]=1;
                }
            }
        }
    }
    cout << cnt;
}