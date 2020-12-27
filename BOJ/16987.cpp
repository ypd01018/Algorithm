#include<bits/stdc++.h>
#define hp first
#define w second
using namespace std;
int N,target = 1;
pair<int,int> arr[9];
void egg(int n_egg)
{
    if(n_egg == 9) return;
    
    for(int i = 1;i<N+1;i++)
    {
        if(arr[n_egg].hp>0 && arr[i].hp>0)
        {
            
        }
    }
}
int main()
{
    for(int i=0;i<N;i++)
    {
        int _hp,_w;
        cin >> _hp >> _w;
        arr[i].hp = _hp;
        arr[i].w=_w;
    }

    

}