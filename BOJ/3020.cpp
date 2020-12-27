#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int N,H;
int arr[500'010];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> H;
    for(int i=0;i<N;i++)
    {   
        int tmp; cin >> tmp;
        if(i%2==0)
        {
            arr[0]++;
            arr[tmp]--;    
        }
        else
        {
            arr[H-tmp]++;
        }
        
    }
    for(int i=1;i<H;i++)
    {
        arr[i] += arr[i-1];
    }
    int mn = 999'999'999,cnt=0;
    for(int i=0;i<H;i++)
    {
        if(arr[i]<mn)
        {
            mn = arr[i];
            cnt=1;
        }
        else if(arr[i]==mn) cnt++;
    }
    cout << mn << " " << cnt;
}