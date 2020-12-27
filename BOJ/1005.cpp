#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
long long T,N,K,cost[1002],indegree[1002],goal,mx_cost[1002];
vector<long long> v[1002];
queue<long long> q;
void sol()
{
    
    cin >> N >> K;
    for(int i=1;i<=N;i++) 
    {
        cin >> cost[i];
        indegree[i]=0;
        mx_cost[i]=0;
        v[i].clear();
    }
    for(int i=0;i<K;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        indegree[b]++;
    }
    cin >> goal;

    for(int i=1;i<=N;i++)
    {
        if(!indegree[i]) 
        {
            mx_cost[i]=cost[i];
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int node = q.front(); q.pop();
        for(int i=0;i<v[node].size();i++)
        {
            int target = v[node][i];
            indegree[target]--;
            mx_cost[target] = max(mx_cost[target],mx_cost[node]+cost[target]);
            if(!indegree[target]) q.push(target);
        }
    }

    //for(int i=1;i<=N;i++) cout << mx_cost[i]<<' '; cout << endl;
    cout <<mx_cost[goal]<< endl;


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for(int i=0;i<T;i++) sol();
}