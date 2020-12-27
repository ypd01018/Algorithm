#include<bits/stdc++.h>
#define _y first
#define _x second
#define turn first
#define check second
using namespace std;
int T,L,dx[8]={2,1,-1,-2,-2,-1,1,2},dy[8]={1,2,2,1,-1,-2,-2,-1};
pair<int,int> origin,target,mat[302][302];
queue<pair<int,int>> q;
void input()
{
    
}
void sol()
{
    while(!q.empty())
    {
        int y,x; tie(y,x) = q.front(); q.pop();
        if(y == target._y && x == target._x) 
        {
            cout <<mat[y][x].turn<<endl;
            return;
        }
        for(int i=0;i<8;i++)
        {
            int nx = x+dx[i], ny = y +dy[i];
            if(nx >= 0 && ny >= 0 && nx <L && ny < L && !mat[ny][nx].check)
            {
                mat[ny][nx].check = 1;
                mat[ny][nx].turn = mat[y][x].turn+1;
                q.push({ny,nx});
            }
        }
    }
}
int main()
{
    cin >> T;
    for(int i=0;i<T;i++)
    {
        cin >> L;
        for(int j=0;j<L;j++)
        {
            for(int k=0;k<L;k++)
            {
                mat[j][k].turn=mat[j][k].check=0;
            }
        }
        cin >> origin._y >> origin._x >> target._y >> target._x;
        q.push({origin._y,origin._x});
        mat[origin._y][origin._x].check=1;
        sol();
        while(!q.empty()) q.pop();
    }
}