#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,a[1'000'002],b[1'000'002],ans[2'000'004];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++) cin >> a[i];
    for(int i=0;i<M;i++) cin >> b[i];
    int idx_a=0,idx_b=0,idx_ans=0;

    while(idx_a!=N || idx_b!=M)
    {
        int tmp;
        if(idx_a==N)
        {
            tmp = b[idx_b++];
        }
        else if(idx_b==M)
        {
            tmp = a[idx_a++];
        }
        else
        {
            if(a[idx_a] < b[idx_b])
            {
                tmp = a[idx_a++];
            }
            else
            {
                tmp = b[idx_b++];
            }
        }
        ans[idx_ans++]=tmp;
    }
    for(int i=0;i<N+M;i++) cout << ans[i] << ' ';
}