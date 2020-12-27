#include<bits/stdc++.h>
#define endl "\n"
#define mp make_pair
#define f first
#define s second
using namespace std;
int N,M,mat[102][102],numbering[102][102],visited[102][102],dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1}, dis[7][7],num=1,root[7];
vector<pair<int,int> > island[7];
queue<pair<int,int> > q;
void find_other(int y, int x, int d)
{
    int ny = y, nx = x,island_dis=-1,me=numbering[y][x];
    while(1)
    {
        ny = ny+dy[d]; nx = nx+dx[d];
        island_dis++;
        if(ny <0 || nx<0 || ny>=N || nx>=M || numbering[ny][nx]==numbering[y][x]) return;
        if(numbering[ny][nx]!=0)
        {
            int target = numbering[ny][nx];
            if(island_dis>1) dis[me][target] = dis[target][me] = min(dis[me][target],island_dis);
            return;
        }
    }
}
void init()
{
    for(int i=0;i<7;i++) root[i]=i;
}
int find(int a)
{
    if(root[a]==a) return a;
    else return root[a]=find(root[a]);
}
void uni(int a, int b)
{
    a = root[a];
    b = root[b];
    root[a] = b;
}
int main()
{
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7;j++)
        {
            dis[i][j]=INT_MAX;
        }
    }
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> mat[i][j];
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(!mat[i][j]||visited[i][j]) continue;
            q.push(mp(i,j)); visited[i][j]=1; numbering[i][j]=num; island[num].push_back(mp(i,j));
            while(!q.empty())
            {
                int y = q.front().f, x = q.front().s; q.pop();
                for(int n=0;n<4;n++)
                {
                    int ny = y+dy[n], nx = x+dx[n];
                    if(ny<0 || nx<0 || ny>=N || nx >= M || !mat[ny][nx] || visited[ny][nx]) continue;
                    visited[ny][nx]=1; numbering[ny][nx]=num;
                    q.push(mp(ny,nx)); island[num].push_back(mp(ny,nx));
                }
            }
            num++;
        }
    }
    for(int i=1;i<num;i++)
    {
        for(int j=0;j<island[i].size();j++)
        {
            int y = island[i][j].f, x = island[i][j].s;
            for(int n=0;n<4;n++) find_other(y,x,n);
        }
    }
    // for(int i=1;i<num;i++)
    // {
    //     for(int j=1;j<num;j++)
    //     {
    //         if(dis[i][j]==INT_MAX) cout <<0;
    //         else cout << dis[i][j];
    //         cout << ' '; 
    //     }cout << endl;
    // }
    vector<pair<int,pair<int,int> > > v;
    for(int i=1;i<7;i++)
    {
        for(int j=1;j<7;j++)
        {
            if(dis[i][j]==INT_MAX) continue;
            v.push_back(mp(dis[i][j],mp(i,j)));
        }
    }
    sort(v.begin(),v.end());
    int tot =0,cnt=0;
    init();
    for(int i=0;i<v.size();i++)
    {
        int c=v[i].f, a= v[i].s.f, b=v[i].s.s; 
        if(find(a)!=find(b))
        {
            tot += c;
            uni(a,b);
            cnt++;
        }
        if(cnt==num-2) break;
    }
    if(tot==0 || cnt<num-2) cout << -1;
    else cout << tot;
}