#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int V,E,answer ,cnt = 1;
int root[100010];
vector<pair<int,pair<int,int>>> v;

void init() {
    for(int i=0;i<=V;i++) root[i] = i;
}

int find(int a) {
    if(root[a] == a) return a;
    else return root[a] = find(root[a]);
}

void uni(int a, int b) {
    a = root[a];
    b = root[b];
    root[b] = a;
}

int main() {
    cin >> V >> E;

    for(int i=0;i<E;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        v.push_back({c,{a,b}});
    }
    init();
    sort(v.begin(), v.end());

    for(int i=0;i<v.size();i++) {
        int d = v[i].first;
        int a = v[i].second.first;
        int b = v[i].second.second;

        if(find(a) == find(b)) continue;

        cnt++;
        answer += d;
        uni(a,b);

        if(cnt == V) break;
    }

    cout << answer;
}