#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,arr[600][600],arr2[600][600],visited[600];
vector<int> v[1000],v_par[1000];
queue<int> q;
int main()
{
    cin >> n >> m;
    for(int i=1;i<m+1;i++)
    {
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v_par[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
    {
        q.push(i);
        if(i!=1)
        for(int j=1;j<=n;j++)
        {
            arr[i][j]=arr[i-1][j];
        }
        while(!q.empty())
        {
            int target = q.front(); q.pop();
            for(int j=0;j<v[target].size();j++)
            {
                if(visited[v[target][j]]) continue;
                arr[i][v[target][j]]++;
                q.push(v[target][j]);
                visited[v[target][j]]=1;
            }
        }
        memset(visited,0,sizeof(visited));
    }



    for(int i=1;i<=n;i++)
    {
        q.push(i);
        if(i!=1)
        for(int j=1;j<=n;j++)
        {
            arr2[i][j]=arr2[i-1][j];
        }
        while(!q.empty())
        {
            int target = q.front(); q.pop();
            for(int j=0;j<v_par[target].size();j++)
            {
                if(visited[v_par[target][j]]) continue;
                arr2[i][v_par[target][j]]++;
                q.push(v_par[target][j]);
                visited[v_par[target][j]]=1;
            }
        }
        memset(visited,0,sizeof(visited));
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[n][i]+arr2[n][i]==n-1) cnt++;
    }
    cout << cnt;
}