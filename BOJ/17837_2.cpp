#include<bits/stdc++.h>
#define endl "\n"
#define f first
#define s second
#define mp make_pair
using namespace std;
int N,K,mat[15][15],dy[5]={0,0,0,-1,1},dx[5]={0,1,-1,0,0};
vector<int> v_mat[15][15];
struct horse_
{
    int y,x,d;
};
horse_ horse[12];
int reverse_d(int d)
{
    if(d==1) return 2;
    else if(d==2) return 1;
    else if(d==3) return 4;
    else return 3;
}
bool blue(int num)
{
    int y = horse[num].y, x = horse[num].x;
    horse[num].d = reverse_d(horse[num].d);
    int ny = y +dy[horse[num].d], nx = x+dx[horse[num].d];
    if(ny<1 || nx<1 || ny>N || nx > N|| mat[ny][nx]==2) return false;
    return true;
}
void move(int num, bool reverse_flag)
{
    int y = horse[num].y, x = horse[num].x,i,check;
    for(i=0;i<v_mat[y][x].size();i++)if(v_mat[y][x][i]==num) {check = i; break;}
    vector<int> tmp;
    for(i=check;i<v_mat[y][x].size();i++) tmp.push_back(v_mat[y][x][i]);
    int end = v_mat[y][x].size();
    for(i=check;i<end;i++) v_mat[y][x].pop_back();
    int ny = y +dy[horse[num].d], nx = x+dx[horse[num].d];
    if(reverse_flag)
    {   
        for(int i=tmp.size()-1;i>=0;i--)
        v_mat[ny][nx].push_back(tmp[i]);
    }
    else
    {
        for(int i=0;i<tmp.size();i++)
        v_mat[ny][nx].push_back(tmp[i]);
    }
    for(int i=0;i<tmp.size();i++)
    {
        horse[tmp[i]].y = ny; horse[tmp[i]].x = nx;
    }
    
}
bool end_check()
{
    for(int j=1;j<=N;j++)
    {
        for(int k=1;k<=N;k++)
        {
            if(v_mat[j][k].size()>=4) return true;
        }
    }
    return false;
}
bool turn()
{
    for(int i=1;i<=K;i++)
    {
        int y = horse[i].y, x = horse[i].x, d = horse[i].d;
        int ny = y+dy[d], nx = x+dx[d];
        bool reverse_flag = false;
        if(ny<1 || nx<1 || ny>N || nx > N|| mat[ny][nx]==2)//블루
        {
            if(!blue(i)) continue;
            ny = y+dy[horse[i].d];nx = x+dx[horse[i].d];
        }
        
        if(mat[ny][nx]==1)//레드
        {
            reverse_flag = true; 
        }
        move(i,reverse_flag);
        if(end_check()) return true;
    }
    return false;
}
int main()
{
    cin >> N >> K;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> mat[i][j];
        }
    }

    for(int i=1;i<=K;i++)
    {
        cin >> horse[i].y >> horse[i].x >> horse[i].d;
        v_mat[horse[i].y][horse[i].x].push_back(i);
    }
    bool flag = false;
    for(int i=0;i<1000;i++)
    {
        if(turn())
        {
            flag = true;
            cout << i+1;
            break;
        }
    }
    if(!flag) cout << -1;
}