#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
string name;
int cnt;
map<string,int> mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    while(getline(cin,name))
    {
        //if(name == "d") break;
        cnt++;
        mp[name]++;
    }

    map<string,int>::iterator iter;
    cout << fixed;
    cout.precision(4);
    for(iter=mp.begin();iter!=mp.end();iter++)
    {
        cout << iter->first << " " << (((double)iter->second)/(double)cnt)*100 << endl;
    }

}