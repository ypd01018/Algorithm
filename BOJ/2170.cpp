#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int N;
vector<pair<int,int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first < b.first) return true;
    else if(a.first > b.first) return false;
    else{
        if(a.second < b.second) return true;
        else return false; 
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(), cmp);
    int mx_end = v[0].first;
    int answer = 0; 
    for(int i=0;i<v.size();i++) {
        int start = v[i].first, end = v[i].second;
        if(mx_end > end) continue;
        answer += end - max(mx_end, start);
        mx_end = end;
    }

    cout << answer;
}