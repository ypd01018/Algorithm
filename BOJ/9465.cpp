#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
<<<<<<< HEAD

int main()
{
    
}
=======
int T,N,arr[2][100010],dp[3][100010];
void print_test()
{
    cout <<"---------------------------------------" <<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    cout <<"---------------------------------------" <<endl;
}
void sol()
{
    memset(arr,0,sizeof(arr));
    memset(dp,0,sizeof(dp));
    cin >> N;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> arr[i][j];
        }
    }
    dp[0][0]=arr[0][0];
    dp[1][0]=arr[1][0];
    dp[3][0]=0;

    for(int i=1;i<N;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(j==0) dp[0][i]= max(dp[1][i-1] + arr[0][i],dp[2][i-1]+arr[0][i]);
            else if(j==1) dp[1][i]= max(dp[0][i-1] + arr[1][i],dp[2][i-1]+arr[1][i]);
            else
            {
                dp[2][i]=max(dp[0][i-1],dp[1][i-1]);
            }
            
        }
    }

    //print_test();
    cout << max(dp[0][N-1],dp[1][N-1]) << endl;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    for(int i=0;i<T;i++)
    {
        sol();
    }
}
>>>>>>> c970bb23ae158ddb0c279d0af13d5172eedb711b
