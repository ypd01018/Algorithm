#include<bits/stdc++.h>
#define endl "\n"
#define mp make_pair
#define f first
#define s second
using namespace std;
int N,M,mat[60][60],virus_check[60][60],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},mn=1e9,n_empty;
vector<pair<int,int> > v,v2;
int virus_time()
{
    queue<pair<pair<int,int>,int>> q; 
    int visited[60][60],cnt_empty = n_empty; memset(visited,0,sizeof(visited));
    for(int i=0;i<v2.size();i++) 
    {
        q.push(mp(v2[i],0));
        visited[v2[i].f][v2[i].s]=1;
    }
    while(!q.empty())
    {
        int y = q.front().f.f, x=q.front().f.s, sec = q.front().s; q.pop();
        for(int i=0;i<4;i++)
        {
            int ny = y+dy[i], nx = x+dx[i];
            if(ny <0 || nx <0 || ny>=N || nx >=N || mat[ny][nx]==1 || visited[ny][nx]) continue;
            if(mat[ny][nx]==0) cnt_empty--;
            if(cnt_empty==0) return sec+1;
            visited[ny][nx]=1;
            q.push(mp(mp(ny,nx),sec+1));
        }
    }
    return 1e9;
}
void go(int n,int a)
{
    if(n==M)
    {
        int sec = virus_time();
        mn = min(mn,sec);
        return;
    }
    for(int i=a;i<v.size();i++)
    {
        if(virus_check[v[i].f][v[i].s]) continue;
        v2.push_back(v[i]);
        virus_check[v[i].f][v[i].s]=1;
        go(n+1,i+1);
        v2.pop_back();
        virus_check[v[i].f][v[i].s]=0;
    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> mat[i][j];
            if(mat[i][j]==0) n_empty++;
            if(mat[i][j]==2) v.push_back(mp(i,j));
        }
    }
    if(n_empty==0) 
    {
        cout << 0;
        return 0;
    }
    go(0,0);
    if(mn==1e9) cout << -1;
    else cout << mn;

}