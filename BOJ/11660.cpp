#include<iostream>
#define endl "\n"
using namespace std;
int n, m;
long long sum[1100][1100];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int tmp; cin >> tmp;
			sum[i][j] += tmp + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		//cout <<sum[x2][y2] << '-' <<sum[x1 - 1][y2]<< '-'<< sum[x2][y1 - 1] <<'+'<< sum[x1 - 1][y1 - 1] << endl;
		cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << endl;
	}
}