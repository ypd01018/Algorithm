#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() 
{
	ll n; cin >> n;
	ll pi = n;
	ll prime = 2;
	while (prime * prime <= n) 
    {
		if (n % prime == 0) pi = pi / prime * (prime - 1);
		while (n % prime == 0) n = n / prime;
		prime++;
	}
	if (n!=1) pi=pi/n*(n-1);
	cout << pi;
}