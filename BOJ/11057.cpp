#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,dp[1010][10];
int main()
{
    cin >> N;
    for(int i=0;i<10;i++) dp[1][i]=1;

    for(int i=2;i<=N;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=j;k<=9;k++)
            {
                dp[i][k] += dp[i-1][j];
                dp[i][k] %= 10007;
            }
        }
    }
    int sum = 0;
    for(int i=0;i<=9;i++) sum += dp[N][i];

    cout << sum % 10007; 
}