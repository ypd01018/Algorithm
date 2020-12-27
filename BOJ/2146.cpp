#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
int N,mat[102][102],check[102][102],check2[102][102],dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},mn=200;
queue<pair<int,int>> q;
queue<pair<pair<int,int>,int>> q2;
void BFS()
{
    while(!q.empty())
    {
        int y,x; tie(y,x)=q.front(); q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx >= 0 && ny >=0 && nx <N && ny < N && mat[ny][nx] && !check[ny][nx])
            {
                check[ny][nx]=1;
                q.push({ny,nx});

                check2[ny][nx]=1;
                q2.push({{ny,nx},0});
                
            }   
        }

    }
}
void BFS2()
{
    while(!q2.empty())
    {
        int y,x,dis; tie(y,x)=q2.front().first; dis = q2.front().second; q2.pop();
        if(dis >= mn) continue;

        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx >= 0 && ny >=0 && nx <N && ny < N && mat[ny][nx] && !check[ny][nx] && !check2[ny][nx])
            {
                check2[ny][nx]=1;
                mn = min(mn,dis);
            }
            if(nx >= 0 && ny >=0 && nx <N && ny < N && !mat[ny][nx] && !check[ny][nx] && !check2[ny][nx])
            {
                check2[ny][nx]=1;
                q2.push({{ny,nx},dis+1});
            }   
        }
    }
}  
int main()
{
    cin >> N;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int tmp; cin >> tmp; mat[i][j]=tmp;
        }
        
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(mat[i][j] && !check[i][j])
            {
                q.push({i,j});
                q2.push({{i,j},0});
                check[i][j]=check2[i][j]=1;
                BFS();
                BFS2();
                memset(check2,0,sizeof(check2));
            }
        }
    }

    cout << mn;


}