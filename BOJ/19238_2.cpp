#include<bits/stdc++.h>
#define endl "\n"
#define INF 1e9
using namespace std;
int N,M,oil,mat[22][22],dis[410][410],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
pair<int,int> taxi;
struct client_
{
    int from_y,from_x,to_y,to_x;
    bool flag = true;
}client[403];
bool cmp(client_ a, client_ b)
{
    if(a.from_y<b.from_y) return true;
    else if(b.from_y<a.from_y) return false;
    else
    {
        if(a.from_x<b.from_x) return true;
        else return false;
    }
}
int ret_idx(int y, int x) {return (y-1)*N+x;}
void floyd()
{
    for(int i=1;i<=N*N;i++)
    {
        for(int j=1;j<=N*N;j++)
        {
            if(i!=j) dis[i][j] = INF;
        }
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(mat[i][j]) continue;
            for(int n=0;n<4;n++)
            {
                int ny = i+dy[n], nx = j+dx[n];
                if(ny<1||nx<1||ny>N||nx>N||mat[ny][nx]) continue;
                dis[(i-1)*N+j][(ny-1)*N+nx]=1;
            }
        }
    }
    for(int k=1; k<=N*N; k++)
        for(int i=1; i<=N*N; i++)
            for(int j=1; j<=N*N; j++)
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
}
int find_client()
{
    int mn=1e9,mn_idx=-1;
    for(int i=0;i<M;i++)
    {
        if(!client[i].flag) continue;
        int d = dis[ret_idx(taxi.first,taxi.second)][ret_idx(client[i].from_y,client[i].from_x)];
        if(mn<=d) continue;
        mn = d;
        mn_idx = i;
    }
    return mn_idx;
}
int go()
{
    for(int i=0;i<M;i++)
    {
        pair<int,int> yx;
        int client_idx = find_client();
        if(client_idx==-1) return -1;
        client[client_idx].flag = false;
        int from_y = client[client_idx].from_y, from_x=client[client_idx].from_x,
            to_y = client[client_idx].to_y, to_x = client[client_idx].to_x;
        int a_oil = dis[ret_idx(taxi.first,taxi.second)][ret_idx(from_y,from_x)],
        b_oil = dis[ret_idx(from_y,from_x)][ret_idx(to_y,to_x)];
        if(oil<a_oil+b_oil) return -1;
        taxi.first = to_y; taxi.second = to_x;
        oil -=(a_oil + b_oil);
        oil += 2*b_oil;
    }
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
    floyd();
    cin >> taxi.first >> taxi.second;
    for(int i=0;i<M;i++) cin >> client[i].from_y >> client[i].from_x >> client[i].to_y >> client[i].to_x;
    sort(client,client+M,cmp);
    cout << go();
}