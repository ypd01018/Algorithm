#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int lego[2000010];
int x,n,L1,L2,mx=-1;
void go()
{
    for(int i=0;i<n-1;i++)
    {
        int a = lego[i];
        int b = x-lego[i];
        int idx = lower_bound(lego+i+1,lego+n,b)-lego;
        if(idx>=n) continue;
        if(a+lego[idx]==x)
        {
            L1 = a; L2=b;
            return;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    while(cin >> x)
    {
        cin >> n;
        for(int i=0;i<n;i++) cin >> lego[i];
        L1=L2=-1;
        if(n>=2)
        {
            x *= 10'000'000;
            sort(lego,lego+n);
            go();
        }
        if(L1==-1&&L2==-1) cout << "danger" << endl;
        else cout << "yes " << L1 << ' ' << L2 << endl;    
    }

}