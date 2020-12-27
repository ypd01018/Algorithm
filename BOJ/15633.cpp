#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a; cin >> a;
    int cnt =0;
    for(int i=1;i<=a;i++)
    {
        if(a%i==0) cnt+=i;
    }
    cout << cnt*5-24;
}