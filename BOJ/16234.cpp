#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
int N,L,R,mat[60][60],visited[60][60],total=0,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},cnt,cnt_day;
bool flag;
queue<pair<int,int>> q,q2;

void BFS()
{
    cnt=1;total=0;
    while(!q.empty())
    {
        
        int y,x; tie(y,x)=q.front(); q.pop();
        q2.push({y,x}); total += mat[y][x];
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0 && ny >=0 && nx <N && ny < N && !visited[ny][nx])
            {
                int dif=abs(mat[ny][nx]-mat[y][x]);
                if(dif< L || dif> R) continue;
                if(!flag)
                {
                    cnt_day++;
                    flag=true;
                }
                visited[ny][nx]=1;
                q.push({ny,nx});
                cnt++;
            }
        }

    }

    int avg = total / cnt;
    while(!q2.empty())
    {
        int y,x; tie(y,x) = q2.front(); q2.pop();
        mat[y][x]=avg;
    }
}

int main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);
    cin >> N >> L >> R;
    int tmp;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> tmp;
            mat[i][j]= tmp;
        }
    }

    while(1)
    {
        flag = false;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(!visited[i][j])
                {
                    visited[i][j]=1;
                    q.push({i,j});
                    
                    BFS();
                }
            }
        }
        
        if(!flag) break;

        memset(visited,0,sizeof(visited));
    }

    cout << cnt_day;

}