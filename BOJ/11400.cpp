#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int V,E,d;
int disc[100010];
bool cut[100010];
vector<int> v[100010];
vector<pair<int,int>> edge;
int DFS(int here,int parent)
{
    disc[here] = ++d;
    int ret = disc[here];
    int child =0;
    for(int there : v[here])
    {
        if(there == parent) continue;
        if(!disc[there])
        {
            child++;
            int df = DFS(there,here);
            if(df > disc[here])
            {
                edge.push_back({min(here,there),max(here,there)});
            }
            ret=min(df,ret);
        }
        else
        {
            ret=min(ret,disc[there]);
        }
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


    DFS(1,0);
    sort(edge.begin(),edge.end());
    

    cout << edge.size() << endl;

    for(int i=0;i<edge.size();i++)
    {
        cout << edge[i].first <<' ' << edge[i].second << endl;
    }
}