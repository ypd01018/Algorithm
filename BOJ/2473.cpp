#include<bits/stdc++.h>
#define endl "\n"
#define ll long long 
using namespace std;
int N,ans[3],mid=-1;
ll arr[5002];
ll mn=INT_MAX;
ll ret_abs(ll a)
{
    if(a>=0) return a;
    else return -1*a;
} 
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i];
    sort(arr,arr+N);
    for(int i=0;i<N;i++)
    {
        if(arr[i]>=0)
        {
            mid = i;
            break;
        } 
    }
    for(int i=0;i<N-2;i++)
    {
        for(int j=i+1;j<N-1;j++)
        {
            for(int k=j+1;k<N;k++)
            {
                ll hap = arr[i]+arr[j]+arr[k];      
                if(ret_abs(hap)<mn)
                {
                    mn=ret_abs(hap);
                    ans[0]=i; ans[1]=j; ans[2]=k;
                }
            }
        }
    }
    sort(ans,ans+3);
    for(int i=0;i<3;i++) cout << ans[i] << ' ';
} 