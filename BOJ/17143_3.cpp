#include<bits/stdc++.h>
#define endl "\n"
#define mp make_pair
using namespace std;
int R,C,M,dy[5]={0,-1,1,0,0},dx[5]={0,0,0,1,-1};
struct shark_
{
    bool life = true;
    int r,c,s,d,z;
}shark[10010];
int King,mat[110][110],ans;
void find_shark(int c)
{
    for(int i=1;i<=R;i++)
    {
        int shark_num = mat[i][c];
        if(!shark_num) continue;
        mat[i][c]=0;
        shark[shark_num].life=false;
        ans += shark[shark_num].z;
        return;
    }
}
int d_reverse(int d)
{
    if(d==1) return 2;
    else if(d==2) return 1;
    else if(d==3) return 4;
    else return 3;
}
void move_shark()
{
    for(int i=1;i<=M;i++)
    {
        if(!shark[i].life) continue;
        mat[shark[i].r][shark[i].c]=0;
        int r=shark[i].r,c=shark[i].c,nr,nc;
        for(int j=0;j<shark[i].s;j++)
        {
            nr = r+dy[shark[i].d]; nc = c+dx[shark[i].d];
            if(nr<1 || nc<1 || nr>R || nc>C)
            {
                shark[i].d = d_reverse(shark[i].d);
                nr = r+dy[shark[i].d]; nc = c+dx[shark[i].d];
            }
            r = nr; c = nc;
        }
        shark[i].r = r; shark[i].c=c;
    }
    for(int i=1;i<=M;i++)
    {
        if(!shark[i].life) continue;
        int r = shark[i].r, c=shark[i].c;
        if(!mat[r][c]) mat[r][c] = i;
        else
        {
            int shark_a=mat[r][c], shark_b=i,die_shark,life_shark;
            if(shark[shark_a].z < shark[shark_b].z) 
            {
                die_shark = shark_a; 
                life_shark = shark_b;
            }
            else 
            {
                die_shark = shark_b;
                life_shark = shark_a;
            }
            shark[die_shark].life=false;
            mat[r][c] = life_shark;
        } 
    }
}
int main()
{
    cin >> R >> C >> M;
    for(int i=1;i<=M;i++)
    {
        cin >> shark[i].r >> shark[i].c >> shark[i].s >> shark[i].d >> shark[i].z;
        mat[shark[i].r][shark[i].c]=i; 
        if(shark[i].d==1 || shark[i].d==2) shark[i].s %= ((R*2)-2);
        else shark[i].s %=((C*2)-2);
    }
    for(int i=1;i<=C;i++)
    {
        find_shark(i);
        move_shark();
    }
    cout << ans;

}