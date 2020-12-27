#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<int> v[1005];
int work[1005];
bool finish[1005];
bool DFS(int a)
{
	for (int i = 0; i < v[a].size(); i++) 
    {
		int t = v[a][i]; 
		if (finish[t]) continue;
		finish[t] = true;
		if (work[t] == 0 || DFS(work[t])) 
        {
			work[t] = a;
			return true;
		}
	}
	return false;
}
 
int main() 
{
    int n,m,c,num,cnt=0;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) 
    {
		cin >> c;
		for (int j = 0; j < c; ++j) 
        {
			cin >> num;
			v[i].push_back(num);
		}
	}
	fill(work, work + 1010, 0);
	for (int i = 1; i <= n; ++i) 
    {
		for (int j = 1; j <= 2; ++j) 
        {
			fill(finish, finish + 1010, false);
			if (DFS(i)) cnt++;
		}
	}
 
	cout << cnt << endl;
}