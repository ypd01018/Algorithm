#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,K;
int fac(int a)
{
    int ret=1,tmp = 0;
    while(tmp!=a)
    {
        tmp++;
        ret *= tmp;
        
    }
    return ret;
}
int main()
{
    cin >> N >> K;
    cout << fac(N) / (fac(K)*fac(N-K));
    

}