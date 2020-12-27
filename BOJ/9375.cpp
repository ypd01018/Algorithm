#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,n;
unordered_map<string,int> um;
int go()
{
    int ret=1;
    um.clear();
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string a,b; cin >> a >> b;
        um[b]++;
    }
    for(auto iter=um.begin();iter!=um.end();iter++)
    {
        ret*=1+iter->second;
    }
    return ret-1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) cout << go()<<endl;   
}