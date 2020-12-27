#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,G,R,mat[52][52],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},mx;
vector<int> v;
vector<pair<int,int>> enable_seed;

void go()
{
    pair<int,int> mat_cpy[52][52]; memset(mat_cpy,0,sizeof(mat_cpy));
    queue<pair<pair<int,int>,int>> r_q,g_q;
    for(int i=0;i<v.size();i++)
    {
        int y = enable_seed[i].first, x = enable_seed[i].second;
        if(v[i]==1) 
        {
            g_q.push({{enable_seed[i]},0});
            mat_cpy[y][x].first = 1;
        }
        else if(v[i]==2)
        { 
            r_q.push({enable_seed[i],0});
            mat_cpy[y][x].first=2;
        }
    }
    bool g_wait=false, r_wait=false;
    int r_time=1,g_time=1,cnt=0,check[52][52]={0};
    while(!r_q.empty() && !g_q.empty())
    {
        while(!g_q.empty())
        {
            if(g_q.front().second==g_time)
            {
                g_time++;
                break;
            }
            int y = g_q.front().first.first, x =  g_q.front().first.second, sec = g_q.front().second; g_q.pop();
            if(check[y][x]) continue;
            for(int n=0;n<4;n++)
            {
                int ny = y+dy[n], nx=x+dx[n];
                if(ny<0 || nx<0 || ny>=N || nx>=M || !mat[ny][nx] || mat_cpy[ny][nx].first) continue;
                mat_cpy[ny][nx].first=1; mat_cpy[ny][nx].second=sec+1;
                g_q.push({{ny,nx},sec+1});
            }
        }
        while(!r_q.empty())
        {
            if(r_q.front().second==r_time)
            {
                r_time++;
                break;
            }
            int y = r_q.front().first.first, x =  r_q.front().first.second, sec = r_q.front().second; r_q.pop();
            for(int n=0;n<4;n++)
            {
                int ny = y+dy[n], nx=x+dx[n];
                if(ny<0 || nx<0 || ny>=N || nx>=M || !mat[ny][nx] || mat_cpy[ny][nx].first==2 || mat_cpy[ny][nx].first==3) continue;
                if(mat_cpy[ny][nx].first==1)
                {
                    if( mat_cpy[ny][nx].second == sec+1)
                    {
                        cnt++; mat_cpy[ny][nx].first=3;
                        check[ny][nx]=1;
                    }
                    continue;
                }
                mat_cpy[ny][nx].first=2; mat_cpy[ny][nx].second=sec+1;
                r_q.push({{ny,nx},sec+1});
            }
        }

    }
    mx = max(mx,cnt);

}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M >> G >> R;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> mat[i][j];
            if(mat[i][j]==2) enable_seed.push_back({i,j});
        }
    }
    for(int i=0;i<enable_seed.size()-G-R;i++) v.push_back(0);
    for(int i=0;i<G;i++) v.push_back(1);
    for(int i=0;i<R;i++) v.push_back(2);
    do
    {
        go();
    }while(next_permutation(v.begin(),v.end())); 
    cout << mx;
}