#include<bits/stdc++.h>
#define endl '\n';
#define ll long long
using namespace std;
int N,n_vertex[300002];
ll g,d;
vector<int> node[300002];

ll ncr(ll n, ll r) {
	if (n < r) {
		return 0;
	}
	if (r == 2LL) {
		return n * (n - 1) / 2LL;
	}
	if (r == 3LL) {
		return n * (n - 1) * (n - 2) / 6LL;
	}
}
int main(){
    cin >> N;
    for(int i=0;i<N-1;i++){
        int a,b; cin >> a >> b;
        node[a].push_back(b);
        n_vertex[a]++; n_vertex[b]++;
    }
    
    for(int i=1;i<=N;i++){
        int a = i;
        if(n_vertex[a]>=3) g+= ncr(n_vertex[a],3);
        for(int j=0;j<node[i].size();j++){
            int b = node[i][j];
            if(n_vertex[a]>1 && n_vertex[b]>1){
                d += (n_vertex[a]-1) * (n_vertex[b]-1);
            }
        }
    }
    cout << d << ' ' << g << endl;
    if(d > 3*g) cout << 'D';
    else if(d < 3*g) cout << 'G';
    else cout << "DUDUDUNGA";
}