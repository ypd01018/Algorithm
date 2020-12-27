#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
int N,arr[1002];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    arr[0]=1; arr[1] = 2;
    for(int i=2;i<N;i++)
    {
        arr[i]=(arr[i-1]+arr[i-2])%10'007;
    }

    cout << arr[N-1];
}