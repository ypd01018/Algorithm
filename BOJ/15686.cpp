#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,dy[4]={-1,0,1,0}, dx[4] = {0,1,0,-1};
int mat[51][51];
//bool visited[51][51];
int chicken[51][51],total_dis[51][51],total_dis_2[51][51];
priority_queue<pair<int,pair<int,int>>> pq;
queue<pair<pair<int,int>,int>> q;
void BFS()
{
    bool visited[51][51]={0,};
    int y,x; tie(y,x)=q.front().first;
    visited[y][x]=1;
    while(!q.empty())
    {
        tie(y,x)=q.front().first; int dis=q.front().second; q.pop();
        for(int i=0;i<4;i++)
        {
            int ny=y+dy[i],nx=x+dx[i];
            if(ny>=0 && nx >=0 && ny <N && nx < N && !visited[ny][nx])
            {
                visited[ny][nx]=1;
                if(mat[ny][nx]==2) total_dis[ny][nx] += dis+1;
                q.push({{ny,nx},dis+1});
            }
        }
    }
}
void BFS_2()
{
    bool visited[51][51]={0,};
    int y,x; tie(y,x)=q.front().first;
    visited[y][x]=1;
    cout << "y:" << y << " x:" <<x << " " << endl;
    while(!q.empty())
    {
        tie(y,x)=q.front().first; int dis=q.front().second; q.pop();
        for(int i=0;i<4;i++)
        {
            int ny=y+dy[i],nx=x+dx[i];
            cout << "ny:" << ny << " nx:" <<nx << " " << endl;
            if(ny>=0 && nx >=0 && ny <N && nx < N && !visited[ny][nx])
            {
                visited[ny][nx]=1;
                if(mat[ny][nx]==2) 
                {
                    cout <<"find" << endl;
                    total_dis_2[ny][nx] += dis+1;
                    return;
                }
                q.push({{ny,nx},dis+1});
            }
        }
    }
    cout <<"not fonund" << endl;
}
int main()
{
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> mat[i][j];
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(mat[i][j]==1) 
            {
                q.push({{i,j},0});
                BFS();
                while(!q.empty()) q.pop();
            }
        }
    }

    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(mat[i][j]==2) 
            {
                int dis_chi = total_dis[i][j];
                pq.push({(-1)*dis_chi,{i,j}});
            }
        }
    }
    int n=0;
    while(!pq.empty())
    {
        int ny,nx; tie(ny,nx) = pq.top().second;
        if(n>=M)
        {
            mat[ny][nx] = 0;
        }
        pq.pop();
        n++;
    }
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(mat[i][j]==1)
            {
                q.push({{i,j},0});
                BFS_2();
                while(!q.empty()) q.pop();
            }
        }
    }

    int total=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(mat[i][j]==2)
            {
                total += total_dis_2[i][j];
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        cout << endl;
        for(int j=0;j<N;j++)
        {
            cout << total_dis_2[i][j] <<" ";
        }
    }
        cout << total;

    /*
    for(int i=0;i<N;i++)
    {
        cout << endl;
        for(int j=0;j<N;j++)
        {
            cout << total_dis[i][j] << ' '; 
        }
        
    }
    */

    /*
    int total=0;
    for(int i=0;i<M;i++)
    {
        int ny,nx; tie(ny,nx) = pq.top().second; pq.pop();
        cout <<"ny:"<<ny<<" nx:"<<nx <<" chicken:" <<chicken[ny][nx] <<" total_dis:" << total_dis[ny][nx] << endl;
        total += total_dis[ny][nx];
    }
    cout << total;
    */
}