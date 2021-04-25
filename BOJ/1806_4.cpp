#include<iostream>
#include<algorithm>

using namespace std;

int N,S,ans=1e9;
int arr[100010];
int main() {
    cin >> N >> S;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }

    int l=0,r=0;
    long long tot = arr[l];
    while(l <= r && r < N) {
        if(tot >= S) {
            ans = min(r - l + 1, ans);
            tot -= arr[l];
            l++;
        }
        else if(tot < S) {
            if(++r > N) break;
            tot += arr[r];
        }
    }
    if(ans == 1e9) cout << 0;
    else cout << ans;
}