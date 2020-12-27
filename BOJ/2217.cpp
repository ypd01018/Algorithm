#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,mx=0,mn=INT_MAX,arr[100'010],tot,cnt;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    mx = mn = arr[n-1];
    tot = arr[n-1];
    cnt=1;
    for(int i=n-2;i>-1;i--)
    {
        tot += arr[i];
        cnt++;
        mn = min(mn,arr[i]);
        //if(mx > mn*cnt ) break;
        mx = max(mx,mn * cnt);
    }
    cout << mx;
}