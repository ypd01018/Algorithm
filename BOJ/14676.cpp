#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int N,M,K,build[100002],need[100002];
vector<int> nxt[100002];
bool test_time_line(){
    int a,b;
    for(int i=0;i<K;i++){
        cin >> a >> b;
        if(a==1){
            if(need[b]>0) return false;
            if(!build[b]){
                for(int j=0;j<nxt[b].size();j++){
                    need[nxt[b][j]]--;
                }
            }
            build[b]++;
        }
        else{
            if(--build[b]<0) return false;
            if(build[b]==0){
                for(int j=0;j<nxt[b].size();j++) need[nxt[b][j]]++;
            }
        }
    }
    return true;
}
int main(){
    cin >> N >> M >> K;
    for(int i=0;i<M;i++){
        int a,b; cin >> a >> b;
        nxt[a].push_back(b);
        need[b]++;
    }
    if(test_time_line()) cout << "King-God-Emperor";
    else cout << "Lier!";
}