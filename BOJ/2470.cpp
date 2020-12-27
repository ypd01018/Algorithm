#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int N;
ll mn = LLONG_MAX,ans[2];
vector<ll> v;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N; v.resize(N);
    for(int i=0;i<N;i++) cin >> v[i];
    sort(v.begin(),v.end());
    int lft = 0, rght = N-1;
    while(1)
    {
        if(lft>=rght) break;
        ll sum = v[lft] + v[rght];
        if(mn>llabs(sum))
        {
            mn = llabs(sum);
            ans[0]=v[lft]; ans[1]=v[rght];
        }
        if(sum<0) lft++;
        else if(sum>0) rght--;
        else break;
    }
    cout << ans[0]<<' ' << ans[1];
}