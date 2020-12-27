#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int mat[10][10],paper[6],mn=1e9;
int check[10][10],cnt,check_cnt;
vector<pair<int,int>> v;

bool stiky(int y, int x,int n)
{
    n--;
    if(y+n>=10 || x+n >=10) return false; 
    for(int i=y;i<=y+n;i++)
    {
        for(int j=x;j<=x+n;j++)
        {
            if(!mat[i][j] || check[i][j]) return false;
        }
    }
    for(int i=y;i<=y+n;i++)
    {
        for(int j=x;j<=x+n;j++)
        {
            check[i][j]=1;
        }
    }
    return true;
}
void go(int a)
{
    if(a==v.size())
    {
        int hap=0;
        for(int i=1;i<=5;i++) {hap+=paper[i];}
        mn = min(hap,mn);
        return;
    }
    if(check[v[a].first][v[a].second]) 
    {
        go(a+1);
        return;
    }
    for(int i=1;i<=5;i++)
    {
        int check_origin[10][10]; memcpy(check_origin,check,sizeof(check));
        if(paper[i]<5 && stiky(v[a].first,v[a].second,i)) 
        {
            paper[i]++;
            go(a+1);
            paper[i]--;
            memcpy(check,check_origin,sizeof(check));
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cin >> mat[i][j];
            if(mat[i][j]) 
            {
                cnt++;
                v.push_back({i,j});
            }
        }
    }
    go(0);
    if(mn==1e9) cout << -1;
    else cout << mn;
}