#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,mat[22][22],dy[2]={1,1},dx[2]={-1,1},y,x,l_b[22],r_b[22],ans=INT_MAX;
pair<int,int> yx[3];

bool lft(int n)
{
    yx[0].first = y+n;
    yx[0].second = x+(-1*n);
    if(yx[0].first < 1 || yx[0].first >N || yx[0].second < 1 || yx[0].second > N) return false;
    return true;
}
bool rght(int n)
{
    yx[1].first = y+n;
    yx[1].second = x+n;
    if(yx[1].first < 1 || yx[1].first >N || yx[1].second < 1 || yx[1].second > N) return false;
    return true;
}
bool dow(int r)
{
    yx[2].first = yx[0].first+r;
    yx[2].second = yx[0].second+r;
    if(yx[2].first < 1 || yx[2].first >N || yx[2].second < 1 || yx[2].second > N) return false;
    return true;
}
void go(int l,int r)
{
    if(!lft(l) || !rght(r) || !dow(r)) return;

    int val[6],mx=-1,mn=INT_MAX;
    memset(val,0,sizeof(val));
    l_b[y]=r_b[y]=x;
    for(int i=0;i<=l;i++)
    {
        l_b[y+i]=l_b[y]-i;
        r_b[y+r+i]=yx[1].second-i;
    }
    for(int i=0;i<=r;i++)
    {
        r_b[y+i]=r_b[y]+i;
        l_b[y+l+i]=yx[0].second+i;
    }


    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(i>=y && i<=yx[2].first && j>=l_b[i] && j <= r_b[i]){val[5] += mat[i][j];}
            else if(i<yx[0].first && j<=x){ val[1] += mat[i][j];}
            else if(i <= yx[1].first &&j > x){ val[2] += mat[i][j];}
            else if(i >= yx[0].first && j<yx[2].second){ val[3] += mat[i][j];}
            else if(i >yx[1].first && j >= yx[2].second){ val[4] += mat[i][j];}
        }
    }
    for(int i=1;i<=5;i++)
    {
        mx = max(mx,val[i]);
        mn = min(mn,val[i]);
    }
    ans = min(ans,mx-mn);
    if(y+l<=N && y+r<=N && x-l >0 && x+r<=N) go(l+1,r);
    if(y+l<=N && y+r<=N && x-l >0 && x+r<=N) go(l,r+1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> mat[i][j];
        }
    }
    
    for(int i=1;i<N-1;i++)
    {
        for(int j=2;j<N;j++)
        {
            y=i;
            x=j;
            go(1,1);
        }
    }

    cout << ans;
}