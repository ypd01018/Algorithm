#include<bits/stdc++.h>
#define endl "\n"
#define mp make_pair 
#define f first
#define s second
using namespace std;
int N,mat[25][25],ans=INT_MAX,tot;
void go(int x, int y, int d1, int d2)
{
    if(y-d1<=0|| y+d2>N||x+d1+d2>N) return;
    int cnt[5]={0};
    //1번
    for(int i=1;i<x+d1;i++)
    {
        int a=0;
        if(i>=x) a = x-i-1;
        for(int j=1;j<=y+a;j++)
        {
            cnt[0] += mat[i][j];
        }
    }
    //2번
    for(int i=1;i<=x+d2;i++)
    {
        int a=0;
        if(i>=x) a=i-x; 
        for(int j=y+1+a;j<=N;j++)
        {
            cnt[1] += mat[i][j];
        }
    }
    //3번
    for(int i=x+d1;i<=N;i++)
    {
        int a;
        if(i<=x+d1+d2) a = y-d1+i-(x+d1);
        else a = y-d1+d2;
        for(int j=1;j<a;j++)
        {
            cnt[2] += mat[i][j];
        }
    }
    //4번
    for(int i=x+d2+1;i<=N;i++)
    {
        int a;
        if(i<=x+d1+d2) a = (y+d2)-(i-(x+d2+1));
        else a = y-d1+d2;
        for(int j=a;j<=N;j++)
        {
            cnt[3] += mat[i][j];
        }
    }
    cnt[4] = tot-cnt[0]-cnt[1]-cnt[2]-cnt[3];
    int mx = 0, mn = 1e9;
    for(int i=0;i<5;i++)
    {
        mx = max(mx,cnt[i]);
        mn = min(mn,cnt[i]);
    }
    ans = min(ans,mx-mn);
    go(x,y,d1+1,d2);
    go(x,y,d1,d2+1);
}
int main()
{
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> mat[i][j];
            tot += mat[i][j];
        }
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            go(i,j,1,1);
        }
    }

    cout << ans;

}