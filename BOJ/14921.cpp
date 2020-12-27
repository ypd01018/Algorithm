#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
long long n,arr[100'010],mn=LLONG_MAX,result[2];
bool compare(ll a, ll b)
{
    return abs(a) > abs(b);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+n,compare);
    for(auto i=0;i<n-1;i++)
    {
        int hap = arr[i]+arr[i+1];
        if(abs(hap) < abs(mn))
        {
            mn = hap;
            result[0] = arr[i];
            result[1] = arr[i+1];
        }
    }

    cout << min(result[0],result[1])<< ' ' << max(result[1],result[0]);
}