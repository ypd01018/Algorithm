#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
set<int> st;
vector<int> v,dis;
int N,K,tot;
int main()
{
    cin >> N >> K;
    for(int i=0;i<N;i++)
    {
        int a; cin >> a;
        if(st.count(a)) continue;
        st.insert(a);
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=1;i<v.size();i++)
    {
        dis.push_back(v[i]-v[i-1]);
        tot += v[i]-v[i-1];
    }
    sort(dis.begin(),dis.end(),greater<int>());
    for(int i=0;i<K-1 && i<dis.size();i++)
    {
        tot -= dis[i];
    }
    cout << tot;
}