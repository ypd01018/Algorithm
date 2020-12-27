#include<iostream>
#include<string>
#include<algorithm>
#define endl "\n"

using namespace std;
int R,C,N;
char mat[30100][32];
int mat_up[32];
struct stone_mat_
{
    int pre=0, check=0, nxt=0;
}stone_mat[30100][32];
void print_test()
{
    for(int i=R;i>0;i--)
    {
        for(int j=1;j<=C;j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }
}
int find_y(int y, int x)
{
    int ret_y=mat_up[x];
    for(ret_y; ret_y!=0;ret_y=stone_mat[ret_y][x].pre)
    {
        if(ret_y<=y) break;
    }
    return ret_y;
}
void stone_insert(int y, int x)
{
    mat[y][x]='O';
    stone_mat[y][x].check=1;
    stone_mat[y][x].nxt = stone_mat[y-1][x].nxt;
    stone_mat[y][x].pre = y-1;

    stone_mat[y-1][x].nxt = y;
    stone_mat[stone_mat[y][x].nxt][x].pre = y;
    mat_up[x]=max(y,mat_up[x]);
}
void go(int y,int x)
{
    if(y==0 || mat[y][x]=='X')
    {
        stone_insert(y+1,x);
        return;
    }
    if(mat[y][x]=='O')
    {
        if(x-1>0)
        {
            int new_y = find_y(y,x-1);
            if(new_y<y-1 || !new_y) 
            {
                go(new_y,x-1);
                return;
            }
        }
        if(x+1<=C)
        {
            int new_y = find_y(y,x+1);
            if(new_y<y-1 || !new_y)
            {
                go(new_y,x+1);
                return;
            }
        }
        stone_insert(y+1,x);
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> R >> C;

    for(int i=R;i>0;i--)
    {
        string a; cin >> a;
        for(int j=1;j<=C;j++)
        {
            mat[i][j]=a[j-1];
            if(mat[i][j]=='X') mat_up[j]=max(mat_up[j],i);
        }
    }

    for(int i=1;i<=C;i++)
    {
        int pre =0;
        for(int j=1;j<=R;j++)
        {
            if(mat[j][i]=='X')
            {
                stone_mat[pre][i].nxt=j;
                stone_mat[j][i].check=1;
                stone_mat[j][i].pre = pre;
                pre = j;
            }
        }
    }
    cin >> N;

    for(int i=0;i<N;i++)
    {
        int stone_x; cin >> stone_x;
        int stone_y = mat_up[stone_x];
        go(stone_y,stone_x);
    }
    print_test();
}