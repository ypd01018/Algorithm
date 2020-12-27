#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int N,mx;
priority_queue<pair<int,int>> pq;
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        int a,b; cin >> a >> b;
        pq.push({-1*a,-1}); pq.push({-1*b,0});
    }
    int cnt = 0;
    while(!pq.empty()){
        int a = -1*pq.top().first, flag = pq.top().second; pq.pop();
        if(flag) mx = max(++cnt,mx);
        else cnt--;
    }
    cout << mx ;

}