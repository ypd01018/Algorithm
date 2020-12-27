#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int A,B,V;
int up(double a)
{
    if(a==(int)a) return a;
    else return (int)a+1;
}
int main()
{
    cin >> A >> B >> V;
    cout << up((((double)(V-A)/(double)(A-B))+(double)1));
}