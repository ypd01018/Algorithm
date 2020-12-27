#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N;
stack<int> stk;
int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int a; cin >> a;
        if(!a) stk.pop();
        else stk.push(a);
    }
    long long ans=0;
    while(!stk.empty())
    {
        ans += (long long)stk.top();
        stk.pop();
    }
    cout << ans;
}