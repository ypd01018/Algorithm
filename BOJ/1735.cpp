#include<bits/stdc++.h>
#define endl "\n"
#define ll unsigned long long
using namespace std;
ll gcd(ll a, ll b)
{
    if(b==0){ return a;}
    else return gcd(b,a%b);
}
ll lcm(ll a, ll b)
{
    return a*b/gcd(a,b);
}
int main()
{
    int ja1,ja2,mo1,mo2;
    cin >> ja1 >>mo1 >>ja2 >>mo2;
    ll gcd_1 = gcd(max(ja1,mo1),min(ja1,mo1));
    int gcd_2 = gcd(max(ja2,mo2),min(ja2,mo2));

    ja1 /= gcd_1;
    mo1 /= gcd_1;
    ja2 /= gcd_2;   
    mo2 /= gcd_2;

    ll mo=lcm(max(mo1,mo2),min(mo1,mo2));
    ll ja=(mo/mo1)*ja1+ja2*(mo/mo2);
    ll _gcd = gcd(max(mo,ja),min(mo,ja));
    mo /= _gcd;
    ja /= _gcd;
    cout <<ja<<" "<<mo;     
}