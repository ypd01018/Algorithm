#include<iostream>
#include<algorithm>
#include<vector>
#define endl "\n"
using namespace std;
int N;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    vector<int> v;
    for(int i=0;i<N;i++)
    {
        int a; cin >> a;
        v.push_back(a);
    }
    if(prev_permutation(v.begin(),v.end())) for(int i=0;i<N;i++) cout << v[i] << ' ';
    else cout << -1;
}