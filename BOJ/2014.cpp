#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
long long K,N,arr[103];
priority_queue<long long> pq;
map<long long,bool> mp;

int main()
{
    cin >> K >> N;
    long long n=0,mn,mx=-1;
    for(int i=0;i<K;i++)
    {
        cin>>arr[i];
        pq.push((-1)*arr[i]);
        mp[arr[i]]=1;
        mx = max(mx, arr[i]);
    }
    while(!pq.empty())
    {
        mn = (-1)*pq.top(); pq.pop();
        //cout << "mn:"<<mn << endl;
        n++;
        if(n==N) break;
        for(int i=0;i<K;i++)
        {
            if(pq.size()+n>N && mx < arr[i]*mn) continue;

            if(!mp[arr[i]*mn])
            {
                pq.push((-1)*arr[i]*mn);
                mp[arr[i]*mn]=1;
                mx = max(mx, arr[i]*mn);
            }
        }
    }
    cout << mn;

}