#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int V,E,K,d[20002];
vector<pair<int,int>> v[20002];
priority_queue<pair<int,int>> pq;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E >> K;
    for(int i=1;i<=V;i++) d[i]=INT_MAX; 
    for(int i=0;i<E;i++)
    {
        int a,b,c; cin >> a >> b >> c;
        v[a].push_back({c,b});
        if(a==K) pq.push({-1*c,b});
    }

    while(!pq.empty())
    {
        int to = pq.top().second, dis=-1*pq.top().first; pq.pop();
        if(d[to]==INT_MAX)
        {
            d[to]=dis;
            for(int i=0;i<v[to].size();i++)
            {
                int new_dis = dis+v[to][i].first;
                int new_to = v[to][i].second;
                pq.push({-1*new_dis,new_to});
            }
        }
    }
    for(int i=1;i<=V;i++)
    {
        if(i==K) cout << 0<<endl;
        else if(d[i]==INT_MAX) cout << "INF" << endl;
        else cout << d[i]<<endl;
    }
}