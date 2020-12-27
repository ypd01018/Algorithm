#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,K,shark_cnt,dy[4]={-1,1,0,0},dx[4]={0,0,-1,1};
pair<int,int> mat[21][21];
priority_queue<int> pq[21][21];
struct shark_
{
    int y,x,d;
    int priority_d[4][4];
    bool die = false;
}shark[404];
void shark_move()
{
    for(int i=1;i<=M;i++)
    {
        if(shark[i].die) continue;
        int ny,nx,nd; bool flag = false;
        for(int n=0;n<4;n++)
        {
            ny = shark[i].y +dy[shark[i].priority_d[shark[i].d][n]]; nx=shark[i].x+dx[shark[i].priority_d[shark[i].d][n]];
            if(ny<0 || nx<0 || ny>=N || nx>=N || mat[ny][nx].first) continue;
            flag = true; nd =shark[i].priority_d[shark[i].d][n]; break;
        }
        if(!flag)
        {
            for(int n=0;n<4;n++)
            {
                ny = shark[i].y +dy[shark[i].priority_d[shark[i].d][n]]; nx=shark[i].x+dx[shark[i].priority_d[shark[i].d][n]];
                if(ny<0 || nx<0 || ny>=N || nx>=N || mat[ny][nx].first != i) continue;
                nd = shark[i].priority_d[shark[i].d][n]; break;
            }
        }
        shark[i].d = nd; shark[i].y=ny; shark[i].x=nx;
        pq[ny][nx].push(-1*i);
    }
}
void die_shark()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(pq[i][j].empty()) continue;
            pq[i][j].pop();
            while(!pq[i][j].empty())
            {
                shark[-1*pq[i][j].top()].die = true; pq[i][j].pop();
                shark_cnt--;
            }
        }
    }
}
void smell()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(!mat[i][j].first) continue;
            else if(mat[i][j].second==1) mat[i][j]={0,0};
            else mat[i][j].second--;
        }
    }
    for(int i=1;i<=M;i++)
    {
        if(shark[i].die) continue;
        mat[shark[i].y][shark[i].x] = {i,K};
    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K; shark_cnt=M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> mat[i][j].first;
            if(!mat[i][j].first) continue;
            shark[mat[i][j].first].y = i; shark[mat[i][j].first].x=j;
            mat[i][j].second = K;
        }
    }
    for(int i=1;i<=M;i++) {cin >> shark[i].d; shark[i].d--;}
    for(int i=1;i<=M;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<4;k++) {cin >> shark[i].priority_d[j][k]; shark[i].priority_d[j][k]--;}
        }
    }
    int n;
    for(n=1;n<=1000;n++)
    {
        shark_move();
        die_shark();
        smell();
        if(shark_cnt==1) break;
    }
    if(shark_cnt==1) cout << n;
    else cout << -1;
}