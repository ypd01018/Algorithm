#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,mat[510][510],visited[510][510],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},mx;

void DFS(int y, int x, int cnt,int score){
    if(cnt==4){
        mx = max(score,mx);
        return;
    }

    visited[y][x] = 1;
    score += mat[y][x];
    for(int n=0;n<4;n++){
        int ny = y+dy[n], nx = x+dx[n];
        if(ny<0 || nx<0 || ny>=N || nx >=M || visited[ny][nx]) continue;
        DFS(ny,nx,cnt+1,score); 
    }
    visited[y][x]=0;
}

void edge(int y, int x){
    int score = mat[y][x],no=0;
    for(int n=0;n<4;n++){
        int ny = y+dy[n], nx = x+dx[n];
        if(ny <0 || nx<0 || ny>=N || nx>=M){
            no++;
            continue;
        }
        score += mat[ny][nx];
    }

    if(no>1) return;
    else if(no==1) mx = max(mx,score);
    else
        for(int n=0;n<4;n++) {
            int ny = y+dy[n], nx = x+dx[n];
            mx = max(mx,score-mat[ny][nx]);
        }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> mat[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            DFS(i,j,0,0);
            edge(i,j);
        }
    }
    cout << mx;
}