#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int N,M,mn=1e9;
char mat[51][51];
char color[2] = {'B', 'W'};
int check(int y, int x) {
    int cnt[2] = {0};
    for(int k=0;k<2;k++) {
        int n = k;
        for (int i = y; i < y + 8; i++){
            for (int j = x; j < x + 8; j++){
                char this_color = mat[i][j];
                char want_color = color[(n++)%2];
                if(this_color != want_color) cnt[k]++;
            }
            n++;
        }
    }
    return min(cnt[0],cnt[1]);
}
int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        string input;
        cin >> input;
        for(int j=0;j<M;j++) {
            mat[i][j] = input[j];
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(i+8 > N || j+8 > M) continue;
            mn = min(check(i,j),mn);
        }
    }

    cout << mn;
}