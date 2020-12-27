#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,mat[12][12],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},mn=INT_MAX;
queue<pair<int,int>> bridge_q;
bool able_check(int y, int x){
    int cnt = 0;
    for(int n=0;n<4;n++){
        int ny = y+dy[n], nx = x + dx[n];
        int nny = y+dy[(n+1)%4], nnx = x +dx[(n+1)%4];
        if(ny<0 || nx <0 || ny>=N || nx >= N || mat[ny][nx]==1) continue;
        if(nny<0 || nnx <0 || nny>=N || nnx >= N || mat[nny][nnx]==1) continue;
        return false;
    }
    return true;
}

int BFS(){
    queue<pair<pair<int,int>,int>> q;
    int visit[12][12]={0}; 
    visit[0][0] = 1;
    q.push({{0,0},0});
    while(!q.empty()){
        int y = q.front().first.first, x = q.front().first.second, sec = q.front().second; q.pop();
        if(y==N-1 && x==N-1) return sec;

        for(int n=0;n<4;n++){
            int ny = y+dy[n], nx = x+dx[n];
            if(ny <0 || nx<0 || ny >=N || nx >= N ||!mat[ny][nx]|| visit[ny][nx] || (mat[ny][nx]>1 && mat[y][x]>1)) continue;
            if(mat[ny][nx]==1 || (mat[ny][nx]>1 && !(sec+1)%mat[ny][nx])) {
                q.push({{ny,nx},sec+1});
                visit[ny][nx] = sec+1;
            }
            else q.push({{y,x},sec+1});
        }
    }
    return INT_MAX;
}
int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> mat[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!mat[i][j] && able_check(i,j)) bridge_q.push({i,j});
        }
    }
    while(!bridge_q.empty()){
        int y = bridge_q.front().first, x =bridge_q.front().second; bridge_q.pop();
        mat[y][x] = M;
        mn = min(BFS(),mn);
        mat[y][x] = 0;
    }
    cout << mn ; 

}