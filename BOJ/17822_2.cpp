#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,T,X,D,K,arr[55][55],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},sum,cnt;
deque<int> dq[55];
queue<pair<int,int>> q;

void make_dq()
{
    for(int i=1;i<=N;i++) dq[i].clear();

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            dq[i].push_back(arr[i][j]);
        }
    }
}
void rotate_left(int idx)
{
    for(int i=0;i<K;i++)
    {
        int tmp = dq[idx].front();
        dq[idx].push_back(tmp); dq[idx].pop_front();
    }
}
void rotate_right(int idx)
{
    for(int i=0;i<K;i++)
    {
        int tmp = dq[idx].back();
        dq[idx].push_front(tmp); dq[idx].pop_back();
    }
}
void rotate()
{
    for(int i=X;i<=N;i+=X)
    {
        if(D==0) rotate_right(i);
        else rotate_left(i);
    }
}
void make_arr()
{
    sum=0;cnt=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            arr[i][j]=dq[i].front();
            dq[i].pop_front();
            if(arr[i][j]!=INT_MIN) 
            {
                cnt++;
                sum += arr[i][j];
            }
        }
    }
}
void action_2()
{
    float avg;
    if(cnt== 0) return;

    if(sum == 0) avg=0;
    else avg = (float)sum/(float)cnt;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(arr[i][j]==INT_MIN) continue;
            
            if((float)arr[i][j]==avg) continue;

            if(arr[i][j]<avg) arr[i][j]++;
            else if(arr[i][j]>avg) arr[i][j]--;
        }
    }

}
void action()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(arr[i][j]==INT_MIN) continue;

            for(int n=0;n<4;n++)
            {
                int ny=i+dy[n],nx=j+dx[n];
                if(nx == 0) nx = M;
                else if(nx == M+1) nx=1;
                
                if(ny >=1 && nx >=1 && ny <= N && nx <= M && arr[i][j]==arr[ny][nx])
                {
                    q.push({i,j});
                    break;
                }
            }
        }
    }

    if(q.empty()) action_2();
    else
    {
        while(!q.empty())
        {
            pair<int,int> yx = q.front(); q.pop();
            arr[yx.first][yx.second]=INT_MIN;
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M >> T;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i=0;i<T;i++)
    {
        cin >> X >> D >> K;
        make_dq();
        rotate();
        make_arr();
        action();
    }

    sum=0;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(arr[i][j]!=INT_MIN) 
            {
                sum += arr[i][j];
            }
        }
    }

    cout << sum << endl;
}