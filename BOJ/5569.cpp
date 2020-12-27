#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
int MOD= 100000;
int w,h,dp[200][200][4];

int main()
{
    cin >> w >> h;
    for(int i=1;i<200;i++)
    {
        dp[i][0][0]=1;
        dp[0][i][1]=1;
    }

    for(int i=1;i<h;i++)
    {
        for(int j=1;j<w;j++)
        {
            dp[i][j][0] += (dp[i-1][j][3]+dp[i-1][j][0])%MOD;
            dp[i][j][3] += (dp[i-1][j][1])%MOD;

            dp[i][j][1] += (dp[i][j-1][1]+dp[i][j-1][2])%MOD;
            dp[i][j][2] += (dp[i][j-1][0])%MOD;
        }
    }
    /*
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<h;j++)
        {
            for(int k=0;k<4;k++)
            cout << dp[i][j][k] <<',';
            cout << "  ";
        }
        cout << endl;
    }
    */
   int tot=0;
   for(int i=0;i<4;i++)
   {
        tot+= dp[h-1][w-1][i];
        tot %= MOD;
   }
   cout << tot;
}