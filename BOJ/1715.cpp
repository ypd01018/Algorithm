#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N;
priority_queue<int> pq;
int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int a; cin >> a;
        pq.push(-1*a);
    }
    int ans = 0;
    while(!pq.empty())
    {
        int a = -1*pq.top(); pq.pop();
        if(pq.empty()) break;
        int b = -1*pq.top();pq.pop();
        ans += a+b;
        pq.push(-1*(a+b));
    }
    cout << ans;
}