#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int mn;
string atob_string(string s, int a, int b)
{
    string ret;
    for(int i=a;i<b && i<s.size();i++) ret.push_back(s[i]);
    return ret;
}
int compression(string s,int n)
{
    string ans;
    string a="",b; int cnt=1;
    int i=0,j;
    while(i<s.size())
    {
        a = atob_string(s,i,i+n);
        for(j=i+n;j<s.size();j+=n)
        {
            b = atob_string(s,j,j+n);
            if(a==b) cnt++;
            else break;
        }
        if(cnt>1) ans.append(to_string(cnt));
        ans.append(a);
        cnt=1; i=j;
    }
    return ans.size();
}
int solution(string s) 
{
    mn = s.size();
    for(int i=1;i<=s.size()/2;i++) mn = min(mn,compression(s,i));
    return mn;
}

int main()
{
    string s = "a";
    cout << solution(s);
}