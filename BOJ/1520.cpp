#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,mat[510][510],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},visit[510][510];

int DFS(int y, int x)
{
    if(y==N-1 && x==M-1) return 1;
    if(visit[y][x]>=0) return visit[y][x];
    visit[y][x]=0;
    for(int i=0;i<4;i++)
    {
        int ny = y+dy[i], nx=x+dx[i];
        if(ny>=0 && nx >=0 && ny <N && nx < M && mat[ny][nx]<mat[y][x]) visit[y][x] += DFS(ny,nx);
    }
    return visit[y][x];
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> mat[i][j];
            visit[i][j]=-1;
        }
    }
    //memset(visit,-1,sizeof(visit));
    cout << DFS(0,0);


}