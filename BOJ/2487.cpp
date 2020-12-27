#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int N,arr[20010],visit[20010],origin,val=1;
int go(int a,int n)
{
    if(a==origin) return n;
    visit[a]=1;
    return go(arr[a],n+1);
}
ll gcd(ll a, ll b)
{
    while(b!=0)
    {
        ll r = a%b;
        a=b;
        b=r;
    }
    return a;
}
ll lcm(ll a, ll b)
{
    return a*b/gcd(a,b);
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        cin >> arr[i];
    }
    for(int i=1;i<=N;i++)
    {
        if(visit[i]) continue;
        origin = i;
        val = lcm(go(arr[i],1),val);
    }
    cout << val;
}