#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,mat[5][5],check[5][5],dy[4]={0,0,1,1},dx[4]={0,1,0,1},mx,
weapon[4][4]={{1,2,0,1},{0,1,1,2},{1,0,2,1},{2,1,1,0}};
void print_()
{
    cout << "print\n";
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cout << check[i][j] << ' ';
        }cout << endl;
    }
}
void DFS(int y,int x,int total)
{
    if(y>=N)
    {
        mx = max(mx,total);
        // print_();
        return;
    }
    for(int i=0;i<5;i++)
    {
        if(i==4)
        {
            if(x+1>=M-1) DFS(y+1,0,total);
            else DFS(y,x+1,total);
            continue;
        }
        bool flag = true;
        int hap = 0;
        for(int j=0;j<4;j++)
        {
            int ny = y+dy[j], nx = x+dx[j];
            if(ny<0 || nx <0 || ny>=N || nx >=M || (weapon[i][j] && check[ny][nx])) 
            {
                flag = false; break;
            }
            hap += mat[ny][nx]*weapon[i][j];
        }
        if(!flag) continue;
        for(int j=0;j<4;j++) if(weapon[i][j]) check[y+dy[j]][x+dx[j]]=i+1;
        if(x+1>=M) DFS(y+1,0,total+hap);
        else DFS(y,x+1,total+hap);
        for(int j=0;j<4;j++) if(weapon[i][j]) check[y+dy[j]][x+dx[j]]=0;
    }
}
int main()
{   
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> mat[i][j];
        }
    }
    DFS(0,0,0);
    cout << mx;
}