#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
ll arr[1000010],n,b,c,cnt;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    cin >> b >> c;
    for(int i=0;i<n;i++)
    {
        arr[i] -= b;
        cnt++;

        if(arr[i]<=0) continue;
        if(arr[i]<=c)
        {
            cnt++;
            continue;
        }
        else
        {
            if(arr[i]%c==0)
            {
                cnt += arr[i]/c;
            }
            else
            {
                cnt += 1+arr[i]/c;
            }
        }
    }
    cout << cnt;
}