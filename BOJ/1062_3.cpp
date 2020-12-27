#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int N,K,alp_check,words[60],mx;
string need = "acint";
void go(int k,int idx){
    if(k==K){
        int n_word = 0;
        string test = "";
        for(int i=0;i<N;i++){
            if( (words[i]&alp_check) == words[i]) n_word++;
        }
        mx = max(mx,n_word);
        return;
    }
    for(int i = idx;i<26;i++){
        if(alp_check&(1<<i)) continue;
        int tmp = alp_check;
        alp_check |= 1<<i;
        go(k+1,i+1);
        alp_check = tmp;
    }
}

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++){
        string word; cin >> word;
        for(int j=0;j<word.size();j++) {
            words[i] |= (1<<(word[j]-'a'));
        }
    }
    K -=5;
    if(K<0){
        cout << 0;
        return 0;
    }
    for(int i=0;i<need.size();i++) alp_check |= 1<<(need[i]-'a');
    go(0,0);
    cout << mx;
}
