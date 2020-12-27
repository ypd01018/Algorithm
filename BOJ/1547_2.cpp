#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int x,y,n,ball = 1;
int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> x >> y;

        if( x == ball & y == ball)
        {
            continue;
        }
        else if(x == ball)
        {
            ball = y;
        }
        else if(y == ball)
        {
            ball = x;
        }
    }

    cout << ball;
}