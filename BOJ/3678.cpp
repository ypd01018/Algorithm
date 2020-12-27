#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int res[6],ans[10002];
short mat[1000][1000];
int dy[6]={-2,-1,1,2,1,-1},dx[6]={0,-1,-1,0,1,1};
vector<int> rule_one(int y, int x)
{
    vector<int> v;
    int check[6]={0};
    for(int n=0;n<6;n++)
    {
        int ny = y+dy[n], nx = x+dx[n];
        if(!mat[ny][nx]) continue;
        check[mat[ny][nx]]=1;
    }
    for(int i=1;i<=6;i++) if(!check[i]) v.push_back(i);
    return v;
    
}
vector<int> rule_two(vector<int> v)
{
    int mn = 1e9;
    vector<int> ret_v;
    for(int i=0;i<v.size();i++)
    {
        if(res[v[i]]<mn)
        {
            ret_v.clear();
            ret_v.push_back(v[i]);
            mn = res[v[i]];
        }
        else if(res[v[i]]==mn) ret_v.push_back(v[i]);
    }
    return ret_v;
}
void select_res(int y, int x)
{
    vector<int> v = rule_one(y,x);
    if(v.size()==1) 
    {
        mat[y][x]=v[0];
        res[v[0]]++;
        return;
    }
    v = rule_two(v);
    if(v.size()==1)
    {
        mat[y][x]=v[0];
        res[v[0]]++;
        return;
    }
    mat[y][x]=v[0];
    res[v[0]]++;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int end = 1,nxt_plus = 6,y=500,x=500,d,cnt_move;
    for(int i=1;i<=10000;i++)
    {
        select_res(y,x);
        ans[i] = mat[y][x];
        if(i==end)
        {
            y = y+dy[5]; x=x+dx[5];
            end += nxt_plus;
            cnt_move = -1+nxt_plus/6;
            nxt_plus+=6;
            d=0;
            continue;
        }
        if(!cnt_move)
        {
            d++;
            cnt_move = -1+nxt_plus/6;
        }
        y = y+dy[d]; x = x+dx[d];
        cnt_move--;
    }
    int T; cin >> T;
    for(int i=0;i<T;i++)
    {
        int a; cin >> a;
        cout <<ans[a] << endl;
    }
}