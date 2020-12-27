#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,L,arr[5'000'003];
deque<int> dq;
vector<int> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> L;
    for(int i=1;i<=N;i++)
    {
        cin >> arr[i];

        if(dq.empty())
        {
            dq.push_back(arr[i]);
        }      
        else
        {
            while(!dq.empty() && dq.back() > arr[i])
            {
                dq.pop_back();
            }

            dq.push_back(arr[i]);
        }

        if(i>L && dq.front() == arr[i-L]) dq.pop_front();

        v.push_back(dq.front());
    }

    for(int i=0;i<v.size();i++)
    {
        cout << v[i] << " ";
    }

    
}