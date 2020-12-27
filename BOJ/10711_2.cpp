#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int H,W,mat[1002][1002],dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1};
queue<pair<int,int>> q;
int main(){
    cin >> H >> W;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            char a; cin >> a;
            if(a=='.') q.push({i,j});
            else {
                mat[i][j] =  a-'0';
            }
        }
    }
    int cnt=0;
    while(1){
        int q_size = q.size();
        for(int i=0;i<q_size;i++){
            int y = q.front().first, x = q.front().second; q.pop();
            for(int n=0;n<8;n++){
                int ny = y+dy[n], nx = x+dx[n];
                if(ny<0 || nx<0 || ny>=H || nx>=W || mat[ny][nx]<=0) continue;
                mat[ny][nx]--;
                if(mat[ny][nx]== 0) q.push({ny,nx});
            }
        }
        if(q.empty()) break;
        cnt++;
        
    }
    cout << cnt;
}