#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N,M,K,X;
int d[300'010];
vector<int> node[300'010];
priority_queue<pair<int,int>> pq;

int main() {
    cin >> N >> M >> K >> X;
    for(int i=0;i<M;i++) {
        int a,b;
        cin >> a >> b;
        node[a].push_back(b);
    }

    for(int i=1;i<=N;i++) d[i] = 1e9;
    d[X] = 1e9+1;

    for(int i=0;i<node[X].size();i++) pq.push({-1,node[X][i]});

    while(!pq.empty()){
        int dis = -1*pq.top().first, num = pq.top().second;
        pq.pop();
        
        if(d[num] != 1e9) continue;

        d[num] = dis;

        for(int i=0;i<node[num].size();i++) {
            int next_num = node[num][i];
            int next_dis = dis+1;
            pq.push({-1*(dis+1),node[num][i]});
        }
    }

    vector<int> answer;

    for(int i=1;i<=N;i++) {
        if(d[i] == K) answer.push_back(i);
    }

    if(answer.empty()) cout << -1;
    else {
        for(int i=0;i<answer.size();i++) cout << answer[i] << '\n';
    }
    
}