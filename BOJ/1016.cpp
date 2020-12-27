#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int check[1'000'010], non_sosu[1'000'010];
ll a,b,ans;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b;
    ans = b-a+1;
    for(ll i=2;i*i<=b;i++)
    {
        if(non_sosu[i]) continue;
        for(ll j=i;j*j<=b;j+=i) non_sosu[j]=1;
        ll start = ((a-1)/(i*i)+1)*i*i;
        for(ll j=start;j<=b;j+=i*i) 
            if(!check[j-a])
            {
                check[j-a]=1;
                ans--;
            }
    }
    cout << ans;
}