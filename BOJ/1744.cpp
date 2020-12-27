#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,mul=1,plu,minu,tot,arr[100'10],one;
int zero;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        if(arr[i]>1) plu++;
        else if(arr[i]==0) zero++;
        else if(arr[i]==1) one++;
        else minu++;
    }

    sort(arr,arr+n);

    for(int i=0;i<minu;i++)
    {
        if(i+1<minu)
        {
            tot += arr[i]*arr[i+1];
            i++;
        }
        else
        {
            if(zero) continue;
            tot += arr[i];
        }
        
    }
    for(int i=n-1;i>=minu+zero+one;i--)
    {
        if(i-1 < minu+zero+one)
        {
            tot += arr[i];
        }
        else
        {
            tot += arr[i]*arr[i-1];
            i--;
        }
    }
    tot += one;
    cout << tot;
}