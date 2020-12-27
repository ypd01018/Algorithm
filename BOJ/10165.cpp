#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int N,M;
vector<pair<int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first<b.first) return true;
    else if(a.first>b.first) return false;
    else{
        if(a.second>b.second) return true;
        else return false;
    }
}

bool bianry_search(int idx){
    int l=0,r=idx-1;
    int start = v[idx].first, end = v[idx].second;
    while(l<=r){
        int mid = (l+r)/2;
        int s = v[mid].first , e = v[mid].second;
        if()
    }
}

int main(){
    cin >> N >> M;
    for(int i;i<M;i++){
        int a,b; cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);

}