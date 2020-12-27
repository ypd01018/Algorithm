#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int N,M,mat[500][500],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},visit[500][500];
vector<pair<int,int>> tmp,processing;
queue<pair<int,pair<int,int>>> q;
queue<pair<int,int>> q_local;

void go(){
    processing = tmp;
    tmp.clear();
    for(int i=0;i<processing.size();i++){
        int y = processing[i].first, x = processing[i].second;
        int cnt = mat[y][x];
        for(int n=0;n<4;n++){
            int nx = x+dx[n], ny = y+dy[n];
            if(ny<0||nx<0||ny>=N||nx>=M||mat[ny][nx]) continue;
            cnt--;
        }
        if(cnt<0) cnt=0;
        q.push({cnt,{y,x}});
        if(cnt) tmp.push_back({y,x});
    }
    while(!q.empty()){
        int y = q.front().second.first, x= q.front().second.second , cnt = q.front().first; q.pop();
        mat[y][x] = cnt;
    }

}

bool BFS(){
    memset(visit,0,sizeof(visit));
    int cnt = 0;
    for(int i=1;i<N-1;i++){
        for(int j=1;j<M-1;j++){
            if(visit[i][j] || !mat[i][j]) continue;
            cnt++;
            if(cnt>1) return true;
            q_local.push({i,j});
            visit[i][j]=1;
            while(!q_local.empty()){
                int y = q_local.front().first , x = q_local.front().second; q_local.pop();
                for(int n=0;n<4;n++){
                    int ny = y+dy[n], nx = x+dx[n];
                    if(!mat[ny][nx] || visit[ny][nx]) continue;
                    visit[ny][nx] = 1;
                    q_local.push({ny,nx});
                }
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++) {
            cin >> mat[i][j];
            if(mat[i][j]) tmp.push_back({i,j});
        }
    }
    int year = 0;
    if(!tmp.size()) {cout << 0; return 0;}
    while(tmp.size()) {
        year++;
        go();
        if(BFS()) {
            cout << year;
            return 0;
        }
    }
    cout << 0;
}