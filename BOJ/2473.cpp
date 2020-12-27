#include<bits/stdc++.h>
#define endl "\n"
#define ll long long 
using namespace std;
<<<<<<< HEAD
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
=======
int N,ans[3];
vector<ll> v;
ll mn=LLONG_MAX;
bool flag;

void two_pointer(int lft)
{
    int mid=lft+1,rght=N-1;
    
    while(1)
    {
        if(mid >= rght) break;

        ll sum = v[lft]+v[mid]+v[rght];
        ll val = llabs(sum);
        if(val<mn)
        {
            mn = val;
            ans[0]=v[lft]; ans[1]=v[mid]; ans[2]=v[rght];
        }

        if(sum<0)
        {
            mid++;
        }
        else if(sum>0)
        {
            rght--;
        }
        else
        {
            flag=true;
            return;
        }
    }
    
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N; v.resize(N);
    for(int i=0;i<N;i++) cin >> v[i];
    sort(v.begin(),v.end());
    for(int i=0;i<N && !flag;i++) two_pointer(i);
>>>>>>> c970bb23ae158ddb0c279d0af13d5172eedb711b
    for(int i=0;i<3;i++) cout << ans[i] << ' ';
} 