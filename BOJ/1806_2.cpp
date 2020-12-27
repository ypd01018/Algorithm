#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,arr[100010],lft,rght,ans=INT_MAX,len,sum;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> arr[i];
    sum = arr[0];

    while(lft <= rght && rght < n)
    {
        if(sum >= m)
        {
            //cout << "case1"<<endl;
            len = rght-lft+1;
            ans = min(len,ans);
            sum -= arr[lft];
            lft++;
            if(lft > rght && lft < n)
            {
                rght = lft;
                sum = arr[lft];
            }
        }
        else
        {
            //cout << "case2"<<endl;
            rght++;
            sum += arr[rght];
        }
    }
    if(ans == INT_MAX) cout << 0;
    else cout << ans;
}