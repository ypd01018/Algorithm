#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
unordered_map<int,vector<pair<int,int>>> m;
int main(){
    m[0].push_back({1,2});
    cout << m[0][0].first;
}