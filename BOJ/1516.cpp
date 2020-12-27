#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,cost[600],visited[600],tot_cost[600],indegree[600],parent[600];
vector<int> v[600];
queue<pair<int,int>> q;



int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        bool cost_input=true;
        int tmp; cin >> tmp;
        cost[i] = tot_cost[i] = tmp;
        while(1)
        {
            cin >> tmp;
            if(tmp == -1) break;
            v[tmp-1].push_back(i);
            indegree[i]++;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0) q.push({cost[i],i});
    }
    while(!q.empty())
    {
        
        int target = q.front().second; q.pop();
        for(int i=0;i<v[target].size();i++)
        {
            indegree[v[target][i]]--;
            tot_cost[v[target][i]] = max(tot_cost[v[target][i]],tot_cost[target]+cost[v[target][i]]);

            if(indegree[v[target][i]]==0)
            {
                q.push({tot_cost[v[target][i]],v[target][i]});
                visited[v[target][i]]=1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout << tot_cost[i] << endl;
    }

}