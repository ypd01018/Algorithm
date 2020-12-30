#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int N,S,mn=1e9;
vector<int> v;
int main(){
    cin >> N >> S;
    for(int i=0;i<N;i++) {
        int input; cin >> input;
        v.push_back(input);
    } 
    int l = 0, r= 0;
    long long sum = v[0];
    while(l<=r && r<N){
        if(sum<S) {
            if(++r < N) sum += v[r];
        }
        else {
            sum -= v[l];
            mn = min(mn,r-l+1);
            l++;
        }
    }
    if(mn == 1e9) cout << 0;
    else cout << mn;
}