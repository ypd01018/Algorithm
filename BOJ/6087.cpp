#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int N,M;
vector<pair<int,int>> start;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
int dp[101][101][2];
char mat[101][101];

void dfs(int y, int x, bool is_row) {
    for(int i=0;i<4;i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M || mat[ny][nx] == '*') continue;
        bool is_next_row = i%2;
        bool is_change = (is_row == is_next_row) ? false : true;
        if(start[0].first == y && start[0].second == x) is_change = false;
        int next_val = is_change? dp[y][x][is_row] + 1 : dp[y][x][is_row];

        if(next_val >= dp[ny][nx][is_next_row]) continue;

        dp[ny][nx][is_next_row] = next_val;
        dfs(ny,nx,is_next_row);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> mat[i][j];
            dp[i][j][0] = dp[i][j][1] = INT_MAX - 10;
            if(mat[i][j] == 'C'){
                start.push_back({i,j});
            }
        }
    }

    dp[start[0].first][start[0].second][0] = 0;
    dp[start[0].first][start[0].second][1] = 0;
    dfs(start[0].first,start[0].second,1);


    cout << min(dp[start[1].first][start[1].second][0], dp[start[1].first][start[1].second][1]);
}