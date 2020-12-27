#include<bits/stdc++.h>
#define endl "\n"
#define val first
#define turn second
using namespace std;
int N,M,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},check[1002][1002][2];
int mat[1002][1002];
int turn[1002][1002][2];
queue<pair<pair<int,int>,int>> q;
void BFS()
{
    while(!q.empty())
    {
        int y,x,broken; tie(y,x) = q.front().first; broken = q.front().second; q.pop();
        if(y == N && x ==M) break;

        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx > 0 && ny > 0 && nx <= M && ny <= N && !check[ny][nx][broken])
            {
                check[ny][nx][broken]=1;
                turn[ny][nx][broken] = turn[y][x][broken] + 1;
                if(!mat[ny][nx])
                {
                    q.push({{ny,nx},broken});
                }
                else
                {
                    if(!broken)
                    {
                        check[ny][nx][1]=1;
                        turn[ny][nx][1] = turn[y][x][0] + 1;
                        q.push({{ny,nx},1});
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for(int i=1;i<=N;i++)
    {
        string tmp; cin >> tmp;
        for(int j=1;j<=M;j++)
        {
            mat[i][j] = tmp[j-1]-48;
        }
    }
    q.push({{1,1},0});
    check[1][1][0]=check[1][1][1]=1;
    turn[1][1][0] =turn[1][1][1] = 1;
    BFS();
    if(turn[N][M][0] ==0 && turn[N][M][1]==0) cout << -1;
    else if(turn[N][M][0] ==0) cout << turn[N][M][1];
    else if(turn[N][M][1]==0) cout << turn[N][M][0];
    else cout << min(turn[N][M][0],turn[N][M][1]);
}