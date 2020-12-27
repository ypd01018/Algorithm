#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
stack<int> stk,ans;
int N;
vector<int> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int a; cin >> a;
        v.push_back(a);
    }
    for(int i= v.size()-1;i>=0;i--)
    {
        bool flag = true;
        while(!stk.empty())
        {
            int val = stk.top();
            if(val>v[i])
            {
                stk.push(v[i]);
                flag = false;
                ans.push(val);
                break;
            }
            stk.pop();
        }
        if(flag)
        {
            stk.push({v[i]});
            ans.push(-1);
            continue;
        }
    }
    while(!ans.empty())
    {
        cout << ans.top()<<' '; ans.pop();
    }
}