#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int R,C,dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},mx=1;
char mat[30][30];
int check[30];

void DFS(int y, int x,int n)
{
    for(int i=0;i<4;i++)
    {
        int ny = y+dy[i], nx=x+dx[i];
        if(ny<0 || nx<0 || ny >= R || nx >= C || check[mat[ny][nx]-'A']) continue;
        mx = max(mx,n+1); check[mat[ny][nx]-'A']=1; if(mx==26) return;
        DFS(ny,nx,n+1);
        check[mat[ny][nx]-'A']=0;
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> R >> C;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin >> mat[i][j];
        }
    }
    check[mat[0][0]-'A']=1;
    DFS(0,0,1);
    cout << mx;


}