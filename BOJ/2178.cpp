#include<iostream>
#define endl "\n"
#include<queue>
#define value first
#define check second
#define X first
#define Y second
using namespace std;
int x,y,dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1},cnt=-1,arr_d[101][101];
pair<int,int> arr[101][101];
queue<pair<int,int>> q;
string input;
void bfs();

int main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);

    cin >> y; cin >> x;
    for(int i=0;i<y;i++)
    {
        cin >> input;
        for(int j=0;j<x;j++)
        {
            arr[i][j].value=(int)(input[j]-48);
            arr[i][j].check = 0;
            arr_d[i][j]=-1;
        }
    }

    q.push(make_pair(0,0));
    arr[0][0].check=1;
    arr_d[0][0]=1;
    
    bfs();
    cout << arr_d[y-1][x-1];
}

void bfs()
{
    while(!q.empty())
    {
        auto co = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = co.X+dx[i], ny = co.Y+dy[i];
            if(nx > -1 && ny > -1 && nx < x && ny < y && arr[ny][nx].value == 1 && arr[ny][nx].check == 0)
            {
                arr[ny][nx].check = 1; 
                q.push(make_pair(nx,ny));
                arr_d[ny][nx]=arr_d[co.Y][co.X]+1;
            }
        }

    }
}