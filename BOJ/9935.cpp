#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
string a,b,ans;
int idx;
vector<char> v;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b;
    for(int i=0;i<a.size();i++)
    {
        v.push_back(a[i]);
        if(a[i]==b[b.size()-1])
        {
            bool flag = true;
            for(int j=0;(i-b.size()>=-1)&&j<b.size();j++)
            {
                if(a[i-j]==b[j]) continue;
                flag = false; break;
            }
            if(!flag) continue;
            for(int j=0;j<b.size();j++) v.pop_back();
        }
    }
    if(lst.size()) for(iter = lst.begin();iter!=lst.end();iter++) cout << *iter;
    else cout << "FRULA";
}