#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,parent[100010];
bool visited[100010];
vector<int> v[100010];
void go(int a)
{
    for(int i=0;i<v[a].size();i++)
    {
        if(visited[v[a][i]]) continue;
        visited[v[a][i]]=1;
        parent[v[a][i]]=a;
        go(v[a][i]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int start,end; cin >> start >> end;
        v[start].push_back(end);
        v[end].push_back(start);
    }
    visited[1]=1;
    go(1);
    for(int i=2;i<=n;i++)
    cout << parent[i] << endl;

    

}