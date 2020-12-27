#include<iostream>
#define endl "\n"
//#define ll long long
typedef long long ll;
using namespace std;

ll pow(ll a, ll b, ll c);
int main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);
    ll A,B,C;

    cin >> A >> B >> C ;
    cout << pow(A,B,C);
   
}

ll pow(ll a,ll b,ll c)
{
    if(b == 0) return 1;

    ll temp = pow(a,b/2,c);
    temp = temp * temp % c ;


    if(b%2==0) return temp;
    else return temp * a % c;
}