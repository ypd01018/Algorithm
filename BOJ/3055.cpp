#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int R,C,goal_y,goal_x,sec,dy[4]={1,0,-1,0},dx[4]={0,1,0,-1},day=0,d[60][60][2];
char mat[60][60];
bool visited_w[60][60],visited_s[60][60];
queue<pair<pair<int,int>,int>> s_q,water;
void test_s_day()
{
    cout << endl;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cout << d[i][j][1]<<" ";
        }
        cout << endl;
    }
}
void print_mat()
{
    cout << endl;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }
}

void BFS()
{
    
    int y,x;

    while(1)
    {
        while(!water.empty())
        {
            int w_day=water.front().second;
            if(w_day!=day) break;
            tie(y,x) = water.front().first; water.pop();
            for(int i=0;i<4;i++)
            {    
                int ny=y+dy[i],nx=x+dx[i];
                if(ny <0 || nx <0 || ny >= R || nx >= C || visited_w[ny][nx] || mat[ny][nx]=='D'|| mat[ny][nx]=='X') continue;
                water.push({{ny,nx},w_day+1});
                mat[ny][nx]='*';
                visited_w[ny][nx]=1;
                d[ny][nx][0] = d[y][x][0]+1;
            } 
        }
        while(!s_q.empty())
        {

            if(s_q.front().second!=day) break;
            tie(y,x) = s_q.front().first; s_q.pop();
            for(int i=0;i<4;i++)
            {    
                int ny=y+dy[i],nx=x+dx[i];
                if(ny <0 || nx <0 || ny >= R || nx >= C || visited_s[ny][nx] ||mat[ny][nx]=='*' || mat[ny][nx]=='X') continue;
                if(mat[ny][nx]=='D')
                {
                    cout << d[y][x][1]+1;
                    return;
                }
                s_q.push({{ny,nx},d[y][x][1]+1});
                mat[ny][nx]='S';
                visited_s[ny][nx]=1;
                d[ny][nx][1] = d[y][x][1]+1;
            } 
        }
        day++;
        if(s_q.empty()) 
        {   
            cout <<"KAKTUS";
            return;
        }
    }
}
int main()
{
    cin >> R >> C;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin >> mat[i][j];
            if(mat[i][j]=='D')
            {
                goal_y=i;goal_x=j;
            }
            else if(mat[i][j]=='S')
            {
                visited_s[i][j]=1;
                s_q.push({{i,j},0});
            }
            else if(mat[i][j]=='*')
            {
                visited_w[i][j]=1;
                water.push({{i,j},0});
            }
        }
    }

    BFS();



}