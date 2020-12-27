#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,S;
vector<pair<int,int>> v;
int go(int a,int h,int c)
{
    if(a==v.size()) return c;
    int new_c=c;
    if(S<=v[a].second-h) new_c+=v[a].second;
    return max(go(a+1,h,c),go(a+1,v[a].first,new_c)); 
}
int main()
{
    cin >> N >> S;
    for(int i=0;i<N;i++)
    {
        int h,c; cin >> h >> c;
        v.push_back({h,c});
    }
    sort(v.begin(),v.end());

}
