#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
priority_queue<long long> pq;
vector<long long> v;
int n,tmp;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> tmp;
        if(!tmp)
        {
            if(pq.empty()) 
            {
                v.push_back(0);
                continue;
            }
            v.push_back((-1)*pq.top()); pq.pop();
        }
        else
        {
            pq.push((-1)*tmp);
        }
    }
    for(long long i : v) cout << i << endl;
}