#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int K,W,H,mat[210][210],horse_dy[8]={-2,-1,1,2,2,1,-1,-2},horse_dx[8]={-1,-2,-2,-1,1,2,2,1},dy[4]={-1,0,1,0},dx[4]={0,-1,0,1},mat_n[210][210][32];
struct monkey_
{
    int y=0,x=0,K_cnt=0,cnt=0;
};
queue<monkey_> q;
int BFS()
{
    monkey_ monkey;
    q.push(monkey);
    mat_n[0][0][0]=1;
    while(!q.empty())
    {
        monkey = q.front(); q.pop();
        int y = monkey.y, x=monkey.x;
        if(y==H-1 && x==W-1) return monkey.cnt;
        if(monkey.K_cnt<K)
        for(int n=0;n<8;n++)
        {
            int ny=monkey.y+horse_dy[n],nx=monkey.x+horse_dx[n];
            if(ny<0 || nx<0 || ny>=H || nx>=W || mat[ny][nx] || mat_n[ny][nx][monkey.K_cnt+1]) continue;
            mat_n[ny][nx][monkey.K_cnt+1]=1;
            monkey_ new_monkey; new_monkey.y = ny; new_monkey.x=nx; new_monkey.cnt=monkey.cnt+1; new_monkey.K_cnt=monkey.K_cnt+1;
            q.push(new_monkey);
        }
        for(int n=0;n<4;n++)
        {
            int ny=monkey.y+dy[n],nx=monkey.x+dx[n];
            if(ny<0 || nx<0 || ny>=H || nx>=W || mat[ny][nx] || mat_n[ny][nx][monkey.K_cnt]) continue;
            mat_n[ny][nx][monkey.K_cnt]=1;
            monkey_ new_monkey; new_monkey.y = ny; new_monkey.x=nx; new_monkey.cnt=monkey.cnt+1; new_monkey.K_cnt=monkey.K_cnt;
            q.push(new_monkey);
        }

    }
    return -1;
}
int main()
{
    cin >> K >> W >> H;
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            cin >> mat[i][j];
        }
    }
    int ans = BFS();
    if(ans==-1) cout << -1;
    else cout << ans;

}