#include <bits/stdc++.h>
using namespace std;
int n, m, match[1010],cnt; 
bool visited[1010];
vector<vector<int>> v(1001); 
 
bool dfs(int here)
{
    if(visited[here]) return false;
    visited[here] = 1;
    for (int i = 0; i < v[here].size(); i++) 
    {
        int work = v[here][i];
        if (!match[work] || dfs(match[work]))
        {
            match[work] = here; 
            return true;
        }
    } 
    return false;
}
 
int main() 
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
    {
        int j; cin >> j;
        for (int k = 1; k <= j; k++) 
        {
            int temp; cin >> temp;
            v[i].push_back(temp);
        }
    } 
    for (int i = 1; i <= n; i++) 
    {
        memset(visited, 0, sizeof(visited));
        if (dfs(i)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
