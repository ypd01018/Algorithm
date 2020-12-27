#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,l,r;
vector<int> v;
bool binary_search(int mid)
{
    int total = 0, cnt = 1;
    for(int i=0;i<N;i++)
    {
        if(v[i]>mid) return false;
        total += v[i];
        if(total > mid)
        {
            total = v[i];
            cnt++;
        }
    }
    cout << "cnt:" << cnt << endl;
    if(cnt<M) return false;
    else return true;
}
int main()
{
    cin  >> N >> M;
    for(int i=0;i<N;i++)
    {
        int a; cin >> a;
        v.push_back(a);
        r +=a;
    }
    while(l<=r)
    {
        int mid = (l+r)/2;
        int cnt = 0,total = 0;
        cout << mid << endl;
        if(binary_search(mid)) l = mid+1;
        else r = mid-1;
    }
    cout << r;
}
