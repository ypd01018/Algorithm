#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int mid = 100'000;
int coin[104][3];
int N;
int dp[110][300'010];
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


    if(!(coin[0][1]%2)) dp[0][mid]=1;
    for(int i=1;i<=coin[0][1];i++) 
    {
        dp[0][mid+coin[0][0]*i]=1;
        mx = max(mx,mid+coin[0][0]*i);
        dp[0][mid-(coin[0][0]*i)]=1;
        mn=min(mn,mid-coin[0][0]*i);
    }
    for(int i=1;i<N;i++)
    {
        int st=mn, ed=mx;
        for(int j=st;j<=ed;j++)
        {
            if(!dp[i-1][j]) continue;
            if(!(coin[i][1]%2)) dp[i][j]=1;
            for(int k=1;k<=coin[i][1];k++)
            {
               dp[i][j+coin[i][0]*k]=1;
               mx = max(mx,j+(coin[i][0]*k));
               dp[i][j-coin[i][0]*k]=1;
               mn = min(mn,j-(coin[i][0]*k));
            }
        }
    }


    cout <<dp[N-1][mid]<< endl;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    for(int i=0;i<3;i++) sol();
}