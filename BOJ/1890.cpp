#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,mat[102][102],dy[2]={1,0},dx[2]={0,1};
long long dp[102][102];
long long DFS(int y, int x)
{
    if(y==N-1 && x==N-1) return 1;
    if(mat[y][x]==0) return 0;
    if(dp[y][x]) return dp[y][x];

    for(int i=0;i<2;i++)
    {
        int ny = y+mat[y][x]*dy[i], nx=x+mat[y][x]*dx[i];
        if(ny>=N || nx>=N) continue;

        dp[y][x]+=DFS(ny,nx);
    }
    return dp[y][x];
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> mat[i][j];
        }
    }

    cout<<DFS(0,0);



}