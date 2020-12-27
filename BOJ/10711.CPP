#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int H,W,mat[1002][1002],cpy[1002][1002],dy[8]={-1,-1,0,1,1,1,0,-1}, dx[8]={0,1,1,1,0,-1,-1,-1};
queue<pair<int,int>> q,erase_q,tmp;
bool wave()
{
    while(!q.empty())
    {
        int y = q.front().first, x = q.front().second; q.pop();
        int n_empty = 0;
        for(int n=0;n<8;n++)
        {
            int ny = y+dy[n], nx = x+dx[n];
            if(!mat[ny][nx]) n_empty++;
        }
        if(n_empty>=mat[y][x]) erase_q.push({y,x});
        else tmp.push({y,x});
    }
    if(erase_q.empty()) return false;

    while(!tmp.empty())
    {
        int y = tmp.front().first, x = tmp.front().second; tmp.pop();
        q.push({y,x});
    }
    while(!erase_q.empty())
    {
        int y = erase_q.front().first, x= erase_q.front().second; erase_q.pop();
        mat[y][x] = 0;
    }
    return true;
}
int main()
{
    cin >> H >> W;
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            char a; cin >> a;
            if(a=='.') mat[i][j] = 0;
            else 
            {
                q.push({i,j});
                mat[i][j] = a-'0';
            }
        }
    }
    int ans = 0;  
    while(1)
    {
        ans++;
        if(!wave()) break;
    }
    cout << ans-1 ;
}