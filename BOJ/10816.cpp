#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
map<int,int> s;
int n,m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin >> tmp;
        s[tmp]++;
    }
    cin >> m;
    for(int i=0;i<m;i++)
    {
        int tmp; cin >> tmp;
        cout << s[tmp] << ' ';
    }
}