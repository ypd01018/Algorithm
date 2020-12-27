#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,oil,mat[22][22],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
pair<int,int> taxi;
struct client_
{
    int to_y,to_x;
    bool flag = false;
}client[22][22];
struct info_
{
    int y,x,d;
}info;
bool cmp(info_ a, info_ b)
{
    if(a.d< b.d) return true;
    else if(a.d > b.d) return false;
    else
    {
        if(a.y<b.y) return true;
        else if(a.y>b.y) return false;
        else
        {
            if(a.x<b.x) return true;
            else return false;
        }
    }
}
int to_oil(int from_y, int from_x)
{
    int visited[22][22]={0}; visited[from_y][from_x]=1;
    int target_y = client[from_y][from_x].to_y, target_x = client[from_y][from_x].to_x;
    queue<pair<pair<int,int>,int>> q;
    q.push({{from_y,from_x},0});
    while(!q.empty())
    {
        int y = q.front().first.first, x= q.front().first.second, d = q.front().second; q.pop();
        if(y==target_y && x == target_x) return d;
        for(int n=0;n<4;n++)
        {
            int ny = y+dy[n], nx =x+dx[n];
            if(ny<1 || nx<1 || ny>N || nx>N || mat[ny][nx] || visited[ny][nx]) continue;
            visited[ny][nx]=1;
            q.push({{ny,nx},d+1});
        }
    }
    return -1;
}
bool find_client()
{
    int visited[22][22]={0}; visited[taxi.first][taxi.second]=1;
    queue<pair<pair<int,int>,int>> q;
    q.push({{taxi.first,taxi.second},0});
    vector<info_> v;
    while(!q.empty())
    {
        int y = q.front().first.first, x= q.front().first.second, d = q.front().second; q.pop();
        if(client[y][x].flag)
        {
            info.y=y; info.x=x; info.d=d;
            v.push_back(info);
        }
        for(int n=0;n<4;n++)
        {
            int ny = y+dy[n], nx =x+dx[n];
            if(ny<1 || nx<1 || ny>N || nx>N || mat[ny][nx] || visited[ny][nx]) continue;
            visited[ny][nx]=1;
            q.push({{ny,nx},d+1});
        }
    }
    if(v.empty()) return false;
    sort(v.begin(),v.end(),cmp);
    int a_oil =v[0].d, b_oil = to_oil(v[0].y,v[0].x);
    if(b_oil==-1 || oil<a_oil+b_oil) return false;
    taxi.first =client[v[0].y][v[0].x].to_y; taxi.second=client[v[0].y][v[0].x].to_x; client[v[0].y][v[0].x].flag=false;
    oil += 2*b_oil-(a_oil+b_oil); 
    return true;
}
int go()
{
    for(int i=0;i<M;i++)
        if(!find_client()) return -1;
    return oil;
}
int main()
{
    cin >> N >> M >> oil;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> mat[i][j];
        }
    }
    cin >> taxi.first >> taxi.second;
    for(int i=0;i<M;i++)
    {
        int a,b; cin >> a >> b;
        client[a][b].flag=true;
        cin >> client[a][b].to_y >> client[a][b].to_x;
    }
    cout << go();
}