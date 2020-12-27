#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,K,mat[15][15],dy[]={0,0,0,-1,1},dx[]={0,1,-1,0,0},ans;
vector<int> v[15][15];
struct horse_str
{
    int y,x,dir,num;
    bool under;
};
horse_str horse[13];
void print_test(string a)
{
    cout <<"------------------------------"<<a<<"------------------------"<< endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout << v[i][j].size();
        }
        cout << endl;
    }
}
void move_0(int num)
{
    horse_str target = horse[num];
    int y=target.y,x=target.x,ny = target.y+dy[target.dir], nx=target.x+dx[target.dir],val=mat[ny][nx];
    int check;
    for(int i=0;i<v[y][x].size();i++)
    {
        check=i;
        if(v[y][x][i]==target.num) break;
    }
    for(int i=check;i<v[y][x].size();i++)
    {
        horse[v[y][x][i]].y=ny, horse[v[y][x][i]].x=nx;
        v[ny][nx].push_back(v[y][x][i]);
    }
    int size = v[y][x].size();
    for(int i=check;i<size;i++) v[y][x].pop_back();
}
void move_1(int num)
{
    horse_str target = horse[num];
    int y=target.y,x=target.x,ny = target.y+dy[target.dir], nx=target.x+dx[target.dir],val=mat[ny][nx];
    int check;
    for(int i=0;i<v[y][x].size();i++)
    {
        check=i;
        if(v[y][x][i]==target.num) break;
    }
    for(int i=v[y][x].size()-1;i>=check;i--)
    {
        horse[v[y][x][i]].y=ny, horse[v[y][x][i]].x=nx;
        v[ny][nx].push_back(v[y][x][i]);
    }
    int size = v[y][x].size();
    for(int i=check;i<size;i++) v[y][x].pop_back();
}
int reverse(int dir)
{
    if(dir==1) return 2;
    else if(dir==2) return 1;
    else if(dir==3) return 4;
    else return 3;
}
bool action(int num)
{
    horse_str target = horse[num];
    // print_test("brfore");
    // cout << num << "   " << target.dir << endl;
    int ny = target.y+dy[target.dir], nx=target.x+dx[target.dir],val=mat[ny][nx];
    if(ny<0 || nx <0 || ny>=N || nx>=N) val=2;
    if(val==0)
    {
        move_0(num);
    }
    else if(val==1)
    {
        move_1(num);
    }
    else
    {
        horse[num].dir=reverse(horse[num].dir); ny = horse[num].y+dy[horse[num].dir], nx=horse[num].x+dx[horse[num].dir]; val=mat[ny][nx];
        if(ny<0 || nx <0 || ny>=N || nx>=N) val=2;
        if(val==0) move_0(num);
        else if(val==1) move_1(num);
    }
    // print_test("after");
    // cout << num << "   " << target.dir << endl;

    if(ny<0 || nx <0 || ny>=N || nx>=N) return true;
    if(v[ny][nx].size()>3) return false;
    return true;
}
bool turn()
{
    ans++;
    for(int i=1;i<=K;i++) 
    {   
        if(!action(i)) return false;
    }
    return true;
}

int main()
{
    cin >> N >> K;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> mat[i][j];
        }
    }
    for(int i=1;i<=K;i++)
    {
        int y , x , dir;
        cin >> y >> x >> dir;
        horse[i].y=y-1; horse[i].x=x-1; horse[i].dir=dir; horse[i].num = i;
        v[y-1][x-1].push_back(i);
    }
    while(ans<=1000) 
    {        
        // cout <<endl<<endl<<"turn:"<< ans<<endl;
        if(!turn()) break;
    }

    if(ans>1000) cout << -1;
    else cout << ans;

}