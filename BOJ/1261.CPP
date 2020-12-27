#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,mat[102][102],dp[102][102],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
queue<pair<pair<int,int>,int>> q;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> M >> N;
    for(int i=0;i<N;i++)
    {
        string a; cin >> a;
        for(int j=0;j<M;j++)
        {
            mat[i][j] = a[j]-'0';
            dp[i][j] = 1e9;
        }
    }
    dp[0][0]=0;
    q.push({{0,0},0});
    while(!q.empty())
    {
        int y = q.front().first.first , x=q.front().first.second, n = q.front().second; q.pop();
        for(int i=0;i<4;i++)
        {
            int ny = y+dy[i], nx = x + dx[i], nn = n;
            if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
            if(mat[ny][nx]==1) nn++;
            if(dp[ny][nx]<=nn) continue;
            dp[ny][nx]=nn;
            q.push({{ny,nx},nn});
        }
    }
    cout << dp[N-1][M-1];

}