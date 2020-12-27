#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int N,K,belt_hp[102],belt_num[102];
list<int> robot;
void check_robot(){
    
}
void belt_rotate(){
    for(int i=0;i<N;i++){
        belt_num[i] = (belt_num[i]+1)%(2*N);
    }
    for(auto iter = robot.begin();iter!=robot.end();iter++){
        *iter++;
    }
}
void move_robot(){
    for(auto iter = robot.begin();iter!=robot.end();iter++){
        int nxt_idx = belt_num[*iter+1];
        if(belt_hp[nxt_idx]<=0) continue;
        *iter++;
        belt_hp[nxt_idx]--;
    }
}
int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) {
        cin >> belt_hp[i];
        belt_num[i] = i;
    }

    while(1){
        belt_rotate(); // 1

    }
}