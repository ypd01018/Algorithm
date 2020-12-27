#include<iostream>
#include<algorithm>

#define endl "\n"
using namespace std;
int N,dp[1010],arr[1010],mx=-1;
int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
    }
    for(int i=0;i<N;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i] && dp[i] < dp[j]+1)
            {
                dp[i]=dp[j]+1;
            }
        }
        mx = max(mx,dp[i]);
    }
    cout << mx;
}