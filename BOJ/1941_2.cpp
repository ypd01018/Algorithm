#include<bits/stdc++.h>

using namespace std;
int mat[5][5],issued[5][5],ans,k,k2,check[5][5];
bool flag;
vector<pair<int,int>> v;

void DFS(int x, int y)
{
    if(k2==7)
    {
        flag=true;
        return;
    }
    
    int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
    for(int i = 0 ; i<4;i++)
    {
        if(x+dx[i]>0 && y+dy[i]>0 && x+dx[i]<5 && y+dy[i]<5)
        {
            if(issued[y+dy[i]][x+dx[i]] && !check[y+dy[i]][x+dx[i]])
            {
                check[y+dy[i]][x+dx[i]]=1;
                k2++;
                DFS(y+dy[i],x+dx[i]);
            }
        }
    }
}
void seven(int x, int y)
{
    
    if(k==7)
    {
        int _x,_y,n_Y=0;
        for(int i = 0 ; i < 7;i++)
        {
            tie(_x,_y) = v[i];
            if(mat[_y][_x]==0) n_Y++;
        }

        if(n_Y > 3) return;

        flag=false;
        DFS(_x,_y);
        if(flag == true) 
        ans++;
        return;

    }

    k++;
    issued[y][x]=1;
    v.push_back(make_pair(x,y));
    for(int i=0;i<5;i++)
    {
        for(int j = 0 ; j <5;j++)
        {
            if(!issued[i][j]) seven(i,j);
        }
    }
    k--;
    issued[y][x]=0;
    v.pop_back();
}


int main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);
    for(int i=0;i<5;i++)
    {
        string input;
        cin >> input;
        for(int j=0;j<5;j++)
        {
            if(input[j]=='S') mat[i][j] = 1; 
            else mat[i][j] =0; 
        }
    }

    for(int i = 0 ; i < 5; i ++)
    {
        for(int j = 0 ; j < 5 ; j ++)
        {
            k2=1;
            seven(j,i);
        }
    }

    cout <<ans;
}