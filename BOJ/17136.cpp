#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int mat[10][10],ans,mn=INT_MAX,use[5];
vector<pair<int,int>> where[5];

bool is_ok()
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {   
            if(mat[i][j]) return false;
        }
    }
    return true;
}
int total_use()
{
    int total = 0;
    for(int i=0;i<5;i++) total += use[i];
    return total;
}
void go(int a)
{
    int y = a/10, x= a%10;
    if(a==100)
    {
        if(is_ok()) mn = min(total_use(),mn);
        return;
    }

    if(!mat[y][x])
    {
        go(a+1);
        return;
    }

    for(int n=4;n>=0;n--)
    {
        int cpy[10][10];
        if(use[n]>=5) continue;
        
        int ny = y + n , nx = x + n;
        if(ny>=10 || nx >= 10) continue;
        memcpy(cpy,mat,sizeof(mat));
        bool flag = true;

        for(int i=y;i<=ny;i++)
        {
            for(int j=x;j<=nx;j++)
            {
                if(!mat[i][j])
                {
                    flag = false;
                    break;
                }
                mat[i][j] = 0;
            }
            if(!flag) break;
        }
        if(flag) 
        {
            use[n]++;
            go(a+1);
            use[n]--;
        }
        memcpy(mat,cpy,sizeof(mat));
    }
}
int main()
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cin >> mat[i][j];
        }
    }
    go(0);
    if(mn==INT_MAX) cout << -1;
    else cout << mn;
}