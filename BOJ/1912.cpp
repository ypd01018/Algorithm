#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
long long N, arr[100'003],mx[100'003],mx_value=-0x7f7f7f7f;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i];
    mx[0]=arr[0];
    for(int i=1;i<N;i++)
    {
        mx[i]=max((long long)0,mx[i-1])+arr[i];
        mx_value = max(mx_value,mx[i]);
    }
/*    if(N==1)
    { 
        cout << mx[0];
        return 0;
    }*/
    cout << *max_element(mx,mx+N);
    //cout << mx_value;
}