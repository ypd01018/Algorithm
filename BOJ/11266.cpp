#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int V,E,d;
int disc[10010];
bool cut[10010];
vector<int> v[10010];
int DFS(int here,bool r)
{
    disc[here] = ++d;
    int ret = disc[here];
    int child =0;
    for(int there : v[here])
    {
        if(!disc[there])
        {
            child++;
            int df = DFS(there,0);
            if(!r && df >= disc[here]) cut[here]=true;
            ret=min(df,ret);
        }
        else
        {
            ret=min(ret,disc[there]);
        }
    }
    
    if(r && child >1)
    {
        cut[here]=true;
    }
    return ret;

}
int main()
{
    cin >> V >> E;
    for(int i=0;i<E;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }


    for(int i=1;i<=V;i++)
    {
        if(!disc[i]) DFS(i,1);
    }
    int ans=0;
    for(int i=1;i<=V;i++)
    {
        if(cut[i]) ans++;
    }

    cout << ans << endl;

    for(int i=1;i<=V;i++)
    {
        if(cut[i]) cout << i <<' ';
    }
}