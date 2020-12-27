#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M;
map<string,int> mp;
map<int,string> mp2;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++)
    {
        string a;
        cin >> a;
        mp2[i] = a;
        mp[a]=i;
    }
    for(int i=0;i<M;i++)
    {
        string a;
        cin >> a;
        if('0'<=a[0] && a[0]<='9')
        {
            int b = atoi(a.c_str());
            cout << mp2[b]<<endl;
        }
        else
        {
            cout << mp[a]<<endl;
        }
        
    }
}