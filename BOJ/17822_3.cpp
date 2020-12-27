#include<bits/stdc++.h>
#define endl "\n"
#define mp make_pair
#define f first 
#define s second
using namespace std;
int N,M,T,mat[55][55],X,D,K,dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
void rotate(int a)
{
    deque<int> dq;
    for(int i=0;i<M;i++) dq.push_back(mat[a][i]);
    if(D==1) // 반시계
    {
        for(int i=0;i<K;i++)
        {
            int tmp = dq.front(); dq.pop_front();
            dq.push_back(tmp);
        }
    }
    else
    {
        for(int i=0;i<K;i++)
        {
            int tmp = dq.back(); dq.pop_back();
            dq.push_front(tmp);        
        }
    }

    for(int i=0;i<M;i++) 
    {
        mat[a][i] = dq.front();
        dq.pop_front();
    }
}
bool same_check()
{
    vector<pair<int,int> > erase;
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<M;j++)
        {
            for(int n=0;n<4;n++)
            {
                int ny = i+dy[n], nx = j+dx[n];
                if(ny>N || ny <=0) continue;
                if(nx<0) nx = M-1; else if(nx==M) nx=0;
                if(mat[ny][nx]==mat[i][j] && mat[i][j]!=0) erase.push_back(mp(ny,nx));
            }
        }
    }
    if(erase.size()==0) return false;
    for(int i=0;i<erase.size();i++) mat[erase[i].f][erase[i].s]=0;
    return true;
}
void not_same()
{
    int cnt=0,tot=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(mat[i][j]==0) continue;
            cnt++;
            tot += mat[i][j];
        }
    }
    double avg = (double)tot/(double)cnt;
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(mat[i][j]==0) continue;
            if(mat[i][j]<avg) mat[i][j]++;
            else if(mat[i][j]>avg) mat[i][j]--;
        }
    }
}
int ans()
{
    int ret=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<M;j++)
        {
            ret += mat[i][j];
        }
    }
    return ret;
}
int main()
{
    cin >> N >> M >> T;
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> mat[i][j];
        }
    }
    for(int i=0;i<T;i++)
    {
        cin >> X >> D >> K;
        for(int i=1;i*X<=N;i++)
        {
            rotate(i*X);
        }
        if(!same_check()) not_same();
    }
    cout << ans();
}