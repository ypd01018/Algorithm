#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,mat[10][10],zero_cnt,dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},check[10][10],mn=INT_MAX;
vector<pair<int,int>> v;
vector<pair<int,int>> five_v;

void print_test()
{
    cout << endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cout << check[i][j] << ' ';
        }
        cout << endl;
    }
}
void go(int a)
{

    if(a==v.size())
    {
        int cnt=0;

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(check[i][j]==0) cnt++;
            }
        }
        //print_test(); cout << cnt << endl;
        mn = min(cnt,mn);
        return;
    }

    int origin[10][10];
    memcpy(origin,check,sizeof(check));
    int y = v[a].first, x=v[a].second, num = mat[y][x];

    if(num==1)
    {
        for(int i=0;i<4;i++)
        {
            int ny = y, nx = x;
            while(1)
            {
                ny += dy[i]; nx += dx[i];
                if(ny < 0 || nx < 0 || ny >=N || nx >= M || mat[ny][nx]==6) break;
                check[ny][nx]=1;
            }
            go(a+1);
            memcpy(check,origin,sizeof(origin));
        }
    }
    else if(num==2)
    {
        for(int i=0;i<2;i++)
        {
            int ny = y, nx = x;
            while(1)
            {
                ny += dy[i]; nx += dx[i];
                if(ny < 0 || nx < 0 || ny >=N || nx >= M || mat[ny][nx]==6) break;
                check[ny][nx]=1;
            }
            ny = y; nx = x;
            while(1)
            {
                ny += dy[i+2]; nx += dx[i+2];
                if(ny < 0 || nx < 0 || ny >=N || nx >= M || mat[ny][nx]==6) break;
                check[ny][nx]=1;
            }
            go(a+1);
            memcpy(check,origin,sizeof(origin));
        }
    }
    else if(num==3)
    {
        for(int i=0;i<4;i++)
        {
            int ny = y, nx = x;
            while(1)
            {
                ny += dy[i]; nx += dx[i];
                if(ny < 0 || nx < 0 || ny >=N || nx >= M || mat[ny][nx]==6) break;
                check[ny][nx]=1;
            }
            ny = y; nx = x;
            while(1)
            {
                ny += dy[(i+1)%4]; nx += dx[(i+1)%4];
                if(ny < 0 || nx < 0 || ny >=N || nx >= M || mat[ny][nx]==6) break;
                check[ny][nx]=1;
            }
            go(a+1);
            memcpy(check,origin,sizeof(origin));
        }
    }
    else if(num == 4)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(j==i) continue;
                int ny = y, nx = x;
                while(1)
                {
                    ny += dy[j]; nx += dx[j];
                    if(ny < 0 || nx < 0 || ny >=N || nx >= M || mat[ny][nx]==6) break;
                    check[ny][nx]=1;
                }
            }

            go(a+1);
            memcpy(check,origin,sizeof(origin));
        }
    }
}
void five()
{
    for(int j=0;j<five_v.size();j++)
    {
        int y = five_v[j].first, x = five_v[j].second;
        for(int i=0;i<4;i++)
        {
            int ny = y, nx = x;
            while(1)
            {
                ny += dy[i]; nx += dx[i];
                if(ny < 0 || nx < 0 || ny >=N || nx >= M || mat[ny][nx]==6) break;
                check[ny][nx]=1;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> mat[i][j];

            if(mat[i][j]==0) zero_cnt++;
            else if(mat[i][j]==5) five_v.push_back({i,j});
            else if(mat[i][j]!=6) v.push_back({i,j});

            if(mat[i][j]!=0) check[i][j]=1;
        }
    }
    five();
    go(0);
    cout << mn;

}