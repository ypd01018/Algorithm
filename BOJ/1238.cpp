#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,X,dis[1001][1001];

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M >> X;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(i==j) dis[i][j]=0;
            else dis[i][j]=1e9;
        }
    }
    for(int i=0;i<M;i++)
    {
        int a,b,c; cin >> a >> b >> c;
        dis[a][b]=c;
    }

    for (int k = 1; k <= N; ++k) 
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j) 
            {
                if (dis[i][j] > dis[i][k] + dis[k][j]) 
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    int mx = 0;
    for(int i=1;i<=N;i++)
    {
        mx = max(mx,dis[i][X]+dis[X][i]);
    }
    cout << mx;
}
