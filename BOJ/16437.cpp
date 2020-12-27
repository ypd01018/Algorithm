#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int N;
pair<char,int> node_info[130000];
vector<int> node[130000];
ll ll_max(ll a, ll b){
    if(a>b) return a;
    else return b;
}
ll DFS(int num){
    ll total = 0;
    for(int i=0;i<node[num].size();i++) total += DFS(node[num][i]);
    if(num==1) return total;
    if(node_info[num].first=='S') return total + node_info[num].second;
    else {
        ll sheep = ll_max(0,total - node_info[num].second);
        node_info[num].second = ll_max(0,node_info[num].second - total);
        return sheep;
    }
}
int main(){
    cin >> N;
    for(int i=2;i<=N;i++) {
        int nxt;
        cin >> node_info[i].first >> node_info[i].second >> nxt;
        node[nxt].push_back(i);
    }
    cout << DFS(1);
    
}