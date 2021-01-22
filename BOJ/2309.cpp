#include<bits/stdc++.h>
#define endl '\n'

using namespace std;
vector<int> v;
int visit[9],arr[9];
void dfs(int idx, int cnt, int sum) {
    if(cnt == 7) {
        if(sum == 100){
            sort(v.begin(), v.end());
            for(int i=0;i<v.size();i++) cout << v[i] << ' ';
            exit(0);
        }
        return;
    }

    for(int i = idx+1; i<9;i++) {
        if(i>=9 || visit[i]) continue;
        visit[i] = 1;
        v.push_back(arr[i]);
        dfs(i, cnt+1, sum+arr[i]);
        visit[i] = 0;
        v.pop_back();
    }

}
int main() {

    for(int i=0;i<9;i++) cin >> arr[i];
    for(int i=0;i<3;i++) {
        visit[i] = 1;
        v.push_back(arr[i]);
        dfs(i, 1, arr[i]);
        visit[i] = 0;
        v.pop_back();
    }
}