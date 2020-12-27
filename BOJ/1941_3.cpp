#include<bits/stdc++.h>
#define endl "\n"
#define y first
#define x second
using namespace std;
int arr[5][5],sev_group[5][5],visited[5][5],dx[]={0,1,0,-1},dy[]={1,0,-1,0},ans;
pair<int,int> seven[7];
queue<pair<int,int>> q;
bool som_check()
{
    int cnt=0;
    for(int i=0;i<7;i++)
    {
        auto yx = seven[i];
        if(arr[yx.y][yx.x]==1) cnt++;
    }
    if(cnt>=4) return true;
    else return false;
}
bool bfs()
{
    int cnt=0; memset(visited,0,sizeof(visited)); memset(sev_group,0,sizeof(sev_group));

    for(int i=0;i<7;i++)
    {
        int _y= seven[i].y,_x=seven[i].x;
        sev_group[_y][_x]=1;
    }

    auto yx = seven[0];
    q.push({yx.y,yx.x});
    visited[yx.y][yx.x]=1;
    //cout << endl << "q:";
    while(!q.empty())
    {
        cnt++;
        yx = q.front(); q.pop();
        //cout << yx.y <<',' << yx.x << "  ";
        for(int i=0;i<4;i++)
        {
            int ny = yx.y + dy[i],nx = yx.x+dx[i];
            if(ny>=0 && ny <5 && nx>=0 && nx<5 && !visited[ny][nx] && sev_group[ny][nx])
            {
                q.push({ny,nx});
                visited[ny][nx]=1;
            }
        }
    }
    //cout << endl;
    if(cnt==7) return true;
    else return false;
}
void go(int a,int idx)
{
    seven[idx]= {a/5,a%5};

    if(idx==7)
    {
        if(!som_check()) return;
        if(!bfs()) return;
        for(int i=0;i<7;i++)
        {
            cout << seven[i].y <<',' << seven[i].x << "  ";
        }
        cout << endl;
        ans++;
        return;
    }
    
    for(int i=a+1;i<25;i++)
    {
        go(i,idx+1);
    }


}
int main()
{
    for(int i=0;i<5;i++)
    {
        string input; cin >> input;
        for(int j=0;j<5;j++)
        {
            if(input[j]=='Y') arr[i][j]=0;
            else arr[i][j]=1;
        }
    }
    for(int i=0;i<18;i++) go(i,0);
    cout << ans;
}