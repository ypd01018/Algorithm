#include<iostream>
#define endl "\n"

using namespace std;
int n, m;
long long sum[100'010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		sum[i] += sum[i - 1] + tmp;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a - 1]<<endl;
	}
}