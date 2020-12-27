#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int T,N,arr[1002],dp[1002][1002][2];
int go(int lft,int rght,int turn)
{
    int flag = turn%2; // 1근우 0명우
    int &ret = dp[lft][rght][flag];
    if(ret!=-1) return ret;
    if(lft>=rght)
    {
        if(flag) return ret=arr[lft];
        else return ret=0; 
    }
    if(flag) return ret = max(go(lft+1,rght,turn+1)+arr[lft],go(lft,rght-1,turn+1)+arr[rght]);
    else return ret= min(go(lft+1,rght,turn+1),go(lft,rght-1,turn+1));
}
void sol()
{
    cin >> N;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
    }
    cout << go(0,N-1,1) << endl;

}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> T;
    for(int i=0;i<T;i++) sol();
}