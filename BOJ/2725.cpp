#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int c,n,ans[2000]={0,2};
int gcd(int a, int b)
{
    if(b==0) return a;
    else
    {
        return gcd(b,a%b);
    }
    
}
void sol()
{
    for(int i=2;i<1003;i++)
    {
    int cnt=0;
        for(int j=1;j<i;j++)
        {
            if(gcd(max(i,j),min(i,j))==1) cnt++;
        }
        ans[i]=ans[i-1]+cnt;
    }
}
int main()
{
    sol();
    cin >> c;
    for(int i=0;i<c;i++)
    {
        cin >> n;
        cout << ans[n]*2-1<<endl;
    }
}