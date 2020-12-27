#include<bits/stdc++.h>
#define endl "\n"
#define h first
#define down second
using namespace std;
int N,check[103][103],mx_cnt=1,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
pair<int,bool> mat[103][103];
queue<pair<int,int>> q;
void input()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int tmp; cin >> tmp;
            mat[i][j].h=tmp;
        }
    }
}
void reset(int a)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            check[i][j]=0;
            mat[i][j].down=false;
            if(mat[i][j].h <= a) mat[i][j].down=true;
        }
    }
    
}
void BFS()
{
    while(!q.empty())
    {
        int y,x; tie(y,x) = q.front(); q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i], ny = y+dy[i];
            if(nx >= 0 && ny >= 0 && nx < N && ny < N && !mat[ny][nx].down &&!check[ny][nx] )
            {
                check[ny][nx]=1;
                q.push({ny,nx});
            }
        }

    }
}
void sol()
{
    int cnt=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(!mat[i][j].down && !check[i][j])
            {
                check[i][j]=1;
                cnt++;
                q.push({i,j});
                BFS();
            }
        }
    }
    mx_cnt = max(cnt,mx_cnt);
}
int main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);

    input();

    for(int i=1;i<=100;i++)
    {
        reset(i);
        sol();
    }

    cout << mx_cnt;




}