#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int hour,min;
    cin >> hour >> min;
    min -= 45;
    if(min<0)
    {
        hour--;
        if(hour <0) hour=23;
        min += 60;
    }
    cout << hour << ' '<< min;
}