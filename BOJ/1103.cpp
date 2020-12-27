#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,mat[55][55],visited[55][55],dy[4]={1,0,-1,0},dx[4]={0,1,0,-1},ans,dp[55][55];
int DFS(int y, int x)
{
    if(dp[y][x]) return dp[y][x];

    visited[y][x]=1;
    int val = mat[y][x];
    for(int i=0;i<4;i++)
    {
        int ny = y+dy[i]*val, nx = x+dx[i]*val;
        if(ny>=0 && nx >=0 && ny <N && nx < M && mat[ny][nx]!=-1)
        {
            if(visited[ny][nx])
            {
                ans = -1;
                cout << ans;
                exit(0);
            }
            else
            {
                dp[y][x]=max(dp[y][x],DFS(ny,nx)+1);
            }
            
        }
    }
    visited[y][x]=0;
    return dp[y][x];
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        string input;
        cin >> input;
        for(int j=0;j<M;j++)
        {
            if(input[j]=='H') mat[i][j]=-1;
            else mat[i][j]= input[j] - '0';
        }
    }
    visited[0][0]=1;

    cout << DFS(0,0)+1;




}