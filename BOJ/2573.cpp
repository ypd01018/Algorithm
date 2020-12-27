#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,mat[302][302],visited[302][302],dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0},down[302][302],cnt=1,n=0,zeros_check[302][302];
queue<pair<int,int>> q,zeros;
void BFS()
{
    while(!q.empty())
    {
        int y,x; tie(y,x) = q.front(); q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(ny>0 && nx > 0 && ny <N-1 && nx < M-1 && mat[ny][nx] && !visited[ny][nx])
            {
                visited[ny][nx]=1;
                q.push({ny,nx});
            }
        }
    }
}
void next_year()
{   
    while(!zeros.empty())
    {
        int y,x; tie(y,x) = zeros.front(); zeros.pop();
        zeros_check[y][x]=1;
        for(int i=0;i<4;i++)
        {
            int ny = y+dy[i], nx = x+dx[i];
            if(ny >= 0 && nx >=0 && ny <N && nx < M)
            {
                down[ny][nx]--;
            }
        }
    }

    for(int i=1;i<N-1;i++)
    {
        for(int j=1;j<M-1;j++)
        {
            mat[i][j] += down[i][j];
            if(mat[i][j] <= 0)
            {   
                mat[i][j]=0;
                if(!zeros_check[i][j]) zeros.push({i,j});
            }
        }
    }

}
void sol()
{
    while(1)
    {
        cnt=0;
        memset(visited,0,sizeof(visited));
        for(int i=1;i<N-1;i++)
        {
            for(int j=1;j<M-1;j++)
            {
                if(mat[i][j] && !visited[i][j])
                {
                    visited[i][j]=1;
                    q.push({i,j});
                    BFS();
                    cnt++;  
                }

                if(cnt>1) 
                {
                    cout << n;
                    return;
                }
            }
        }
        if(cnt==0) 
        {
            cout << 0;
            return;
        }
        next_year();
        n++;
    }

}
int main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int tmp;
            cin >> tmp;
            mat[i][j]=tmp;
            if(tmp==0) zeros.push({i,j});
        }
    }
    sol();
}