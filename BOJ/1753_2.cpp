#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int V,E,K,min_dis[300'010];
vector<pair<int,int>> v[300'010];
priority_queue<pair<int,int>> pq;
int main()
{
    cin >> V >> E >> K;
    for(int i=0;i<=V;i++) min_dis[i]=INT_MAX;
    min_dis[K]=0;

    for(int i=0;i<E;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        if(a==K) pq.push({-1*c,b});
    }

    while(!pq.empty())
    {
        int node = pq.top().second, val = pq.top().first; pq.pop();
        if(min_dis[node]==INT_MAX)
        {
            min_dis[node] = -1*val;
            for(int i=0;i<v[node].size();i++)
            {
                pq.push({-1*(v[node][i].second+min_dis[node]),v[node][i].first});
            }
        }
    }

    for(int i=1;i<=V;i++)
    {
        if(min_dis[i]==INT_MAX) cout << "INF"<< endl;
        else        cout << min_dis[i] << endl;
    }

}