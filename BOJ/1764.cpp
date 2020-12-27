#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,cnt;
map<string,int> mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        string input; cin >> input;
        mp[input]++;
    }
    for(int i=0;i<m;i++)
    {
        string input; cin >> input;
        mp[input]++;
        if(mp[input]>1) cnt++;
    }
    cout << cnt << endl;
    map<string,int>::iterator iter;
    for(iter = mp.begin();iter!=mp.end();iter++)
    {
        if(iter->second>1) cout << iter->first<<endl;
    }
}