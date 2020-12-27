#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
ll N;
ll arr[2][300002], mn = LLONG_MAX;
ll llmin(ll a,ll b)
{
    if(a>b) return b;
    else return a;
}
ll go(ll mid)
{
    if(mid<0 || mid>1e12) return LLONG_MAX;
	ll ret=0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ll block = mid + abs((N / 2) - j);
			ret += abs(arr[i][j] - block);
		}
	}
    mn = llmin(ret,mn);
	return ret;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	ll start = 0, end = 1e12+1;
	while (start <= end)
	{
		ll mid = (start + end) / 2;
		if (go(mid)>go(mid+1)) start = mid + 1;
		else end = mid - 1;
	}
	cout << mn;

}