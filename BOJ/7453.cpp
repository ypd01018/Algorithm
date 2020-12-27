#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
long long cnt,A[4001],B[4001],C[4001],D[4001],AB[4001*4001],CD[4001*4001];
int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            AB[n*i+j]=A[i]+B[j];
            CD[n*i+j]=C[i]+D[j];
        }
    }

    sort(CD,CD+n*n);

    for(int i=0;i<n*n;i++)
    {
        cnt += (upper_bound(CD,CD+n*n,AB[i]*(-1))-CD+1)-(lower_bound(CD,CD+n*n,AB[i]*(-1))-CD+1);
        //cout <<"AB["<<i<<"]:"<< AB[i] << " upper:" << (upper_bound(CD,CD+n*n,AB[i]*(-1))-CD+1) << "  low:"<<(lower_bound(CD,CD+n*n,AB[i]*(-1))-CD+1)<< endl;
    }

    cout << cnt;
}