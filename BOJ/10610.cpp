#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
string n;
vector<int> v;
bool flag;
int main()
{
    cin >> n;
    int total=0;
    for(int i=0;i<n.size();i++)
    {
        if(n[i]=='0') flag = true;
        total += n[i]-'0';
        v.push_back(n[i]-'0');
    }
    if( (total%3)!= 0) flag = false;

    if(!flag) cout << -1;
    else
    {
        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>-1;i--) cout << v[i];
    }


}