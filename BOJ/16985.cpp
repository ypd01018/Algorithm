#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<int> arr = {0,1,2,3,4};
vector<vector<int>> mat[5];
int mn = 1e9,dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},dz[2]={-1,1};
void rotate_mat(int a)
{
    queue<int> q;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            q.push(mat[a][i][j]);
        }
    }
    for(int i=4;i>=0;i--)
    {
        for(int j=0;j<5;j++)
        {
            mat[a][j][i] = q.front(); q.pop();
        }
    }
}
int go_maze()
{
    if(mat[arr[0]][0][0]==1 || mat[arr[4]][4][4]==1) return 1e9;
    struct idx_
    {
        int x=0,y=0,z=0,cnt=0;
    }idx;
    int visited[5][5][5] = {0};
    visited[0][0][0]=1;
    queue<idx_> q;
    q.push(idx);
    while(!q.empty())
    {
        int z = q.front().z, y = q.front().y, x = q.front().x, cnt = q.front().cnt; q.pop();
        
        for(int n=0;n<4;n++)
        {
            int nz = z, ny = y+dy[n], nx = x+dx[n];
            if(nz<0 || nz >=5 || ny<0 || nx <0 || ny>=5 || nx>=5 || mat[arr[nz]][ny][nx] || visited[nz][ny][nx]) continue;
            visited[nz][ny][nx] = 1;
            if(nz==4 && ny == 4 && nx == 4) return cnt+1;
            idx_ new_idx; new_idx.y = ny; new_idx.x = nx; new_idx.z = nz; new_idx.cnt = cnt+1;
            q.push(new_idx);
        }
        for(int n=0;n<2;n++)
        {
            int nz = z+dz[n], ny = y, nx = x;
            if(nz<0 || nz >=5 || ny<0 || nx <0 || ny>=5 || nx>=5 || mat[arr[nz]][ny][nx] || visited[nz][ny][nx]) continue;
            visited[nz][ny][nx] = 1;
            if(nz==4 && ny == 4 && nx == 4) return cnt+1;
            idx_ new_idx; new_idx.y = ny; new_idx.x = nx; new_idx.z = nz; new_idx.cnt = cnt+1;
            q.push(new_idx);
        }
        
    }
    return 1e9;
}
void go(int a)
{
    if(a==5)
    {
        mn = min(mn,go_maze());
        return;
    }
    for(int i=0;i<4;i++)
    {
        go(a+1);
        rotate_mat(a);
    }
}
int main()
{
    for(int n=0;n<5;n++)
    {
        for(int i=0;i<5;i++)
        {
            vector<int> v_input; 
            for(int j=0;j<5;j++)
            {
                int a; cin >> a;
                if(a==1) a=0;
                else a=1;
                v_input.push_back(a);
            }
            mat[n].push_back(v_input);
        }
    }
    do
    {
        go(0);
    }while(next_permutation(arr.begin(),arr.end()));
    if(mn==1e9) cout << -1;
    else cout << mn;
}