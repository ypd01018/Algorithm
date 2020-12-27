#include<bits/stdc++.h>
using namespace std;
int N,M,dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};
char mat[21][21];
struct coin_
{
    vector<int> y,x;
    int cnt=0;
}coin;
queue<coin_> q;
int BFS()
{
    while(!q.empty())
    {
        vector<int> y = q.front().y, x = q.front().x; int cnt = q.front().cnt; q.pop();
        if(cnt>=10) return -1;
        for(int n=0;n<4;n++)
        {
            coin_ tmp; int check_cnt=0;
            for(int i=0;i<2;i++)
            {
                int ny = y[i]+dy[n], nx = x[i]+dx[n];
                if(ny<0 || nx<0 || ny >=N || nx>=M)
                {
                    check_cnt++;
                }
                if(mat[ny][nx]=='#')
                {
                    tmp.y.push_back(y[i]); tmp.x.push_back(x[i]);
                }
                else
                {
                    tmp.y.push_back(ny); tmp.x.push_back(nx);
                }
            }
            if(check_cnt==1) return cnt+1;
            else if(check_cnt==2) continue;
            tmp.cnt = cnt+1;
            q.push(tmp);
        }
    }
    return -1;
}
int main()
{
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> mat[i][j];
            if(mat[i][j]!='o') continue;
            coin.y.push_back(i);coin.x.push_back(j);
            mat[i][j]='.';
        }
    }

    q.push(coin);
    cout << BFS();
    
}