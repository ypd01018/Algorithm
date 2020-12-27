#include<bits/stdc++.h>
#define endl "\n"
#define MAX 999'999'999
using namespace std;
int V,e,k;
int min_dis[20100];
vector<pair<int,int>> v[20100];
priority_queue<pair<int,int>> q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> e >> k;

    for(int i=1;i<=V;i++) min_dis[i]=999'999'999;
    min_dis[k]=0;
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        if(a==k) q.push({(-1)*c,b});
    }

    while(!q.empty())
    {
        int target=q.top().second,dis=(-1)*q.top().first; q.pop();
        if(min_dis[target]==MAX)
        {
            min_dis[target]=dis;
            for(int i=0;i<v[target].size();i++)
            {
                q.push({(-1)*(v[target][i].second+min_dis[target]),v[target][i].first});
            }
        }
    }   
    for(int i=1;i<=V;i++)
    {
        if(min_dis[i]==999999999) cout <<"INF"<<endl;
        else cout << min_dis[i] << endl;
    }
}