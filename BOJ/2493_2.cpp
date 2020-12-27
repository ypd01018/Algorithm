#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,arr[500'002];
stack<pair<int,int>> s;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        int a; cin >> a;

        while(!s.empty())
        {
            int val = s.top().second; int idx = s.top().first;
            if(val >= a)
            {
                arr[i]=idx; s.push({i,a});
                break;
            }
            else s.pop();
        }
        if(s.empty())
        {
            arr[i]=0;
            s.push({i,a});
        }
    }

    for(int i=1;i<=N;i++) cout << arr[i] << ' ';
}