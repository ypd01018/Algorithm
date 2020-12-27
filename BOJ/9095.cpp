#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int T,d[11];

int main()
{
    cin >> T;
    d[0]=1;
    for(int i=1;i<11;i++)
    {
        if(i>0) d[i] += d[i-1];
        if(i>1) d[i] += d[i-2];
        if(i>2) d[i] += d[i-3];
    }
    for(int i=0;i<T;i++)
    {
        int tmp; cin >> tmp;
        cout<< d[tmp] << endl;
    }

}