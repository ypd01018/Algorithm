#include<bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;
const ll MAX = 1000000000;
ll tree[3000000];
ll num[1000001];

ll init(int index, int start, int end)
{
    if (start == end)
        return tree[index] = num[start];
    int mid = (start + end) / 2;
    tree[index] = min(init(index * 2, start, mid),init(index * 2 + 1, mid + 1, end));
    return tree[index];
}

ll mn(int lft, int rght, int index, int start, int end)
{
    if (lft <= start && end <= rght) 
        return tree[index];
    if (rght < start || end < lft)
        return MAX;
 
    int mid = (start + end) / 2;
    return min(mn(lft, rght, index * 2, start, mid),mn(lft, rght, index * 2 + 1, mid + 1, end));
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        cin >> num[i];
    init(1, 1, N);

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << mn(a, b, 1, 1, N) << endl;
    }
}

