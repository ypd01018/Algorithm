#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
int gcd(int a,int b)
{
    cout << a << ' ' << b << endl;
    if(b==0) return a;
    else return gcd(b,a%b);
}
long long solution(int w,int h)
{
	long long answer = (ll)w*(ll)h;
    ll a = (ll)gcd(w,h);
    answer -= (w/(w/a))*((w/a)+(h/a)-1);
	return answer;
}


int main()
{
    long long w,h;
    cin >> w >> h;
    cout << solution(w,h);
}