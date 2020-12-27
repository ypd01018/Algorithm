#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
priority_queue<pair<int,int>> jewel;
priority_queue<int> pq;
int N,K,knapsack[300002];
int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++){
        int a, b; cin >> a >> b;
        jewel.push({-1*a,b});
    } 
    for(int i=0;i<K;i++) cin >> knapsack[i];
    long long total = 0;
    sort(knapsack,knapsack+K);
    for(int i=0;i<K;i++){
        while(!jewel.empty() && -1*jewel.top().first <= knapsack[i]){
            pq.push(jewel.top().second); 
            jewel.pop();
        }
        if(!pq.empty()){
            total += pq.top();
            pq.pop();
        }
    }
    cout << total;
}