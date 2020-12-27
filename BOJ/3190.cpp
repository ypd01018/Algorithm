#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,K,mat[110][110],L,d=0,dy[4]={0,1,0,-1},dx[4]={1,0,-1,0},sec,snake_mat[102][102],y=1,x=1;
queue<pair<int,char>> q;
deque<pair<int,int>> dq;
void l_cmd()
{
    if(d>0) d--;
    else d=3; 
}
void d_cmd()
{
    if(d<3) d++;
    else d=0;
}
void print_test()
{
    cout<< "sec:"<<sec << endl;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cout << snake_mat[i][j]<<' ';
        }
        cout << endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> K;
    for(int i=0;i<K;i++)
    {
        int r,c;
        cin >> r >> c;
        mat[r][c]=1;
    }
    cin >> L;
    for(int i=0;i<L;i++)
    {
        int a;char b;
        cin >> a >> b;
        q.push({a,b});
    }
    dq.push_back({1,1});
    snake_mat[1][1]=1;
    while(1)
    {
        sec++;
        //print_test();
        y += dy[d]; x += dx[d];
        if(snake_mat[y][x] || y<1 || x<1 || y>N || x> N) break;
        dq.push_back({y,x});
        snake_mat[y][x]=1;
        if(!mat[y][x])
        {
            int del_y=dq.front().first, del_x = dq.front().second; dq.pop_front();
            snake_mat[del_y][del_x]=0;
        }
        else
        {
            mat[y][x]=0;
        }
        

        if(!q.empty() && sec == q.front().first)
        {
            if(q.front().second=='L') l_cmd();
            else d_cmd();
            q.pop();
        }
    }
    cout << sec;
}