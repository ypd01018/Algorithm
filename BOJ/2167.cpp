#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,mat[302][302],dp[302][302];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            cin >> mat[i][j];
            dp[i][j]=dp[i-1][j]+dp[i][j-1]+mat[i][j]-dp[i-1][j-1];
        }
    }

    int n; cin >> n;
    for(int i=0;i<n;i++)
    {
        int a,b,c,d; cin >> a >> b >> c >> d;
        cout << dp[c][d]-dp[a-1][d]-dp[c][b-1]+dp[a-1][b-1]<<endl;
    }
}