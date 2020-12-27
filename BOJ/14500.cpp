#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,dx[]={0,1,0,-1},dy[]={1,0,-1,0},mx=0;
int mat[510][510];
bool visited[510][510];
void DFS(int y, int x, int tot,int cnt)
{
    tot += mat[y][x];
    if(cnt==4)
    {
        mx = max(tot,mx);
        return;
    }
    for(int i=0;i<4;i++)
    {
        int ny = y+dy[i],nx=x+dx[i];
        if(ny>=0 && nx >=0 && ny < n && nx < m && !visited[ny][nx])
        {
            visited[ny][nx]=1;
            DFS(ny,nx,tot,cnt+1);
            visited[ny][nx]=0;
        }
    }
}
void go(int y,int x)
{
    int tot=mat[y][x];
    int non=0;
    for(int i=0;i<4;i++)
    {
        int ny = y+dy[i],nx=x+dx[i];
        if(ny<0 || nx <0 || ny >= n || nx >= m)
        {
            non++;
            continue;
        }
        tot += mat[ny][nx];
    }
    if(non>1) return;
    if(non==1)
    {
        mx = max(mx,tot);
    }
    else
    {
        for(int i=0;i<4;i++)
        {
            int ny = y+dy[i],nx=x+dx[i];
            mx = max(tot-mat[ny][nx],mx);
        }
    }
    
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> mat[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            visited[i][j]=1;
            DFS(i,j,0,1);
            go(i,j);
            visited[i][j]=0;
        }
    }
    cout << mx;
}