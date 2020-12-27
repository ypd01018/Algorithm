#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int T,x,y;
int sol()
{
    cin >> x >> y;
    ll val = 1,ret=1;
    for(int i=1;val<y-x-1;i++)
    {
        val += i/2;
        cout<<"  " <<ret <<','<< val << endl;
        ret++;
    }
    return ret;
}
int main()
{
    //ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    for(int i=0;i<T;i++) cout << sol() << endl;
}