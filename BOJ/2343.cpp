#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,l=1,r;
vector<int> v;
bool binary_search(int mid)
{
    int total = 0, cnt = 1;
    for(int i=0;i<N;i++)
    {
        if(v[i]>mid) return false; // 블루레이가 너무 작다 -> 크기를 늘린다
        total += v[i];
        if(total > mid)
        {
            total = v[i];
            cnt++;
        }
    }
    if(cnt<=M) return true; // 블루레이가 너무 크다 -> 크기를 줄인다
    else return false; // 블루레이가 작거나 같다 -> 크기를 늘려본다
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin  >> N >> M;
    for(int i=0;i<N;i++)
    {
        int a; cin >> a;
        v.push_back(a);
        r +=a;
    }
    int ans=0;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(binary_search(mid)) 
        {
            ans = mid;
            r= mid-1;
        }
        else l=mid+1;
    }
    cout << ans;
}