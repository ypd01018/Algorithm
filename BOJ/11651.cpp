#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N;
vector<pair<int,int>> v;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int x,y;
        cin >> x >> y;
        v.push_back({y,x});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++) cout << v[i].second << ' ' << v[i].first << endl;
}