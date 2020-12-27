#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N;
vector<int>v,ans_v;
priority_queue<int> pq_max,pq_min;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++)
    {
        int tmp; cin >> tmp;

        pq_max.push(tmp);

        while(pq_max.size() > pq_min.size())
        {
            pq_min.push((-1)*pq_max.top()); pq_max.pop();
        }
        while(pq_max.size() < pq_min.size())
        {
            pq_max.push((-1)*pq_min.top()); pq_min.pop();
        }
        ans_v.push_back(pq_max.top());
    }

    for(int i : ans_v) cout << i << endl;


}