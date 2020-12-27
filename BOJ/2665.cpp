#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int N,mat[52][52],dp[52][52],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};

void DFS(int y, int x){
    for(int n=0;n<4;n++){
        int ny = y+dy[n], nx = x+dx[n];
        if(ny<0 || nx<0 || ny>=N || nx >=N) continue;
        // if(!mat[ny][nx] && dp[ny][nx]<=dp[y][x]+1) continue;
        // if(mat[ny][nx] && dp[ny][nx]<=dp[y][x]) continue;
        if(dp[ny][nx]<=dp[y][x]) continue;
        dp[ny][nx] = dp[y][x] + (1-mat[y][x]);
        DFS(ny,nx);
    }
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        string a; cin >> a;
        for(int j=0;j<N;j++){
            mat[i][j] = a[j]-'0';
            dp[i][j]=INT_MAX;
        }
    }
    dp[0][0] = 1 - mat[0][0];
    DFS(0,0);
    cout << dp[N-1][N-1];
}
