#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,cnt;
map<string,int> mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string input,state; cin >> input >> state;
        if(state=="enter") mp[input]++;
        else mp[input]--;
    }

    map<string,int>::iterator iter = mp.end();

    while(1)
    {
        iter--;
        if(iter->second>0) cout << iter->first<<endl;
        if(iter==mp.begin()) break;
    }
}