#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int cnt;
string input;
vector<string> v;
string make_origin(string a)
{
    string ret = "";
    int n = 4-a.size();
    for(int i=0;i<n;i++)
    {
        ret.push_back('0');
    }
    ret.append(a);
    return ret;
}
int main()
{
    cin >> input;
    string group="";
    bool flag = true;
    for(int i=0;i<input.size();i++)
    {
        if(input[i]==':')
        {
            if(group=="" && flag)
            {
                flag = false;
                v.push_back("check");
            }
            else if(group!="")
            {
                cnt++;
                v.push_back(make_origin(group));
                group.clear();
            }
        }
        else group.push_back(input[i]);
        if(i==input.size()-1) 
        {
            if(group!="")
            {
                cnt++;
                v.push_back(make_origin(group));
            }
        }
    }
    string ans="";
    for(int i=0;i<v.size();i++)
    {
        if(v[i]=="check")
        {
            string zero="";
            for(int j=0;j<8-cnt;j++)
            {
                zero.append("0000:");
            }
            ans.append(zero);
        }
        else
        {
            ans.append(v[i]);
            ans.push_back(':');
        }
    }
    ans.pop_back();
    cout << ans;
}