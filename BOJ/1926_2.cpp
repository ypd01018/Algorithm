#include<iostream>
#define endl "\n"
#include<queue>
using namespace std;

pair<int,int> ary[501][501];
queue<pair<int,int>> q;
int x,y,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},temp=0,best=0,pic_count=0;
void bfs();

int main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);

    cin >> y; 
    cin >> x;

    for(int i=0;i<y;i++)
    {
        for( int j=0; j<x;j++)
        {
            cin >> ary[i][j].first;
            ary[i][j].second=0;
        }
    }

    for(int i=0;i<y;i++)
    {
        for( int j=0; j<x;j++)
        {
            if(ary[i][j].first == 1 &&  ary[i][j].second==0 )
            {
                pic_count++;
                q.push(make_pair(j,i));
                ary[i][j].second = 1;
                bfs();
            }
        }
    }

    cout << pic_count << endl << best;

}

void bfs()
{
    temp = 0;
    while(!q.empty())
    {
        temp ++ ; 
        int temp_x = q.front().first,temp_y=q.front().second;
        q.pop();
        for(int i=0 ; i < 4 ; i++)
        {
            int nx = temp_x+dx[i], ny = temp_y+dy[i];
            if(nx>-1 && ny>-1 && nx < x && ny < y && ary[ny][nx].first==1 && ary[ny][nx].second==0)
            {
                ary[ny][nx].second=1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    if(temp > best) best = temp;

}