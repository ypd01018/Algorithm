#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int w,h,dis[11][11],dy[]={-1,0,1,0},dx[]={0,1,0,-1},finish,mn=1e9;
char mat[21][21];
vector<pair<int,int> > v;
int find_num(int y, int x)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i].first == y && v[i].second==x) return i;
    }
    return -1;
}
void BFS(pair<int,int> yx,int from)
{
    int visited[21][21]={0};
    queue<pair<pair<int,int>,int> > q;
    q.push({yx,0});
    while(!q.empty())
    {
        int y=q.front().first.first, x=q.front().first.second, sec=q.front().second; q.pop();
        for(int n=0;n<4;n++)
        {
            int ny = y+dy[n], nx=x+dx[n];
            if(ny<0 || nx<0 || ny>=h || nx>=w || mat[ny][nx]=='x' || visited[ny][nx]) continue;
            visited[ny][nx]=1;
            if(mat[ny][nx]=='*') 
            {
                dis[from][find_num(ny,nx)]=sec+1;
                dis[find_num(ny,nx)][from]=sec+1;
            }
            q.push({{ny,nx},sec+1});
        }
    }
}
void init()
{
    v.clear();
    v.push_back({0,0});
    memset(dis,-1,sizeof(dis));
    finish=0;
    mn=1e9;
}
bool make_true()
{
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            if(dis[i][j]==-1) return false;
        }
    }
    return true;
}
void DFS(int n,int dis_plus,int check)
{
    if(check == finish) 
    {
        mn = min(mn,dis_plus);
        return;
    }
    for(int i=1;i<v.size();i++)
    {
        if(1<<i & check) continue;
        DFS(i,dis_plus+dis[n][i],check|1<<i);
    }
}
int main()
{
    while(1)
    {
        cin >> w >> h;
        if(!w && !h) break;
        init();
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                cin >> mat[i][j];
                if(mat[i][j]=='o') v[0]={i,j};
                else if(mat[i][j]=='*') v.push_back({i,j});
            }
        }
        for(int i=0;i<v.size();i++) 
        {
            finish |=1<<i;
            BFS(v[i],i);
        }
        if(!make_true())
        {
            cout << -1 << endl;
            continue;
        }
        DFS(0,0,1);
        cout << mn << endl;
    }
}