#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int N,tmp;
pair<ll,bool> dp[103][300];

int main()
{
    cin >> N >> tmp;
    dp[0][tmp].first = dp[0][tmp].second =1;
    for(int i=1;i<N-1;i++)
    {
        cin >>tmp;
            for(int j=0;j<=100;j++)
            {
                if(dp[i-1][j].second)
                {
                    if(j+tmp<=20)
                    {
                        dp[i][j+tmp].first += dp[i-1][j].first ;
                        dp[i][j+tmp].second=1;
                    }
                    if(j-tmp>=0)
                    {
                        dp[i][j-tmp].first += dp[i-1][j].first ;
                        dp[i][j-tmp].second=1;
                    }
                } 
            }
        
    }
    cin >> tmp;
    //cout <<"tmp:" << tmp << endl;
    cout << dp[N-2][tmp].first;
}
