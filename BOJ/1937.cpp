#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,mat[502][502],dp[502][502],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},mx=0;
int DFS(int y, int x)
{
    if(dp[y][x]) return dp[y][x];
    dp[y][x]=1;
    for(int i=0;i<4;i++)
    {
        int ny = y+dy[i], nx=x+dx[i];
        if(ny >=0 && nx>=0 && ny<n && nx<n && mat[ny][nx]> mat[y][x])
        {
            dp[y][x]=max(dp[y][x],DFS(ny,nx)+1);
        }
    }
    return dp[y][x];
}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> mat[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            mx = max(DFS(i,j),mx);
        }
    }
    cout << mx;
}