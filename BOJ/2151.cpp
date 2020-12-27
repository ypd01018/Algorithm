#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},cnt[60][60][2],visit[60][60][2],mn=INT_MAX;
char mat[60][60];
vector<pair<int,int>> door;
queue<pair<int,pair<int,int>>> q;
void print_test()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout << cnt[i][j][0]<<' ';
        }
        cout << endl;
    }
    cout << endl;
        for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout << cnt[i][j][1]<<' ';
        }
        cout << endl;
    }

}
int dir(int a)
{
    if(a==0 || a==2) return 0;
    return 1;
}
int diff(int a)
{
    if(a==0 || a==2) return 1;
    return 0;
}
void mirror(int y, int x, int d)
{
    for(int i=d;i<4;i+=2)
    {
        int ny = y+dy[i], nx=x+dx[i];
        while(ny>=0 && nx >=0 && ny <N && nx<N && mat[ny][nx]!='*')
        {
            if(ny == door[1].first && nx == door[1].second)
            {
                mn=min(mn,cnt[y][x][dir(d)]);
            }
            else if(mat[ny][nx]=='!' && !visit[ny][nx][diff(d)])
            {
                cnt[ny][nx][diff(d)] = cnt[y][x][dir(d)]+1;
                visit[ny][nx][diff(d)]=1;
                q.push({diff(d),{ny,nx}});
            }
            ny += dy[i]; nx += dx[i];
        }
    }
}
void go()
{
    while(!q.empty())
    {
        int d = q.front().first, y=q.front().second.first, x=q.front().second.second; q.pop();
        mirror(y,x,d);
    }
}
int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> mat[i][j];
            if(mat[i][j]=='#') door.push_back({i,j});
        }
    }
    pair<int,int> yx = door[0];
    q.push({0,{yx.first,yx.second}});
    q.push({1,{yx.first,yx.second}});
    go();
    print_test();
    cout << mn;
}