#include<bits/stdc++.h>
#define endl "\n"
#define s second
#define e first
#define ll long long
using namespace std;
int n,cnt;
double check;
pair<int,int> arr[100'010];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i].s >> arr[i].e;
    }
    sort(arr,arr+n);
    // for(int i=0;i<n;i++)
    // {
    //     cout << arr[i].s << ' ' << arr[i].e << endl;
    // }
    check = arr[0].e;
    cnt=1;

    for(int i=1;i<n;i++)
    {
        if(arr[i].s >= check)
        {
            cnt++;
            check = arr[i].e;
        }
    }
    cout << cnt;
}