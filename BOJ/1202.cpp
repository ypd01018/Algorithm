#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,K,idx;
vector<pair<int,int>> v;
vector<int> bag_v;
priority_queue<pair<int,int>> dia;
priority_queue<int> pq; 
long long ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i=0;i<N;i++)
    {
        int weight, price;
        cin >> weight >> price;
        v.push_back({weight,price});
    }
    for(int i=0;i<K;i++)
    {
        int siz;
        cin >> siz;
        bag_v.push_back(siz);
    }

    sort(v.begin(),v.end());
    sort(bag_v.begin(),bag_v.end());

    for(int i=0;i<K;i++)
    {
        while(idx<N && v[idx].first<=bag_v[i])
        {
            pq.push(v[idx].second);
            idx++;
        }

        if(!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;


}