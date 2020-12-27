#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int l,u,x,T;
void sol()
{
    cin >> l >> u >> x;
    if(x<l)
    {
        cout << l-x << endl;
    }
    else if(x<u)
    {
        cout << 0;
    }
    else
    {
        cout << -1;
    }
    
    
}
int main()
{
    cin >> T;
    for(int i=1;i<=T;i++)
    {
        cout << '#' << i <<' ';
        sol();
        cout << endl;
    }
}