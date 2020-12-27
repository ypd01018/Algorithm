#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int mid = 100'000;
int coin[104][3];
int N;
bool dp[102][50'010];
void sol()
{
    memset(dp,0,sizeof(dp));
    int mx,mn,tot=0;; mn=mx=mid;
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> coin[i][0] >> coin[i][1];
        tot += coin[i][0]*coin[i][1];
    }

    if(tot%2)
    {
        cout << 0 << endl; return;
    }

    dp[0][0]=true;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=tot/2;j++)
        {
            int k; if(coin[i][1]%2) k=1; else k=0;
            for(k;k<=coin[i][1] && j+coin[i][0]*k<=tot/2 ;k++)
            {
                int a;if(i==0) a=0; else a=-1;
                dp[i][j+coin[i][0]*k] |= dp[i+a][j]; 
            }
        }
    }
     cout << dp[N-1][tot/2]<<endl;
    
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    for(int i=0;i<3;i++) sol();
}