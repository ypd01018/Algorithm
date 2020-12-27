#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int T,a,b,x_arr[4],visited[10010];

int D_act(int x)
{
    if(2*x >=10000) return (2*x)%10000;

    return 2*x;
}
int S_act(int x)
{
    if(x==0) return 9999;
    return x-1;
}
int L_act(int x)
{
    int tmp = x/1000;
    x %= 1000;
    x *= 10;
    x += tmp;
    return x;
}
int R_act(int x)
{
    int tmp = x % 10;
    x -= tmp;
    x /= 10;
    x += tmp*1000;
    return x;
}
void BFS()
{
    queue<pair<int,string>> q;
    memset(visited,0,sizeof(visited));
    string cmd;

    q.push({a,""});
    visited[a]=1;

    while(1)
    {
        int x = q.front().first; cmd = q.front().second; q.pop();
        //cout << x << endl;
        if(x==b) break;

        int d = D_act(x);
        if(!visited[d])
        {
            q.push({d,cmd+"D"});
            visited[d]=1;
        }
        int s = S_act(x);
        if(!visited[s])
        {
            q.push({s,cmd+"S"});
            visited[s]=1;
        }
        int l = L_act(x);
        if(!visited[l])
        {
            q.push({l,cmd+"L"});
            visited[l]=1;
        }
        int r = R_act(x);
        if(!visited[r])
        {
            q.push({r,cmd+"R"});
            visited[r]=1;
        }
    }
    cout << cmd << endl;
}

int main()
{
    cin >> T;
    for(int i=0;i<T;i++)
    {
        cin >> a >> b;
        BFS();
    }
}