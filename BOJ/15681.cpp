#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,R,Q,ans[100'002],visited[100'002];
vector<int> node[100'002];
int go(int num)
{
    ans[num]=1;
    for(int i=0;i<node[num].size();i++)
    {
        if(visited[node[num][i]]) continue;
        visited[node[num][i]]=1;
        ans[num] += go(node[num][i]);
    }
    return ans[num];
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> R >> Q;
    for(int i=0;i<N-1;i++)
    {
        int a,b; cin >> a >> b;
        node[a].push_back(b); node[b].push_back(a);
    }
    visited[R]=1;
    go(R);
    for(int i=1;i<=Q;i++)
    {
        int a; cin >> a;
        cout << ans[a]<<endl;
    }
}