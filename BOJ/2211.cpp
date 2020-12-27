#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,min_dis[1002];
vector<pair<int,int>> v[1002];
priority_queue<pair<int,pair<int,int>>> pq;
queue<pair<int,int>> q;
int main()
{
    cin >> N >> M;
    for(int i=2;i<=N;i++) min_dis[i]=INT_MAX;
    for(int i=1;i<=M;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
        if(a==1) pq.push({-1*c,{1,b}});
        if(b==1) pq.push({-1*c,{1,a}});
    }

    while(!pq.empty())
    {
        int start =pq.top().second.first, target= pq.top().second.second, dis = (-1)*pq.top().first; pq.pop();
        if(min_dis[target]==INT_MAX)
        {
            min_dis[target]=dis;
            q.push({start,target});
            for(int i=0;i<v[target].size();i++)
            {
                int target_dis = dis + v[target][i].first;
                int new_target = v[target][i].second;
                pq.push({(-1)*target_dis,{target,new_target}});
            }
        }
    }
    //for(int i=1;i<=N;i++) cout << min_dis[i] << ' ';
    cout << q.size()<<endl;
    while(!q.empty())
    {
        cout << q.front().first << ' ' << q.front().second << endl;
        q.pop();
    }
}