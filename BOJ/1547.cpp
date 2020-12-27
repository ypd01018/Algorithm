#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int x,y,n,ball = 1,arr[4];
int main()
{
    arr[1]=1;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> x >> y;
        
        int tmp = arr[x];
        arr[x] = arr[y];
        arr[y] = tmp;
    }
    for(int i=1;i<4;i++)
        if(arr[i]) cout << i;
}