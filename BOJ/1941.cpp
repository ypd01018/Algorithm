#include<bits/stdc++.h>

using namespace std;
int mat[5][5],n_Y,k,issued[5][5],ans, dx[3] = {1, 0, -1}, dy[3]={0,1,0};

void seven(int x, int y)
{
 // cout <<"y:" << y<<" x:" <<x <<"  k:"<< k << endl;
    if(k == 7)
    {
        ans++;
        return;
    }

    if(mat[y][x] == 0 && n_Y ==3)
    {
        return;
    }
            
    for(int i = 0; i < 3 ; i++)
    {
        if(x+dx[i] > -1 && x+dx[i] < 5 && y+dy[i] < 5 && !issued[y+dy[i]][x+dx[i]] )
        {
            if(mat[y][x] == 0) n_Y++;
            issued[y][x] = 1;
            k++;
            seven(x+dx[i],y+dy[i]);
            if(mat[y][x] == 0) n_Y--;
            issued[y][x] = 0;
            k--;
        }
    }
    
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
            seven(j,i);
        }
    }

    cout <<ans;
}