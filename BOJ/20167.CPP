#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int N,K,sum;
int arr[30],dp[30];
int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> arr[i];
    int l=0,r=1;
    while(r<=N){
        sum += arr[r];
        dp[r] = dp[r-1];
        while(sum>=K){
            dp[r] = max(dp[r],dp[l]+sum-K);
            sum -= arr[++l];
        }
        r++;
    }
    cout << dp[N];

}