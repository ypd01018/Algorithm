#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,node_people[11],node_color[11],visit[11],mn=INT_MAX;
vector<int> node[11];

void BFS(int color)
{
    queue<int> q;
    for(int i=1;i<=N;i++) if(node_color[i]==color) {q.push(i);visit[i]=1;break;}
    while(!q.empty())
    {
        int target=q.front();q.pop();
        for(int i=0;i<node[target].size();i++)
        {
            int nxt_node = node[target][i];
            if(visit[nxt_node] || node_color[nxt_node]!=color) continue;
            visit[nxt_node]=1;
            q.push(nxt_node);
        }
    }
}
void check()
{
    for(int i=1;i<=N;i++) cout << node_color[i] << ' '; cout << endl;
    memset(visit,0,sizeof(visit));
    BFS(0); BFS(1);
    for(int i=1;i<=N;i++) {if(!visit[i]) return;}
    int cnt_1=0, cnt_0=0;
    for(int i=1;i<=N;i++)
    {
        if(!node_color[i]) cnt_0+=node_people[i];
        else cnt_1+=node_people[i];
    }
    mn=min(mn,abs(cnt_0-cnt_1));
}
void DFS(int a,int cnt)
{
    if(cnt) check();

    for(int i=a;i<=N;i++)
    {
        if(node_color[i]) continue;
        node_color[i]=1;
        DFS(i+1,cnt+1);
        node_color[i]=0;
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> node_people[i];
    for(int i=1;i<=N;i++)
    {
        int n; cin >> n;
        for(int j=0;j<n;j++)
        {
            int a; cin >> a;
            node[i].push_back(a);
        }
    }
    DFS(1,0);
    if(mn==INT_MAX) cout <<-1;
    else cout << mn;
}