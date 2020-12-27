#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,r,c,d,mat[52][52],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
bool visited[52][52];
int lft(int a)
{
    a--;
    if(a==-1) a=3;
    return a;
}
int bck(int a)
{
    a=(a+2)%4;
    return a;
}
bool act_a()
{
    //cout << "a"<<endl;
    int ny = r + dy[lft(d)],nx = c + dx[lft(d)];
    if(mat[ny][nx]==0 && !visited[ny][nx])
    {
        r =ny; c=nx;
        d=lft(d);
        return true;
    }
    return false;
}
void act_b()
{
    //cout << "b"<<endl;
    while(1)
    {
        int ny = r + dy[lft(d)],nx = c + dx[lft(d)];
        if(mat[ny][nx]==0 && visited[ny][nx]==0) break;
        d=lft(d);
    }
    
}
int act_cd()
{
    //cout << "cd"<<endl;
    bool back=true;
    int cnt=0;
    for(int i=0;i<4;i++)
    {
        int ny = r+dy[i],nx = c+dx[i];
        if(visited[ny][nx] || mat[ny][nx])
        {
            cnt++;
            if(i==bck(d) && mat[ny][nx]==1) back = false;
        }
    }

    if(cnt==4 && !back) return 0;
    if(cnt == 4) 
    {
        r += dy[bck(d)];
        c += dx[bck(d)];
        return 1;
    }
    return 2;
}
void test_print()
{
    cout << "------------------------"<<endl;
    cout << "r:" << r << " c:"<< c <<" d:" << d << endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==1) cout << 2 << " ";
            else cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------------------"<<endl;
}
int main()
{
    cin >> n >> m;
    cin >> r >> c >> d;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> mat[i][j];
        }
    }

    while(1)
    {
        visited[r][c]=1;
        //test_print();
        if(act_a()) continue;
        int ret = act_cd();
        if(ret==0) break;
        else if(ret==1) continue;
        else
        {
            act_b();
        }
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visited[i][j]) ans++;
        }
    }
    cout << ans;
}