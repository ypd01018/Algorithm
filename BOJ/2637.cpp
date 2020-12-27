#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,node_need[101][101],visit[101];
vector<pair<int,int>> node[101];

void DFS(int idx){
    for(int i=0;i<node[idx].size();i++){
        int nxt_node = node[idx][i].first, n_need = node[idx][i].second;
        if(!node[nxt_node].size()) node_need[idx][nxt_node] += n_need;
        else{
            if(!visit[nxt_node]) {
                visit[nxt_node] = 1;
                DFS(nxt_node);
            }
            for(int j=0;j<N;j++) node_need[idx][j] += node_need[nxt_node][j]*n_need;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int X,Y,K; cin >> X >> Y >> K;
        node[X].push_back({Y,K});
    }

    DFS(N);
    for(int i=1;i<N;i++) if(!node[i].size()) cout << i << ' ' << node_need[N][i]<<endl;
}