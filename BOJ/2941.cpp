#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
string a;
int cnt;
int check(int idx)
{  
    if(idx+1 == a.size()) return 0;

    char a_=a[idx], b_=a[idx+1];
    if(a_ == 'c' && (b_=='=' || b_=='-')) return 1;
    else if(a_=='d')
    {
        if(b_=='-') return 1;
        if(idx+2 != a.size() && b_=='z' && a[idx+2]=='=') return 2;
    }
    else if(a_=='l' && b_=='j') return 1;
    else if(a_=='n' && b_=='j') return 1;
    else if(a_=='s' && b_=='=') return 1;
    else if(a_=='z' && b_=='=') return 1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> a;
    for(int i=0;i<a.size();i++)
    {
        i+=check(i);
        cnt++;
    }
    cout << cnt;
}