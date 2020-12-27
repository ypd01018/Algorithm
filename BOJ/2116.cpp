#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int N,dice[10002][6],back[6]={5,3,4,1,2,0},mx;

int find_max(int n,int excep){
    int ret = 0;
    for(int i=0;i<6;i++){
        if(i==excep || i == back[excep]) continue;
        ret = max(ret,dice[n][i]);
    }
    return ret;
}

void go(int n,int need_num,int total){
    if(n==N){
        mx = max(total,mx);
        return;
    }
    for(int i=0;i<6;i++){
        if(dice[n][i]!=need_num) continue;
        go(n+1,dice[n][back[i]],total+find_max(n,i));
        break;
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<6;j++) cin >> dice[i][j];
    }   

    for(int i=0;i<6;i++){
        go(1,dice[0][i],find_max(0,i));
    }

    cout << mx;
}