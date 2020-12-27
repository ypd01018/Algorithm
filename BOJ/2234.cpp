#include<bits/stdc++.h>
#define endl "\n"
#define mp make_pair
#define f first
#define s second
using namespace std;
int N,M,mat[90][90],visited[90][90],cnt,dy[4]={0,-1,0,1},dx[4]={-1,0,1,0},mx_size,numbering[90][90],two[4]={1,2,4,8},room_size[2600],mx_plus;
queue<pair<int,int> > q;
void BFS()
{
    int room_cnt=0;
    while(!q.empty())
    {
        int y = q.front().f, x=q.front().s; q.pop();
        numbering[y][x]=cnt+1;
        room_cnt++;
        for(int n=0;n<4;n++)
        {
            int ny = y+dy[n] , nx = x+dx[n];
            if(visited[ny][nx]||(mat[y][x]&two[n])) continue;
            visited[ny][nx]=1;
            q.push(mp(ny,nx));
        }
    }
    room_size[cnt+1] = room_cnt;
    mx_size = max(room_cnt,mx_size);
}
int main()
{
    cin >> M >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> mat[i][j];
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {  
            if(visited[i][j]) continue;
            visited[i][j]=1;
            q.push(mp(i,j));
            BFS();
            cnt++;
        }
    }

    mx_plus = mx_size;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {  
            for(int n=0;n<4;n++)
            {
                int ny = i+dy[n], nx = j+dx[n];
                if(ny<0 || nx<0 || ny >=N || nx >=M || numbering[i][j]==numbering[ny][nx]) continue;
                mx_plus = max(mx_plus, room_size[numbering[i][j]]+room_size[numbering[ny][nx]]);
            }
        }
    }
    cout << cnt << endl << mx_size << endl << mx_plus;  
}