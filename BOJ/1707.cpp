#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int T,V,E;
bool visited[20'002];
bool node_color[20'002];
vector<int> v[20'002];
void sol()
{
    cin >> V >> E;
    for(int i=1;i<=V;i++) 
    {
        v[i].clear();
        node_color[i]=visited[i]=0;
    }
    for(int i=0;i<E;i++)
    {
        int a,b; cin >> a >> b;
        v[a].push_back(b); v[b].push_back(a);
    }

    queue<int> q;
    for(int n=1;n<=V;n++)
    {
        if(visited[n]) continue;
        q.push(n); visited[n]=1; node_color[n]=true;
        while(!q.empty())
        {
            int node = q.front(); q.pop();
            for(int i=0;i<v[node].size();i++)
            {
                if(visited[v[node][i]]) continue;
                node_color[v[node][i]]=(!node_color[node]);
                visited[v[node][i]]=1;
                q.push(v[node][i]);
            }
        }
    }
    for(int i=1;i<=V;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            if(node_color[i]==node_color[v[i][j]])
            {
                cout << "NO"<<endl; return;
            }
        }
    }
    cout << "YES"<<endl;

}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> T;
    for(int i=0;i<T;i++) sol();

}