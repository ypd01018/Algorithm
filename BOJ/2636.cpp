#include<iostream>
#include<queue>
#include<memory.h>
#define mp make_pair
#define f first 
#define s second
using namespace std;
int N,M,mat[102][102],visited[102][102],check[102][102],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},chese,hour;
queue<pair<int,int> > q;
void BFS()
{
    bool flag = false;
    vector<pair<int,int> > cache;
    while(!q.empty())
    {
        int y=q.front().f, x=q.front().s; q.pop(); cache.push_back(mp(y,x));
        for(int i=0;i<4;i++)
        {
            int ny = y+dy[i],nx=x+dx[i];
            if(ny>=0 && nx >=0 && ny <N && nx < M)
            {
                if(!mat[ny][nx] && !visited[ny][nx])
                {
                    visited[ny][nx]=1;
                    q.push(mp(ny,nx));
                }
            }
            else flag = true;
        }
    }
    if(!flag)
    {
        for(int i=0;i<cache.size();i++)
        {
            check[cache[i].first][cache[i].second]=1;
        }
    }

}
void check_pruf()
{
    memset(visited,0,sizeof(visited));
    memset(check,0,sizeof(check));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(!mat[i][j] && !visited[i][j]) 
            {
                q.push(mp(i,j)); visited[i][j]=1;
                BFS();
            }
        }
    }
}
void chese_check()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(mat[i][j])
            {
                int cnt=0;
                for(int n=0;n<4;n++)
                {
                    int ny=i+dy[n], nx=j+dx[n];
                    if(ny>=0 && nx >=0 && ny <N && nx < M)
                    {
                        if(!mat[ny][nx] && !check[ny][nx]) cnt++;
                    }
                    else cnt++;
                }
                if(cnt>=1) q.push(mp(i,j));
            }
        }
    }

}
void chese_melt()
{
    while(!q.empty())
    {
        int y = q.front().f, x=q.front().s; q.pop();
        mat[y][x]=0; chese--;
    }
}
void one_hour()
{
    check_pruf();
    chese_check();
    chese_melt();
    hour++;
}
int main()
{
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> mat[i][j];
            if(mat[i][j]) chese++;
        }
    }
    int cache;
    while(chese)
    {
        cache=chese;
        one_hour();
    }
    cout << hour<< endl;
    cout << cache;
}
