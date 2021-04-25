#include<iostream>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

long long N,M;
vector<int> v;

int main() {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int l = 0;
    int r = 2'000'000'000;
    long long ans;
    while(l<=r) {
        long long mid = (l+r)/2;

        long long tot = 0;

        for(int i=0;i<v.size();i++)
            tot += (v[i] - mid) < 0 ? 0 : v[i] - mid;

        if(tot >= M) {
            l = mid + 1;
            ans = mid;
        }
        else r = mid -1; 
    }

    cout << ans;
}