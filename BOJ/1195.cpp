#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
string a,b;
int mn;
bool check(int a_end)
{
    int i=0,b_end = b.size()-1; 
    if(a_end>=a.size()) 
    {
        b_end=b.size()-1-(a_end-a.size());
        a_end = a.size()-1;
    }
    for(i;a_end-i>=0 && b_end-i>=0;i++)
    {
        if((a[a_end-i]=='2')&&(a[a_end-i]==b[b_end-i])) return false;
        if(0==(b_end-i) && b_end==b.size()-1) return true;
    }
    mn = min(mn,(int)(a.size()+b.size()-i));
    return false;
}
int main()
{
    cin >> a >> b;
    mn = a.size()+b.size();
    if(a.size()<b.size()) swap(a,b);
    for(int i=0;i<a.size()+b.size();i++)
    {
        if(check(i)){cout << a.size(); return 0;}
    }
    cout << mn;
}
