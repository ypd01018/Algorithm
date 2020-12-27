#include<bits/stdc++.h>
#define endl "\n"
#define ll long long 
using namespace std;
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
    for(int i=0;i<3;i++) cout << ans[i] << ' ';
} 