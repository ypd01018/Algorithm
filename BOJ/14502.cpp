#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,mat[10][10],copy_mat[10][10],dy[4]={1,0,-1,0},dx[4]={0,1,0,-1},mx;
bool visited[10][10],visit[10][10];
queue<pair<int,int>> q;

void BFS()
{
    memset(visited,0,sizeof(visited));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            copy_mat[i][j]=mat[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(copy_mat[i][j]!=2) continue;

            q.push({i,j});
            visited[i][j]=1;

            while(!q.empty())
            {
                int y=q.front().first,x=q.front().second; q.pop();
                for(int k=0;k<4;k++)
                {
                    int ny = y+dy[k],nx=x+dx[k];
                    if(ny >=0 && nx >=0 && ny < n && nx < m && copy_mat[ny][nx]==0 && !visited[ny][nx])
                    {
                        copy_mat[ny][nx]=2;
                        visited[ny][nx]=1;
                        q.push({ny,nx});
                    }
                }

            }
        }
    }
    int cnt=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(copy_mat[i][j]==0) cnt++;
        }
    }
    mx = max(cnt,mx);
}

void one_select(int y,int x,int cnt)
{
    
    if(cnt==3)
    {
        //if(mat[1][0]==1 && mat[0][1]==1 && mat[3][5]==1) cout << "can"<<endl;
        BFS();
        return;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==0)
            {
                mat[i][j]=1;
                //cout << "cnt:"<<cnt <<" i:"<<i <<" j:" << j << endl;
                one_select(i,j,cnt+1);
                mat[i][j]=0;
            }

        }
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> mat[i][j];
        }
    }

    one_select(0,0,0);
    cout << mx;



}