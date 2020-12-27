#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,T,mat[102][102],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},mn=INT_MAX;
int visited[2][102][102];
struct a
{
    int y=0,x=0,gram=0,sec=0;
};
a hero;
queue<a> q;
a ret(int y, int x, int gram, int sec)
{
    a r;
    r.y=y; r.x=x; r.gram=gram; r.sec=sec;
    return r;
}
void print_test(int a)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cout << visited[a][i][j] << ' ';
        }
        cout << endl;
    }
}
void BFS()
{
    q.push(hero); visited[0][0][0]=1;
    while(!q.empty())
    {
        int y = q.front().y, x = q.front().x, gram = q.front().gram, sec = q.front().sec; q.pop();
        // cout << gram <<' '<< y<<' ' << x << ' '<< sec<< endl;
        for(int i=0;i<4;i++)
        {
            int ny = y+dy[i], nx = x+dx[i];
            if(sec<T && ny >=0 && nx >=0 && ny < N && nx < M && ( mat[ny][nx]!=1 || gram) && !visited[gram][ny][nx])
            {
                visited[gram][ny][nx]=sec+1;
                int origin = gram;
                if(mat[ny][nx]==2) 
                {
                    gram = 1;
                    visited[gram][ny][nx]=sec+1;;
                }
                if(ny==N-1 && nx==M-1){mn=min(sec+1,mn);}
                q.push(ret(ny,nx,gram,sec+1));
                gram = origin;
            }
        }
    }
    // cout << endl;
    // print_test(0);
    // cout << endl;
    // print_test(1);
}
int main()
{
    cin >> N >> M >> T;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> mat[i][j];
        }
    }
    BFS();
    if(mn==INT_MAX) cout << "Fail";
    else cout << mn;
}