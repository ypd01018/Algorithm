#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

ll tree[3'000'000];
ll num[1000001];

ll init(int index, int start, int end)
{
    if (start == end)
        return tree[index] = num[start];
    int mid = (start + end) / 2;
    tree[index] = init(index * 2, start, mid) + init(index * 2 + 1, mid + 1, end);
    return tree[index];
}

void update(int index, int start, int end, int changed_index, int diff)
{
    if (start <= changed_index && changed_index <= end)
        tree[index] += diff;
    else
        return;

    if (start == end)
        return;

    int mid = (start + end) / 2;
    update(index * 2, start, mid, changed_index, diff);
    update(index * 2 + 1, mid + 1, end, changed_index, diff);
}

ll sum(int lft, int rght, int index, int start, int end)
{
    if (lft <= start && end <= rght) 
        return tree[index];
    if (rght < start || end < lft)
        return 0;
 
    int mid = (start + end) / 2;
    return sum(lft, rght, index * 2, start, mid) + sum(lft, rght, index * 2 + 1, mid + 1, end);
}


int main()
{
    int N, M, K;
    cin >> N >> M >>K;
    for (int i = 1; i <= N; ++i)
        cin >> num[i];
    init(1, 1, N);
    for (int i = 0; i < M + K; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            int diff = c - num[b];
            num[b] = c;
            update(1, 1, N, b, diff);
        }
        else
            cout << sum(b, c, 1, 1, N) << endl;
    }
}

