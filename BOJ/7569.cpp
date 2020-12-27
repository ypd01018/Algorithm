#include<bits/stdc++.h>
#define endl "\n"
#define state first
#define day second
using namespace std;
int col,row,high,dz[6]={1,-1,0,0,0,0},dx[6]={0,0,0,1,0,-1},dy[6]={0,0,1,0,-1,0},n_tomato[102];
pair<int,int> mat[102][102][102];
queue<pair<int,pair<int,int>>> q;
int main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);
    cin >> row >> col >> high;
    for(int i=0;i<high;i++)
    {
        for(int j=0;j<col;j++)
        {
            for(int k=0;k<row;k++)
            {
                int tmp;
                cin >> tmp;
                mat[i][j][k].state=tmp;
                if(mat[i][j][k].state==1) q.push({i,{j,k} }); 
                if(mat[i][j][k].state==0) n_tomato[i]++;
            }
        }
    }

    int max_day=0;
    while(!q.empty())
    {
        int x,y,z;
        z = q.front().first;
        tie(y,x) = q.front().second;
        q.pop();
        for(int i=0;i<6;i++)
        {
            int nz,ny,nx;
            nz = z+dz[i]; ny = y+dy[i]; nx = x+dx[i];
            if(nz >= 0 && ny >= 0 && nx >= 0 && nz < high && ny < col && nx < row && mat[nz][ny][nx].state == 0)
            {
                mat[nz][ny][nx].state=1;
                mat[nz][ny][nx].day = mat[z][y][x].day+1;
                max_day = max(mat[nz][ny][nx].day,max_day);
                n_tomato[nz]--;
                q.push({nz,{ny,nx}});
            }
        }
    }


    bool flag = true;
    for(int i = 0; i < high ; i++)
    {
        if(n_tomato[i]==0) continue;    
        flag = false;
        cout << "-1";
        break;
    }
    if(flag) cout << max_day;

}