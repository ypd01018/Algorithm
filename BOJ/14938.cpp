#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,r,item[102],dis[102][102],mx;
void print_test()
{
    cout << endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dis[i][j]==INT_MAX) cout << -1 << ' ';
            else cout << dis[i][j] <<' ';
        }
        cout << endl;
    } 
    cout << endl;
}
int main()
{
    cin >> n >> m >> r;
    for(int i=1;i<=n;i++)
    {
        cin >> item[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) dis[i][j]=0;
            else dis[i][j]=INT_MAX;
        }
    }

    for(int i=0;i<r;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        dis[a][b]=c; dis[b][a]=c;

    }

    for (int k = 1; k <= n; k++) 
    {
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                if(dis[i][k]==INT_MAX || dis[k][j]==INT_MAX) continue;
                if (dis[i][j] > dis[i][k] + dis[k][j]) 
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        int tot=0;
        for(int j=1;j<=n;j++)
        {
            if(dis[i][j]>m) continue;
            tot += item[j];
        }
        mx = max(mx,tot);
    }

    cout << mx;
}