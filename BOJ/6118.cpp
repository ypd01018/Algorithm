#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,cnt,mx=-1,mn_idx;
int visited[20010];
pair<int,int> dis_arr[20010];
vector<int> v[20010];
queue<pair<int,int>> q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) dis_arr[i].second = i;
    for(int i=0;i<m;i++)
    {
        int start,end;
        cin >> start >> end;
        v[start].push_back(end);
        v[end].push_back(start);
    }
    visited[1]=1;
    for(int i=0;i<v[1].size();i++)
    {
        q.push({v[1][i],1});
        visited[v[1][i]]=1;
    }

    while(!q.empty())
    {
        int target = q.front().first,dis = q.front().second; q.pop();
        dis_arr[target].first = dis;
        if(dis>mx)
        {
            mx = dis;
            cnt=1;
            mn_idx = target;
        }
        else if(dis == mx)
        {
            cnt++;
            mn_idx = min(target,mn_idx);
        }
        for(int i=0;i<v[target].size();i++)
        {
            if(!visited[v[target][i]]) 
            {
                q.push({v[target][i],dis+1});
                visited[v[target][i]]=1;
            }
        }
    }
    //sort(dis_arr+1,dis_arr+1+n);
    cout << mn_idx << ' ' << mx << ' ' << cnt ;
    
}