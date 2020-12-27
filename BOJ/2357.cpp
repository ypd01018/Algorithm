#include<bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;
const ll MAX = 1000000000;
ll mx_tree[3000000],mn_tree[3000000];
ll num[1000001];

ll mn_init(int index, int start, int end)
{
    if (start == end)
        return mn_tree[index] = num[start];
    int mid = (start + end) / 2;
    mn_tree[index] = min(mn_init(index * 2, start, mid),mn_init(index * 2 + 1, mid + 1, end));
    return mn_tree[index];
}

ll mx_init(int index, int start, int end)
{
    if (start == end)
        return mx_tree[index] = num[start];
    int mid = (start + end) / 2;
    mx_tree[index] = max(mx_init(index * 2, start, mid),mx_init(index * 2 + 1, mid + 1, end));
    return mx_tree[index];
}

ll mn(int lft, int rght, int index, int start, int end)
{
    if (lft <= start && end <= rght) 
        return mn_tree[index];
    if (rght < start || end < lft)
        return MAX;
 
    int mid = (start + end) / 2;
    return min(mn(lft, rght, index * 2, start, mid),mn(lft, rght, index * 2 + 1, mid + 1, end));
}
ll mx(int lft, int rght, int index, int start, int end)
{
    if (lft <= start && end <= rght) 
        return mx_tree[index];
    if (rght < start || end < lft)
        return -1;
 
    int mid = (start + end) / 2;
    return max(mx(lft, rght, index * 2, start, mid),mx(lft, rght, index * 2 + 1, mid + 1, end));
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        cin >> num[i];
    mn_init(1, 1, N);
    mx_init(1, 1, N);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << mn(a, b, 1, 1, N) <<' '<<mx(a, b, 1, 1, N) <<endl;
    }
}

