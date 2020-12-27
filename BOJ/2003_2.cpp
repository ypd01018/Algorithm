#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,arr[10100],lft,rght,sum,cnt;
int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> arr[i];
    sum =arr[0];
    while(lft <= rght && rght < n)
    {
        if(sum < m)
        {
            rght++;
            sum += arr[rght];
        }
        else if(sum ==m)
        {
            cnt++;
            rght++;
            sum += arr[rght];
        }
        else
        {
            sum -= arr[lft];
            lft++;
            if(lft > rght && lft < n)
            {
                rght = lft;
                sum = arr[lft];
            }
        }
    }

    cout << cnt;
}