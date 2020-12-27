#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,mat[22][22],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},check[22][22],mx;
void go_up(int y, int x)
{
    int val = mat[y][x]; mat[y][x]=0;
    for(int i=y-1;i>=0;i--)
    {
        if(!mat[i][x]) continue;
        if(mat[i][x]==val && !check[i][x]) {mat[i][x]*=2; check[i][x]=1; mx = max(val*2,mx);}
        else mat[i+1][x] = val;
        return;
    }
    mat[0][x]=val;
}
void find_up()
{
    memset(check,0,sizeof(check));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            go_up(i,j);
        }
    }
}
void go_rght(int y, int x)
{
    int val = mat[y][x]; mat[y][x]=0;
    for(int i=x+1;i<N;i++)
    {
        if(!mat[y][i]) continue;
        if(mat[y][i]==val && !check[y][i]) {mat[y][i]*=2; check[y][i]=1;  mx = max(val*2,mx);}
        else mat[y][i-1] = val;
        return;
    }
    mat[y][N-1]=val;
}
void find_rght()
{
    memset(check,0,sizeof(check));
    for(int j=N-1;j>=0;j--)
    {
        for(int i=0;i<N;i++)
        {
            go_rght(i,j);
        }
    }
}
void go_down(int y, int x)
{
    int val = mat[y][x]; mat[y][x]=0;
    for(int i=y+1;i<N;i++)
    {
        if(!mat[i][x]) continue;
        if(mat[i][x]==val && !check[i][x]) {mat[i][x]*=2; check[i][x]=1; mx = max(val*2,mx);}
        else mat[i-1][x] = val;
        return;
    }
    mat[N-1][x]=val;
}
void find_down()
{
    memset(check,0,sizeof(check));
    for(int i=N-1;i>=0;i--)
    {
        for(int j=0;j<N;j++)
        {
            go_down(i,j);
        }
    }
}
void go_lft(int y, int x)
{
    int val = mat[y][x]; mat[y][x]=0;
    for(int i=x-1;i>=0;i--)
    {
        if(!mat[y][i]) continue;
        if(mat[y][i]==val && !check[y][i]) {mat[y][i]*=2; check[y][i]=1; mx = max(val*2,mx);}
        else mat[y][i+1] = val;
        return;
    }
    mat[y][0]=val;
}
void find_lft()
{
    memset(check,0,sizeof(check));
    for(int j=0;j<N;j++)
    {
        for(int i=0;i<N;i++)
        {
            go_lft(i,j);
        }
    }
}
void go(int n)
{
    if(n==5) return;
    int cpy[22][22];
    memcpy(cpy,mat,sizeof(mat));
    find_up(); 
    go(n+1);memcpy(mat,cpy,sizeof(mat));
    find_rght();
    go(n+1);memcpy(mat,cpy,sizeof(mat));
    find_down();
    go(n+1);memcpy(mat,cpy,sizeof(mat));
    find_lft();
    go(n+1);memcpy(mat,cpy,sizeof(mat));
}
int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> mat[i][j];
            mx = max(mat[i][j],mx);
        }
    }
    go(0);
    cout << mx;
}