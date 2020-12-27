#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int idx,cnt[30],mx,ans;
bool flag=true;
string a;
int main()
{
    cin >> a;
    for(int i=0;i<a.size();i++)
    {
        if('A'<= a[i] && a[i] <= 'Z') idx = a[i]-'A';
        else idx=a[i]-'a';
        ++cnt[idx];
        if(mx==cnt[idx]) flag = false;
        else if(mx<cnt[idx])
        {
            flag =true;
            mx = cnt[idx];
            ans = idx;
        }
    }

    if(flag) cout << (char)(ans+'A');
    else cout << '?';
}