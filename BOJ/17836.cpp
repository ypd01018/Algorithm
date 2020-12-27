#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int>> q;
int N,M,T;
int mat[102][102],visited[102][102];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
pair<int,int> sword;
int main(){
    cin >> N >> M >> T;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> mat[i][j];
            if(mat[i][j]==2) sword = {i,j};
        }
    }

    visited[0][0] = 1;
    q.push({0,0});
    while(!q.empty()){
        int y = q.front().first, x = q.front().second;
        int visited_time = visited[y][x];
        q.pop();
        for(int i=0;i<4;i++){
            int ny = y+dy[i], nx = x+dx[i];
            if(ny<0 || nx<0 || ny>=N || nx>=M || visited[ny][nx] || mat[ny][nx] == 1) continue;
            visited[ny][nx] = visited_time + 1;
            q.push({ny,nx});
        }
    }

    int distance_sword_between_target = (N-1-sword.first) + (M-1-sword.second);
    int distance_sword = (visited[sword.first][sword.second] - 1);
    int distance_having_sword = distance_sword!=-1?distance_sword_between_target + distance_sword:1e9;

    int distance_no_sword = visited[N - 1][M - 1]?visited [N - 1][M - 1] - 1:1e9;
    int min_distance = min(distance_having_sword, distance_no_sword);

    if(min_distance<=T) cout << min_distance;
    else cout << "Fail";
}