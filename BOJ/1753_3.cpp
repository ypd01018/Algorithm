#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#define endl "\n"
using namespace std;
int V,E,K,dis[20002];
vector<pair<int,int>> v[20002];
priority_queue<pair<int,int>> pq;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> V >> E >> K;
    for(int i=0;i<E;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        if(a==K) pq.push({-1*c,b});_
    }
    memset(dis,-1,sizeof(dis));
    while(!pq.empty())
    {
        int to = pq.top().second, d = -1*pq.top().first; pq.pop();
        if(dis[to]>=0) continue;
        dis[to] = d;
        for(int i=0;i<v[to].size();i++)
        {
            int to_to = v[to][i].first, to_to_d = d + v[to][i].second;
            pq.push({-1*to_to_d,to_to});
        }
    }

    for(int i=1;i<=V;i++)
    {
        if(i==K) cout << 0;
        else if(dis[i]<0) cout << "INF";
        else cout << dis[i];
        cout << endl;
    }
}