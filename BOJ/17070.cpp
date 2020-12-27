#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,mat[20][20],cnt,visit[20][20];

struct pipe_str
{
    int y_s=0,y=0;
    int x_s=0,x=1;
    int state=0;
    //0:가로 1:세로 2: 대각선
};
pipe_str pipe;
void print_test()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==pipe.y && j==pipe.x) cout << 3 << ' ';
            else cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
}
bool move_down()
{
    if(pipe.state==0) return false;
    int ny = pipe.y+1, nx = pipe.x;
    if(ny>=n || nx >=n || ny <0 || nx <0 || mat[ny][nx] || visit[ny][nx]) return false;
    pipe.y = ny; pipe.x=nx; pipe.state = 1;
    return true;
}
bool move_right()
{
    if(pipe.state==1) return false;
    int ny = pipe.y, nx = pipe.x+1;
    if(ny>=n || nx >=n || ny <0 || nx <0 || mat[ny][nx] || visit[ny][nx]) return false;
    pipe.y = ny; pipe.x=nx; pipe.state = 0;
    return true;
}
bool move_diag()
{
    int ny,nx;
    ny = pipe.y; nx = pipe.x+1;
    if(ny>=n || nx >=n || ny <0 || nx <0 || mat[ny][nx]|| visit[ny][nx]) return false;
    ny = pipe.y+1; nx = pipe.x;
    if(ny>=n || nx >=n || ny <0 || nx <0 || mat[ny][nx]|| visit[ny][nx]) return false;
    ny = pipe.y+1; nx = pipe.x+1;
    if(ny>=n || nx >=n || ny <0 || nx <0 || mat[ny][nx]|| visit[ny][nx]) return false;

    pipe.y = ny; pipe.x=nx; pipe.state = 2;
    return true;
}
void DFS()
{
    // cout << "y:" << pipe.y << "   x:" << pipe.x <<"    state:"<<pipe.state<<  endl;
    // print_test();

    if(pipe.y == n-1 && pipe.x==n-1)
    {
        cnt++;
        //cout << "cnt++" << endl;
        return;
    }

    visit[pipe.y][pipe.x]=1;
    int origin_y = pipe.y,origin_x = pipe.x,origin_state=pipe.state;
    if(move_down()) 
    {
        DFS();
        pipe.y = origin_y; pipe.x=origin_x; pipe.state=origin_state;
    }
    if(move_right()) 
    {
        DFS();
        pipe.y = origin_y; pipe.x=origin_x; pipe.state=origin_state;
    }
    if(move_diag()) 
    {
        DFS();
        pipe.y = origin_y; pipe.x=origin_x; pipe.state=origin_state;
    }

    visit[pipe.y][pipe.x]=0;
}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> mat[i][j];
        }
    }

    DFS();
    cout << cnt;
}