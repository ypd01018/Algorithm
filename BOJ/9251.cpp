#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
string a1,a2;
int dp[1002][1002],find_point[1002];
int main()
{
    cin >> a1 >> a2;
    int check;
    for(int i=0;i<a1.size();i++)
    {
        for(int j=0;i<a2.size();j++)
        {
            if(a1[i]==a2[j]) check = j;
            dp[i][i]=1;
            break;
        }

        for(int j=i+1;j<a1.size();j++)
        {
            if()
        }
    }
}