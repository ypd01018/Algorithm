#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int N,M;
int main() {
    cin >> N >> M;
    M = min(M,N-M);
    long long parent = 1;
    long long child = 1;

    for(int i=0;i<M;i++) {
        parent *= N--;
        cout << parent << endl;
    }

    for(int i=0;M>0;i++) {
        child *= M--;
    }

    cout << parent << ' ' << child << endl;
}