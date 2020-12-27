#include<bits/stdc++.h>

using namespace std;
int n,w,L,arr[1010],bridge[105],current_L = 0,n_truk=0,turn=0,n_exit=0;

int br_next()
{
    int temp[105];
    for(int i = 0 ; i <w ; i++)
    {
        temp[i] = bridge[i];
    }
    bridge[0]=0;
    for(int i=0;i<w;i++)
    {
        bridge[i+1] = temp[i];
    }

    if(bridge[w]) n_exit++;
    return bridge[w];
}
int main()
{
    cin >> n >> w >> L;
    for(int i = 0 ; i < n ; i++)
    {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }

    while(!(n_exit==n))
    {
        turn++;
        current_L -= br_next();
        if(current_L + arr[n_truk] <=L && n_truk <= n)
        {
            current_L += arr[n_truk];
            bridge[0] = arr[n_truk];
            n_truk++;
        }

    }

    cout << turn;


}