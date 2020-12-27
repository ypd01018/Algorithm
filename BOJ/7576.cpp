#include<bits/stdc++.h>
<<<<<<< HEAD

using namespace std;
int M,N,mat[1002][1002];
queue<pair<int,int>> q;
int main()
{
    
    cin >> M >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int tmp;
            cin >> tmp;
            mat[i][j]=tmp;
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(mat[i][j]) q.push({i,j}); 
        }
    }
    
    




=======
#define endl "\n"
#define state first
#define day second
using namespace std;
queue<pair<int,int>> q;
int row,col,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},n_tomato[1002];
pair<int,int> mat[1002][1002];
int main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);

    cin >> row >> col;
    for(int i=0;i<col;i++)
    {
        for(int j=0;j<row;j++)
        {
            int tmp;
            cin >> tmp;
            mat[i][j].state=tmp;
            if(tmp == 1) q.push({i,j});
            if(tmp == 0) n_tomato[i]++;
        }
    }
    int max_day=0;
    while(!q.empty())
    {
        int y,x;
        tie(y,x) = q.front(); q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if( nx >= 0 && nx < row && ny >= 0 && ny < col && mat[ny][nx].state==0)
            {
                mat[ny][nx].state = 1;
                n_tomato[ny]--;
                mat[ny][nx].day = mat[y][x].day+1;
                max_day = max(max_day,mat[ny][nx].day);
                q.push({ny,nx});
            }
        }
    }
    int flag = true;
    for(int i=0;i<col;i++)
    {
        if(n_tomato[i]==0) continue;
        flag = false;
        cout <<"-1";
        break; 
    }
    if(flag) cout << max_day;
>>>>>>> c970bb23ae158ddb0c279d0af13d5172eedb711b
}