#include<bits/stdc++.h>
#define endl "\n"
#define shark_num 100
using namespace std;
int dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,-1,-1,-1,0,1,1,1},mat[4][4],mx; 
struct fish_
{
    int y,x,d;
    bool life=true;
    int eat = 0;
}fish[17],shark;
void change_fish(int y, int x, int ny, int nx)
{
    int a = mat[y][x], b= mat[ny][nx];
    if(!b)
    {
        mat[ny][nx] = mat[y][x];
        mat[y][x]=0;
        fish[a].y=ny; fish[a].x=nx;
        return;
    }
    int a_y = fish[a].y, a_x = fish[a].x, b_y = fish[b].y, b_x = fish[b].x;
    fish[a].y = b_y; fish[a].x = b_x;
    fish[b].y = a_y; fish[b].x = a_x;
    mat[a_y][a_x] = b;
    mat[b_y][b_x] = a;
}
void copy_fish(fish_ &cpy_shark, fish_ cpy_fish[], int (*cpy_mat)[4])
{
    cpy_shark = shark;
    for(int i=1;i<=16;i++) cpy_fish[i] = fish[i];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++) cpy_mat[i][j]=mat[i][j];
    }
}
void paste_fish(fish_ &cpy_shark, fish_ cpy_fish[], int (*cpy_mat)[4])
{
    shark = cpy_shark;
    for(int i=1;i<=16;i++) fish[i] = cpy_fish[i];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++) mat[i][j]=cpy_mat[i][j];
    }
}
void fish_move()
{
    for(int i=1;i<=16;i++)
    {
        if(!fish[i].life) continue;
        int y = fish[i].y, x = fish[i].x,d=fish[i].d,ny,nx,nd; bool flag=false;
        for(int j=0;j<8;j++)
        {
            ny = y+dy[(fish[i].d+j)%8]; nx = x+dx[(fish[i].d+j)%8];
            if(ny <0 || nx <0 || ny>=4 || nx>=4 || mat[ny][nx]==shark_num) continue;
            flag = true; nd =(fish[i].d+j)%8;  break;
        }
        if(!flag) continue;
        fish[i].d = nd;
        change_fish(y,x,ny,nx);
    }
}
bool shark_move(int n)
{
    int ny = shark.y+n*dy[shark.d], nx = shark.x+n*dx[shark.d];
    if(ny<0 || nx<0 || ny>=4 || nx>=4) return false;
    if(!mat[ny][nx]) return false;
    shark.eat += mat[ny][nx]; fish[mat[ny][nx]].life = false; shark.d = fish[mat[ny][nx]].d;
    mat[shark.y][shark.x] = 0; shark.y = ny; shark.x = nx; mat[ny][nx]=shark_num;
    return true;
}
void DFS(int depth)
{
    int cpy_mat[4][4];
    fish_ cpy_fish[17],cpy_shark;
    fish_move();
    copy_fish(cpy_shark, cpy_fish, cpy_mat);
    int check=0;
    for(int n=1;n<4;n++)
    {
        bool flag = shark_move(n);
        if(!flag) {check++; continue;}
        DFS(depth+1);
        paste_fish(cpy_shark,cpy_fish, cpy_mat);
    }
    if(check==3)  mx = max(mx,shark.eat);
}
int main()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            int a,b;
            cin >> a >> b;
            fish[a].y=i; fish[a].x=j; fish[a].d=b-1;
            mat[i][j]=a;
        }
    }
    shark = fish[mat[0][0]]; shark.eat = mat[0][0];
    fish[mat[0][0]].life = false;
    mat[0][0]=shark_num;
    DFS(0);
    cout << mx;
}