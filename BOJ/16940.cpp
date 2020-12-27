#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<int> node[100010];
vector<int> parent[100010];
list<pair<int,int>> lst;
int N,arr[100010],visit[100010];
bool true_parent(int child_node, int parent_node)
{
    for(int i=0;i<parent[child_node].size();i++) if(parent[child_node][i]==parent_node) return true;
    return false;
}
int n_child(int a)
{
    int ret=0;
    for(int i=0;i<node[a].size();i++)
    {
        if(!visit[node[a][i]]) ret++;
    }
    return ret;
}
bool go()
{
    if(arr[0]!=1) return false;
    lst.push_front({1,node[1].size()}); visit[1]=1;
    for(int i=1;i<N;i++)
    {
        visit[arr[i]]=1;
        if(true_parent(arr[i],lst.front().first))
        { 
            if(--lst.front().second==0) lst.pop_front();
            int get_n_child = n_child(arr[i]);
            if(get_n_child>0)lst.push_back({arr[i],get_n_child});
        }
        else return false;
    }
    return true; 
}
int main()
{
    cin >> N;
    for(int i=0;i<N-1;i++)
    {
        int a,b; cin >> a >> b;
        node[a].push_back(b); node[b].push_back(a);
        parent[a].push_back(b); parent[b].push_back(a);
    }
    for(int i=0;i<N;i++) cin >> arr[i];
    cout << go();
}