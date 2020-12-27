#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N;
vector<int> v,ans;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int a; cin >> a;
        v.push_back(a);
    }
    for(int i=0;i<N;i++)
    {
        int a = v[i];
        if(ans.empty() || a>ans.back())
        {
            ans.push_back(a);
            continue;
        }
        vector<int>::iterator iter = lower_bound(ans.begin(),ans.end(),a);
        ans[iter-ans.begin()] = a;
    }
    cout << ans.size();
}