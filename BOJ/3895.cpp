#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n,k,m;
int sol(){
    vector<int> v;
    for(int i=1;i<=n;i++) v.push_back(i);
    vector<int>::iterator iter = v.begin()+m-1;
    iter = v.erase(iter);
    int last = m, delete_num = m-1;
    while(!v.empty()){
        delete_num = (delete_num-1+k)%v.size();
        iter = v.begin() + delete_num;
        last = *iter;
        v.erase(iter);
    }
    return last;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(1){
        cin >> n >> k >> m;
        if(!n&&!k&&!m) break;
        cout << sol() << endl;
    }
}