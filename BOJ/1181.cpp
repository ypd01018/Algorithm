#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#define endl "\n"
using namespace std;
int N;
string str[20'002];
set<string> s;
bool cmp(string a, string b)
{
    if(a.size()<b.size()) return true;
    else if(a.size()>b.size()) return false;
    else
    {
        if(a<b) return true;
        else return false;
    }
    
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) cin >>str[i];
    sort(str,str+N,cmp);
    for(int i=0;i<N;i++) 
    {
        if(s.count(str[i])) continue;
        s.insert(str[i]);
        cout << str[i] << endl;
    }
}
