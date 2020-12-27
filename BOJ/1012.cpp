#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
int T,M,N,K,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1},n;
stack<pair<int,int>> stk;
queue<pair<int,int>> q;
pair<bool,bool> mat[60][60];


void input()
{
    int x,y;
    cin >> M >> N >> K;
    for(int i = 0 ; i < N ;i++)
    {
        for(int j = 0 ; j < M ;j++)
        {
            mat[i][j].first=0;
            mat[i][j].second=0;
        }
    }

    for(int i = 0 ; i <K; i++)
    {
        cin >> x >> y;
        mat[y][x].first=1;
    }

}

void sol()
{
    for(int i = 0 ; i < N ;i++)
    {
        for(int  j=0 ; j<M ;j++)
        {
            if(mat[i][j].f == 0 || mat[i][j].s == 1) continue; //배추지역이 아니거나(0) 이미 간곳이면(1) continue    

            n++;
            q.push(make_pair(i,j));
            mat[i][j].s=1;
            while(!q.empty())
            {
                auto cur = q.front();
                q.pop();
                for(int dir=0 ; dir<4;dir++)
                {
                    int nx = cur.s + dx[dir], ny = cur.f + dy[dir];
                    if(nx < 0 || nx >= M || ny < 0 || ny >=N ) continue;
                    if(mat[ny][nx].f == 0 || mat[ny][nx].s == 1) continue;
                    mat[ny][nx].s = 1;
                    q.push(make_pair(ny,nx));
                    //cout << "important:" << q.size() << endl;
                }
            }

        }
    }
}


int main()
{
    cin >> T;
    for(int i = 0 ; i < T;i++)
    {
        n=0;
        input();
        sol();
        cout << n << endl;
    }
}

