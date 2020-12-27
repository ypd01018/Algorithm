#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,k,m,visited[200010];
vector<int> v[200010];
queue<pair<int,int>> q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m; //n = node k+m=edge 
    if(n==1)
    {
        cout << 1;
        exit(0);
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<k;j++)
        {
            int tmp; cin >> tmp;
            v[i+n+1].push_back(tmp);
            v[tmp].push_back(i+n+1);
        }
    }

    visited[1]=1;
    for(int i=0;i<v[1].size();i++)
    {
        q.push({v[1][i],2});
        visited[v[1][i]]=1;
    }
    while(!q.empty())
    {
        int target=q.front().first,dis=q.front().second; q.pop();
        if(target>n) dis--;
        if(target==n)
        {
            cout << dis;
            exit(0);
            break;
        }
        for(int i=0;i<v[target].size();i++)
        {
            if(visited[v[target][i]]) continue;
            q.push({v[target][i],dis+1});
            visited[v[target][i]]=1;
        }
    }
    cout << -1;


}