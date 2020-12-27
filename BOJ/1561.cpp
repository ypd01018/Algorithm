#include<bits/stdc++.h>
#define endl '\n'
#define ll long long 
using namespace std;
int N,M;
vector<int> ride;
ll get_n_child(ll time){
    ll n_child = M;
    for(int i=0;i<M;i++) n_child += time/ride[i];
    return n_child;
}
int binary_search(){
    ll end = 60'000'000'010, start = 0,n_child,time;
    while(start<=end){
        ll mid = (start+end)/2;
        n_child = get_n_child(mid);
        if(n_child<N) start = mid+1;
        else {
            end = mid-1;
            time = mid;
        }
    }
    ll rest_child = N-get_n_child(time-1);
    for(int i=0;i<M;i++) {
        if(time%ride[i]==0) rest_child--;
        if(!rest_child) return i+1;
    }
}
int main(){
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int a; cin >> a;
        ride.push_back(a);
    }
    if(N<=M){
        cout << N;
        return 0;
    }
    cout << binary_search();

}