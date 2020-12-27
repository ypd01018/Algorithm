#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N;
vector<pair<int,int>> v;
priority_queue<int> pq;
bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.first<b.first) return true;
    else if(a.first>b.first) return false;
    else
    {
        if(a.second<b.second) return true;
        else return false;
    }
}
int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int a,b; cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {        
        int start = v[i].first, end = v[i].second;
        bool flag = true;
        if(pq.empty() || -1*pq.top()>start) 
        {
            pq.push(-1*end);
            continue;
        } 
        pq.pop();
        pq.push(-1*end);
    }
    cout << pq.size();
}