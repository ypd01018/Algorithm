#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,mul,divi,plu,minu,arr[13],tmp,mx=INT_MIN,mn=INT_MAX;
void go(int a)
{
    if(a == n)
    {
        mx = max(tmp,mx);
        mn = min(tmp,mn);
        return;
    }

    int origin = tmp;
    if(mul)
    {
        tmp *= arr[a];
        mul--;
        go(a+1);
        tmp = origin;
        mul++;
    }
    if(plu)
    {
        tmp += arr[a];
        plu--;
        go(a+1);
        tmp = origin;
        plu++;
    }
    if(minu)
    {
        tmp -= arr[a];
        minu--;
        go(a+1);
        tmp = origin;
        minu++;
    }
    if(divi)
    {
        int flag=1;
        if((tmp<0 && arr[a]>0) || (tmp>0 && arr[a]<0)) flag = -1; 
        tmp = abs(tmp);
        tmp /= abs(arr[a]);
        tmp *= flag;
        divi--;
        go(a+1);
        tmp = origin;
        divi++;
    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    cin >> plu >> minu >> mul >> divi;

    tmp = arr[0];

    go(1);

    cout << mx << endl << mn;


    

}