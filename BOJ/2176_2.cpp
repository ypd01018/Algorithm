#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, M, n_node[1002], d[1002][1002];
vector<int> node[1002];
int visit[1002];
void DFS(int a)
{
    for (int i = 0; i < node[a].size(); i++)
    {
        int b = node[a][i];
        if (d[2] - d[b] < d[2] - d[a])
            n_node[b] += n_node[a];
    }
    for (int i = 0; i < node[a].size(); i++)
    {
        int b = node[a][i];
        if (visit[b])
            continue;
        visit[b] = 1;
        if (d[2] - d[b] < d[2] - d[a])
            DFS(b);
    }
}
int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        node[A].push_back(B);
        node[B].push_back(A);
        d[A][B] = d[B][A] = C;
    }
    n_node[1] = 1;
    DFS(1);
    cout << n_node[2];
}