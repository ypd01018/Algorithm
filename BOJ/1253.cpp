#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,arr[2010],cnt,lft,rght;
void two_pointer(int target,int idx)
{
    lft=0;rght=n-1;
    while(lft<rght)
    {
        if(arr[lft]+arr[rght] == target)
        {
            if(lft != idx && rght != idx)
            {
                cnt++;
                break;    
            }

            if(rght == idx) rght--;
            else if(lft==idx) lft++;

        }
        else if(arr[lft]+arr[rght] < target)
        {
            lft++;
        }
        else if(arr[lft]+arr[rght] > target)
        {
            rght--;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];

    sort(arr,arr+n);
    lft=0;rght=n-1;
    for(int i=0;i<n;i++)
    {
        two_pointer(arr[i],i);
    }
    cout << cnt;
}