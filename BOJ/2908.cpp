#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
string a,b;
int ten=10,num_a,num_b;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> a;
    cin >> b;
    for(int i=a.size()-1;i>=0;i--)
    {
        num_a *=10;
        num_a += a[i]-'0';
    }
    for(int i=b.size()-1;i>=0;i--)
    {
        num_b *=10;
        num_b += b[i]-'0';
    }
    //cout << num_a << endl << num_b;
    if(num_a > num_b) cout <<num_a;
    else cout << num_b;
}