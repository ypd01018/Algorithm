#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int R,C,mat[10002][502],dy[3] = {-1,0,1}, dx[3] = {1,1,1} ,visit[10002][502],mx;
bool DFS(int y, int x, int r, int cnt){
    if(x==C-1) {
        cnt++;
        mx = max(cnt,mx);
        if(r<R-1) DFS(r+1,0,r+1,cnt);
        return true;
    }
    bool flag = false;
    for(int i=0;i<3;i++){
        int ny = y + dy[i], nx = x+ dx[i];
        if(ny<0 || nx<0 || ny>=R || nx>=C || mat[ny][nx] || visit[ny][nx]) continue;
        visit[ny][nx] = 1;
        flag = DFS(ny,nx,r,cnt);
        if(flag) break;
    }
    if(x==0 && r<R-1) return DFS(r+1,0,r+1,cnt);
    else return flag;
}
int main(){
    cin >> R >> C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            char a; cin >> a;
            mat[i][j] = (a =='x');
        }
    }
    DFS(0,0,0,0);
    cout << mx;
}