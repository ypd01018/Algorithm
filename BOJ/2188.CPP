#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,ans,visited[202],room[202];
vector<int> want[202];
bool sol(int n)
{
    if(visited[n]) return false;
    visited[n]=1;
    for(int i=0;i<want[n].size();i++)
    {
        int want_room = want[n][i];
        if(!room[want_room] || sol(room[want_room]))
        {
            room[want_room]=n;
            return true;
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++)
    {
        int a; cin >> a;
        for(int j=0;j<a;j++)
        {
            int b; cin >> b;
            want[i].push_back(b);
        }
    }

    for(int i=1;i<=N;i++)
    {
        memset(visited,0,sizeof(visited));
        if(sol(i)) ans++;
    }
    cout << ans;
}
