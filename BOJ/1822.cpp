#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
set<int> s1,s2;
priority_queue<int> pq;
queue<int> q;
int n,m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin >> tmp;
        s1.insert(tmp);
        pq.push(-1*tmp);
    }
    for(int i=0;i<m;i++)
    {
        int tmp; cin >> tmp;
        s2.insert(tmp);
        pq.push(-1*tmp);
    }

    while(!pq.empty())
    {
        int target = -1*pq.top(); pq.pop();
        if(s1.count(target) && !s2.count(target)) q.push(target);
    }
    cout << q.size()<<endl; 
    while(!q.empty())
    {
        cout << q.front() << ' '; q.pop();
    }

}