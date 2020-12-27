#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    if(b>=c){cout << -1; return 0;}
    double x = (double)a/(double)(c-b);
    cout << (int)(x+1);
}