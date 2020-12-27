#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int T=3,N,coin[101][2],dp[100010];
int sol(){
    cin >> N;
    int tot = 0;
    for(int i=0;i<N;i++) {
        cin >> coin[i][0] >> coin[i][1];
        tot += coin[i][0] * coin[i][1];
    }
    if(tot%2) return 0;
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i=0;i<N;i++){
        for(int j=tot/2;j>=0;j--){
            if(!dp[j]) continue;
            for(int k=1;k<=coin[i][1];k++){
                dp[j+coin[i][0]*k]=1;
            }
        }
    }
    return dp[tot/2];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(T--) cout << sol() << endl;
}