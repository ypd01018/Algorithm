#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int w,h,mat[52][52],visited[52][52],dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,-1,-1,-1,0,1,1,1};
void BFS(int y_, int x_)
{
    queue<pair<int,int>> q;
    q.push({y_,x_}); visited[y_][x_]=1;
    while(!q.empty())
    {
        int y = q.front().first, x = q.front().second; q.pop();
        for(int n=0;n<8;n++)
        {
            int ny = y +dy[n], nx = x+dx[n];
            if(ny<0 || nx<0 || ny>h || nx>w || !mat[ny][nx] || visited[ny][nx]) continue;
            visited[ny][nx]=1;
            q.push({ny,nx});
        }
    }
}
int sol()
{
    int ret=0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin >> mat[i][j];
            visited[i][j]=0;
        }
    }
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(visited[i][j] || !mat[i][j]) continue;
            BFS(i,j);
            ret++;
        }
    }
    return ret;
    
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    while(1) 
    { 
        cin >> w >> h;
        if(!w && !h) break;
        cout << sol() << endl;
    }
}