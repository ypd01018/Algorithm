#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,K,arr[11],tot,cnt;
vector<int> v;
void go(int n)
{
    if(n==-1) return;
    while(1)
    {
        if(tot + arr[n] > K) break;
        tot += arr[n];
        cnt++;
        if(tot == K) return;
    }

    go(n-1);    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
    }
    go(N-1);
    cout << cnt;

}