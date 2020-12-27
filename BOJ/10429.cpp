#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},visited[3][3];
char mat[3][3];
vector<pair<int,int>> v;
int plmi()
{
    int y = v.back().first, x = v.back().second;
    if(mat[y][x]=='+') return 1;
    else return -1;
}
void DFS(int y, int x, int a,int val)
{
    if('0'<=mat[y][x] && mat[y][x]<='9')
    {
        if(v.empty()) val += mat[y][x] - '0';
        else val += plmi()*(mat[y][x]-'0');
    }
    v.push_back({y,x});
    if(a==2*M-1)
    {
        if(val==N)
        {
            cout <<1 <<endl;
            for(int i=0;i<v.size();i++) cout << v[i].first << ' ' << v[i].second << endl;
            exit(0);
        }
    }
    else
    {
        for(int n=0;n<4;n++)
        {
            int ny = y+dy[n], nx = x+dx[n];
            if(ny<0 || nx<0 || ny>=3 || nx >=3 || visited[ny][nx]) continue;
            visited[ny][nx]=1;
            DFS(ny,nx,a+1,val);
            visited[ny][nx]=0;
        }
    }
    v.pop_back();
    return;
    
    
}
int main()
{
    cin >> N >> M;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >> mat[i][j];
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            visited[i][j]=1;
            if('0'<=mat[i][j] && mat[i][j]<='9') DFS(i,j,1,0);
            visited[i][j]=0;
        }
    }
    cout << 0;

}