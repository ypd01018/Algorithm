#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,mat[1002][1002],dp[1002][1002],ny[3]={1,0,1},nx[3]={0,1,1},check[1002][1002];

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> mat[i][j];
            int a,b,c;
            if(i==0) a = 0; else a = dp[i-1][j];
            if(j==0) b = 0; else b = dp[i][j-1];
            if(i==0&&j==0) c = 0; else c = dp[i-1][j-1];
            dp[i][j]=mat[i][j]+max(max(a,b),c); 
        }
    }

    cout << dp[N-1][M-1];


}