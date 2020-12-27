#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> tree, arr;
int h[1'000'010];

void update(int node, int start, int end, int idx, int diff)
{
	if(idx<start || idx>end) return;
	tree[node] += diff;
	if(start^end)
    {
	    update(node*2, start, (start+end)/2, idx, diff);
        update(node*2+1, (start+end)/2+1, end, idx, diff);
	}
}

ll sum(int node, int start, int end, int lft, int rght)
{
	if(lft>end || rght<start) return 0;
	if(lft<=start && end<=rght) return tree[node];
	return sum(node*2, start, (start+end)/2, lft, rght) + sum(node*2+1, (start+end)/2+1, end, lft, rght);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
    arr = vector<ll>(n+10);
	tree = vector<ll>(4*n+40);
	for(int i=1; i<=n; i++)
    {
		ll a; cin >> a;
		h[a] = i;
	}
	for(int i=1; i<=n; i++)
    {
		ll a; cin >> a;
		arr[i] = h[a];
	}

	ll ans = 0;

	for(int i=1; i<=n; i++)
    {
		int j = arr[i];
		ans += sum(1, 1, n, j+1, n);
		update(1, 1, n, j, 1);
	}
	cout << ans;
}