#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,indegree[1002],check[1002],cnt;
vector<int> v[1003];
queue<pair<int,int>> q;
int main()
{
    cin >> N >> M;
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        indegree[b]++;
    }
    for(int i=1;i<=N;i++)if(!indegree[i]) q.push({i,1});

    while(!q.empty())
    {
        int a = q.front().first, b = q.front().second; q.pop();
        check[a]=b;
        for(int i=0;i<v[a].size();i++)
        {
            indegree[v[a][i]]--;
            if(!indegree[v[a][i]]) q.push({v[a][i],b+1});
        } 
    }
    for(int i=1;i<=N;i++) cout << check[i] << ' ';
}