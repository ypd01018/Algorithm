#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
ll n,q;
ll x,y,a,b;
ll tree[4'000'000];
ll num[1'000'001];

ll init(int index, int start, int end)
{
    if (start == end)
        return tree[index] = num[start];
    int mid = (start + end) / 2;
    tree[index] = init(index * 2, start, mid) + init(index * 2 + 1, mid + 1, end);
    return tree[index];
}

void update(int index, int start, int end, int changed_index, ll diff)
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
    ios::sync_with_stdio(0);cin.tie(0);

    cin >> n >> q;

    for(ll i=1;i<=n;++i)
    {
        cin >> num[i];
    }
    
    init(1, 1, n);
    
    for(ll i=0;i<q;i++)
    {
        cin >> x >> y >> a >> b;

        if(x > y) swap(x,y);
        cout << sum(x,y,1,1,n)<< endl;
        ll diff = b - num[a];
        
        update(1, 1, n, a, diff);
        num[a]=b;
    }
}