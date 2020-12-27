#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int a,N,ans;
priority_queue<int> boys[2],girls[2];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> a; boys[(a>0)].push(abs(a));
    }
    for(int i=0;i<N;i++){
        cin >> a; girls[(a>0)].push(abs(a));
    }
    while(!boys[0].empty() && !girls[1].empty()){ // 남자는 작은 여자, 여자는 큰 남자 원함
        int boy = boys[0].top(), girl = girls[1].top();
        girls[1].pop();
        if(boy>girl){
            boys[0].pop();
            ans++;
        }
    }
    while(!boys[1].empty() && !girls[0].empty()){ // 남자는 큰 여자, 여자는 작은 남자 원함
        int boy = boys[1].top(), girl = girls[0].top();
        boys[1].pop();
        if(girl>boy){
            girls[0].pop();
            ans++;
        }
    }
    cout << ans;
}