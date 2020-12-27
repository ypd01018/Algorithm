#include<iostream>
#define endl "\n"
using namespace std;
string a;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> a;
    for(int i=0;i<a.size();i++)
    {
        if('A'<=a[i] && a[i]<='Z') cout << a[i];
    }
}