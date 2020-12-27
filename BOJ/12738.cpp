#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int a,N;
vector<int> v;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a;
        if(v.empty()||v.back()<a) v.push_back(a);
        else *lower_bound(v.begin(),v.end(),a)=a;
    }
    cout << v.size() <<endl;
    for(int i=0;i<)
}