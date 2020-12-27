#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int T,n,d,c,dis[10002];
vector<pair<int,int>> com[10002];
priority_queue<pair<int,int>> pq;
void sol(){
    cin >> n >> d >> c;
    for(int i=1;i<=n;i++) {
        dis[i] = INT_MAX;
        com[i].clear();
    }
    for(int i=0;i<d;i++){
        int a,b,s;
        cin >> a >> b >> s;
        com[b].push_back({s,a});
        if(b==c) pq.push({-1*s,a});
    }
    dis[c] = 0;
    while(!pq.empty()){
        int to = pq.top().second, sec = -1*pq.top().first; pq.pop();
        if(dis[to]==INT_MAX){
            dis[to] = sec;
            for(int i=0;i<com[to].size();i++){
                int new_sec = sec + com[to][i].first;
                int new_to = com[to][i].second;
                pq.push({-1*new_sec,new_to});
            }
        }
    }
    int mx=0, n_com=0;
    for(int i=1;i<=n;i++){
        if(dis[i]==INT_MAX) continue; 
        n_com++;
        mx = max(dis[i],mx);
    }
    cout << n_com << ' ' << mx << endl;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> T;
    while(T--) sol();        
    
}