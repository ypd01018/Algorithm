#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,K,mat[15][15],dy[4]={0,0,-1,1},dx[4]={1,-1,0,0},turn=1,horse_mat[15][15];
struct horse_
{
    int y,x,d;
    bool down=true;
    vector<int> v;
};
horse_ horse[12];
void print_test()
{
    cout << endl;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cout << horse_mat[i][j]<<' ';
        }cout << endl;
    }
}
void move(int num)
{
    int ny = horse[num].y + dy[horse[num].d],nx = horse[num].x + dx[horse[num].d];
    horse_mat[horse[num].y][horse[num].x]=0;
    if(horse_mat[ny][nx])
    {
        int target = horse_mat[ny][nx];
        horse[target].v.push_back(num);
        for(int i=0;i<horse[num].v.size();i++) horse[target].v.push_back(horse[num].v[i]);
        horse[num].v.clear();
        horse[num].down=false;
    }
    else
    {
        horse[num].y = ny; horse[num].x=nx; 
        horse_mat[ny][nx]=num;
    }
}
int reverse(int d)
{
    if(d==0) return 1;
    else if(d==1) return 0;
    else if(d==2) return 3;
    else return 2; 
}
bool blue(int num)
{
    horse[num].d = reverse(horse[num].d);
    int ny = horse[num].y + dy[horse[num].d], nx = horse[num].x + dx[horse[num].d];
    if(ny <=0 || nx<=0 || ny>N || nx>N || mat[ny][nx]==2) return false;
    return true;
    
}
void red(int num)
{
    stack<int> stk;
    for(int i=0;i<horse[num].v.size();i++) stk.push(horse[num].v[i]);
    if(stk.empty())
    {
        move(num); return;
    }
    horse[num].v.clear();
    int target = stk.top(); stk.pop();
    while(!stk.empty())
    {
        horse[target].v.push_back(stk.top());  stk.pop();
    } horse[target].v.push_back(num);
    horse[target].down = true;
    int cache = horse[target].d;
    horse[target].y = horse[num].y; horse[target].x = horse[num].x; horse[target].d = horse[num].d; 
    horse[num].down = false;
    move(target);
    horse[target].d = cache;
}
bool action()
{
    for(int i=1;i<=K;i++)
    {
        if(!horse[i].down) continue;
        int ny = horse[i].y + dy[horse[i].d], nx = horse[i].x + dx[horse[i].d];
        if(ny <=0 || nx<=0 || ny>N || nx>N || mat[ny][nx]==2)
        {
            if(!blue(i)) continue;
            ny = horse[i].y + dy[horse[i].d]; nx = horse[i].x + dx[horse[i].d];
        }
        if(!mat[ny][nx]) {move(i);}
        else if(mat[ny][nx])
        {
            red(i);
        }
        if(horse[horse_mat[ny][nx]].v.size()>=3) return true;
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
        cin >> horse[i].y >> horse[i].x >> horse[i].d; horse[i].d--;
        horse_mat[horse[i].y][horse[i].x] = i;
    }
    while(turn <=1000)
    {
        if(action()) break;
        turn++;
    }
    if(turn>1000) cout << -1;
    else cout << turn;

}