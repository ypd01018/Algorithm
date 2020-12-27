#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int N,M;
bool check[500002];
vector<pair<int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first<b.first) return true;
    else if(a.first>b.first) return false;
    else{
        if(a.second>b.second) return true;
        else return false;
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i;i<M;i++){
        int a,b; cin >> a >> b;
        v.push_back({a,b});
    }
    for(int i=0;i<v.size();i++){
        if(check[i]) continue;
        
    }
}