#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
ll N,S;
ll gcd(ll a,ll b)
{
    while(b!=0)
    {
        ll r = a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> S;
    ll a; cin >> a;
    a = abs(S-a);
    for(int i=1;i<N;i++)
    {
        int b; cin >> b;
        b=abs(S-b);
        a=gcd(a,b);
    }
    cout << a;
}