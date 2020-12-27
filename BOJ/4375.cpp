#include<bits/stdc++.h>
#define endl "\n"
#define ll long long 
using namespace std;

int main()
{
    string input;
    ll num;
    ll ten,cnt;
    while(scanf("%d", &num) != EOF)
    {
        ten=cnt=1;
        while(1)
        {
            if(ten%num==0)
            {
                cout << cnt<<endl;
                break;
            }
            cnt++;
            ten*=10;
            ten++;
            ten %=num;           
        }
    }
}