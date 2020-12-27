#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,D,mat[20][20],check[20],cpy[20][20],mx=-1;;
pair<int,int> arr[5];
queue<pair<int,int>> q;

bool find_enemy(int y,int x)
{
    vector<pair<int,int>> v;
    int mn_d = INT_MAX,enemy_cnt=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(mat[i][j]==0) continue;
            enemy_cnt++;
            int dis = abs(i-y)+abs(j-x);
            if(dis>D) continue;

            if(dis<mn_d)
            {
                v.clear();
                v.push_back({i,j});
                mn_d=dis;
            }
            else if(dis == mn_d)
            {
                v.push_back({i,j});
            }
        }
    }
    if(!enemy_cnt) return false;

    if(v.size()==1) q.push({v[0].first,v[0].second});
    else if(v.size()>1)
    {
        int y_tmp,x_tmp,mn_x=INT_MAX;
        for(int i=0;i<v.size();i++)
        {
            if(mn_x > v[i].second)
            {
                y_tmp = v[i].first; x_tmp = v[i].second;
                mn_x = v[i].second;
            }
        }
        q.push({y_tmp,x_tmp});
    }
    return true;
}
void down()
{
    for(int i=N-1;i>0;i--)
    {
        for(int j=0;j<M;j++)
        {
            mat[i][j]=mat[i-1][j];
        }
    }
    for(int i=0;i<M;i++) mat[0][i]=0;
}
void game_start()
{
    
    int cnt=0;
    bool flag = true;
    while(flag)
    {
        for(int i=0;i<3;i++)
        {
            if(!find_enemy(arr[i].first,arr[i].second)) 
            {
                flag = false;
                break;
            }
        }
        while(!q.empty())
        {
            int y = q.front().first, x = q.front().second; q.pop();
            if(mat[y][x])
            {
                mat[y][x]=0;
                cnt++;
            } 
        }
        if(flag) down();
        
    }

    mx = max(mx,cnt);
}
void DFS(int a,int b)
{
    if(a==3)
    {
        memcpy(mat,cpy,sizeof(cpy));
        game_start();
        return;
    }

    for(int i=b;i<M;i++)
    {
        if(check[i]) continue;
        mat[N-1][i]=1;
        check[i]=1;
        arr[a]={N,i};
        DFS(a+1,i+1);
        mat[N-1][i]=0;
        check[i]=0;
    }
}
int main()
{
    cin >> N >> M >> D;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> mat[i][j];
        }
    }
    memcpy(cpy,mat,sizeof(mat));
    DFS(0,0);
    cout << mx;
}