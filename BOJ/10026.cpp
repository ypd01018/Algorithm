#include<bits/stdc++.h>
#define endl "\n"
#define val first
#define check second
using namespace std;
int N,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},cnt[2];
pair<char,bool> mat[2][102][102];
queue<pair<int,int>> q[2];
void BFS(int a)
{
    while(!q[a].empty())
    {
        int y,x; tie(y,x)=q[a].front(); q[a].pop();
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i],ny=y+dy[i];
            if(nx >=0 && ny >= 0 && nx < N && ny < N && !mat[a][ny][nx].check && mat[a][ny][nx].val == mat[a][y][x].val)
            {
                mat[a][ny][nx].check=1;
                q[a].push({ny,nx});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);

    cin >> N;

    for(int i=0;i<N;i++)
    {
        string tmp; cin >> tmp;
        for(int j=0;j<N;j++)
        {
            mat[0][i][j].val = tmp[j];
            if(tmp[j]=='G') mat[1][i][j].val='R';
            else mat[1][i][j].val=tmp[j];
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<2;k++)
            {
                if(!mat[k][i][j].check)
                {
                    mat[k][i][j].check=1;
                    q[k].push({i,j});
                    BFS(k);
                    cnt[k]++;
                }
            }
        }
    }
    for(int i : cnt)
    cout << i << " ";
}