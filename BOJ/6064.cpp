#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int T;
int solve(int m, int n, int x, int y)
{
    if(x==m) x=0;
    if(y==n) y=0;
    for(int i=x;i<= m*n;i+=m)
    {
        if(i%n==y) return i;
    }
    return -1;
}
int main()
{
    int n,m,x,y;
    cin >> T;
    for(int i=0;i<T;i++)
    {
        cin >> m >> n >> x >> y;
        cout << solve(m,n,x,y) << endl;
    }
}