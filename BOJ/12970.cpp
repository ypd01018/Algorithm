#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int N,K,fin_flag=0,mx;
string S,ans="";
void go(int idx, int cnt, int n_A){
    if(idx ==N || cnt>K || fin_flag) return;
    else if(cnt == K){
        ans = S;
        fin_flag = 1;
        return;
    }
    int new_cnt = cnt - n_A + (N-(idx+1));
    S[idx] = 'A';
    go(idx+1,new_cnt,n_A+1);
    S[idx] = 'B';

    go(idx+1,cnt,n_A);
}

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) S.push_back('B');
    
    if(N%2) mx = (N/2)*(1+(N/2));
    else mx = (N/2)*(N/2);

    if(K>mx){
        cout << -1;
        return 0;
    }
    else if(K==0){
        string a;
        for(int i=0;i<N;i++) a.push_back('A');
        a[0]='B';
        cout << a;
        return 0;
    }
    go(0,0,0);
    if(ans=="") cout << -1;
    else cout << ans;
}