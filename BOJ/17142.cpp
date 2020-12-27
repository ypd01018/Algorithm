#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,arr[53][53],virus_cnt,dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},ans=INT_MAX,zero_cnt;
vector<pair<int,int>> v;
pair<int,int> virus[13];
queue<pair<pair<int,int>,int>> q;
void BFS()
{
    int arr_cpy[53][53],visited[53][53]={0,},turn=0,z_cnt = zero_cnt;
    memcpy(arr_cpy,arr,sizeof(arr));
    for(int i=0;i<M;i++) 
    {
        q.push({virus[i],0});
        visited[virus[i].first][virus[i].second]=1;
    }
    while(!q.empty())
    {
        int y = q.front().first.first, x = q.front().first.second, q_turn = q.front().second;
        turn = max(turn,q.front().second); q.pop();

        for(int i=0;i<4;i++)
        {
            int ny = y+dy[i],nx=x+dx[i];
            if(ny >=0 && nx>=0 && ny<N && nx < N && arr_cpy[ny][nx]!=1 && visited[ny][nx]!=1)
            {
                if(arr_cpy[ny][nx]==0) z_cnt--;
                arr_cpy[ny][nx]=2;
                visited[ny][nx]=1;
                q.push({{ny,nx},q_turn+1});
            }
        }
        
        if(z_cnt==0)
        {
            turn = max(turn,q_turn+1);
            while(!q.empty()) q.pop();
            ans = min(turn,ans);
            break;
        }
    }
}
void go(int a)
{
    if(virus_cnt==M)
    {
        BFS();
        return;
    }
    for(int i=a;i<v.size();i++)
    {
        virus[virus_cnt]=v[i];
        virus_cnt++;
        go(i+1);
        virus_cnt--;
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> arr[i][j];
            if(arr[i][j]==2) v.push_back({i,j});
            if(arr[i][j]==0) zero_cnt++;
        }
    }
    if(zero_cnt==0)
    {
        cout << 0;
        exit(0);
    }
    go(0);
    if(ans==INT_MAX) cout << -1;
    else cout << ans;
}