#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int arr[102],N,visited[102],mx=-1;
vector<int> v;
priority_queue<int> pq;
void go(int a,int start)
{
    v.push_back(a);
    visited[a]=1;
    if(visited[arr[a]])
    {
        if(start==arr[a])
        {
            for(int i=0;i<v.size();i++) pq.push(-1*v[i]);
        }
        else
        {
            for(int i=0;i<v.size();i++) visited[v[i]]=0;
        }
        
        return;
    }
    go(arr[a],start);
}
int main()
{
    cin >> N;
    for(int i=1;i<=N;i++)cin >> arr[i];
    for(int i=1;i<=N;i++)
    {
        if(visited[i]) continue;
        v.clear();
        go(i,i);
    }
    cout << pq.size()<< endl;
    while(!pq.empty())
    {
        cout << -1*pq.top() << endl; pq.pop();
    }
}