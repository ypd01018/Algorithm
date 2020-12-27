#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,A[52],B[10002];
bool cmp(int a, int b)
{
    return a>b;
}
bool check(int mid)
{
    int idx = 0;
    for(int i=0;i<M;i+=mid)
    {
        if(idx>=N || A[idx++]<B[i]) return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    cin >> M;
    for(int i=0;i<M;i++) cin >> B[i];
    sort(A,A+N,cmp); sort(B,B+M,cmp);
    if(A[0]<B[0])
    {
        cout << -1;
        return 0;
    }
    int start = 1,end=10000;
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(check(mid)) end = mid-1;
        else start = mid+1;
    }
    cout << start;
}