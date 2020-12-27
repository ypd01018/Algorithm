#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
long long X,Y,Z,Z_change,mid,ans;
int main()
{
    cin >> X >> Y;
    Z = 100*Y/X;
    
    if(Z>=99) 
    {
        cout << -1;
        exit(0);
    }
    long long left =0,right=1000000000;
    while(left <= right)
    {
        mid = (left+right)/2;
        Z_change = 100*(Y+mid)/(X+mid);
        if(Z>=Z_change)
        {
            left = mid+1;
        }
        else
        {
            right = mid -1;
        }
        cout << "Z_change:" <<Z_change << endl;
    }
    cout << mid + 1;
}