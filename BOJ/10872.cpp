#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    long long N;
    cin >> N;
    long long ans=1;
    for(long long i=2;i<=N;i++) ans*=i;
    cout << ans;
}