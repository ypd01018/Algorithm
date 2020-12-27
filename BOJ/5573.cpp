#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int h,w,n,arr[1003][1003],dp[1003][1003];
pair<int,int> ans;
void DFS(int r, int c) 
{
    if (r >= h || c >= w) 
    {
        ans = { r,c };
        return;
    }
    
    if (arr[r][c] == 1) 
    {
        if (dp[r][c] == 1)
            DFS(r, c + 1);
        else
            DFS(r + 1, c);
    }
    else 
    {
        if (dp[r][c] == 1)
            DFS(r+1, c);
        else
            DFS(r, c+1);
    }
}

int main()
{
    cin >> h >> w >> n;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin >> arr[i][j];
        }
    }
    dp[0][0]=n;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if (arr[i][j] == 1) 
            {
                dp[i+1][j] += dp[i][j] / 2;
                dp[i][j+1] += (dp[i][j] % 2 == 0) ? dp[i][j] / 2 : dp[i][j] / 2 + 1;
            }
            else 
            {
                dp[i+1][j] += (dp[i][j] % 2 == 0) ? dp[i][j] / 2 : dp[i][j] / 2 + 1;
                dp[i][j + 1] += dp[i][j] / 2;
            }
        }
    }

    for (int i = 0; i < h; i++) 
    {
        for (int j = 0; j < w; j++) 
        {
            dp[i][j] %= 2;
        }
    }
    DFS(0, 0);
    cout << ++ans.first << " " << ++ans.second << "\n";


}